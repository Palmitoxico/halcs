/*
 * Copyright (C) 2014 LNLS (www.lnls.br)
 * Author: Lucas Russo <lucas.russo@lnls.br>
 *
 * Released according to the GNU LGPL, version 3 or any later version.
 */

/* This file is based on the work of Andrzej Wojenski for the FCS project,
 * available, to my knowledge, only in https://github.com/lerwys/fcs
 *
 * Description : Software driver for Wishbone SPI_BIDIR_1_0 IP core
 *                 (modification of SPI Master Controller from OpenCores
 *                 with modification to handle bidirectional transfer on
 *                 MOSI line)
 */

#include "sm_io.h"
#include "sm_pr_spi.h"
#include "sm_pr_spi_defaults.h"
#include "wb_spi_regs.h"
#include "rw_param.h"
#include "rw_param_codes.h"
#include "hal_assert.h"

/* Undef ASSERT_ALLOC to avoid conflicting with other ASSERT_ALLOC */
#ifdef ASSERT_TEST
#undef ASSERT_TEST
#endif
#define ASSERT_TEST(test_boolean, err_str, err_goto_label, /* err_core */ ...) \
    ASSERT_HAL_TEST(test_boolean, SM_PR, "[sm_pr:spi]",         \
            err_str, err_goto_label, /* err_core */ __VA_ARGS__)

#ifdef ASSERT_ALLOC
#undef ASSERT_ALLOC
#endif
#define ASSERT_ALLOC(ptr, err_goto_label, /* err_core */ ...)   \
    ASSERT_HAL_ALLOC(ptr, SM_PR, "[sm_pr:spi]",                 \
            smpr_err_str(SMPR_ERR_ALLOC),                       \
            err_goto_label, /* err_core */ __VA_ARGS__)

#ifdef CHECK_ERR
#undef CHECK_ERR
#endif
#define CHECK_ERR(err, err_type)                                \
    CHECK_HAL_ERR(err, SM_PR, "[sm_pr:spi]",                    \
            smpr_err_str (err_type))

static smpr_err_e _spi_init (smpr_t *self);
static ssize_t _spi_read_write_generic (smpr_t *self, uint8_t *data,
        size_t size, spi_mode_e mode, uint32_t flags);

/************ Our methods implementation **********/

/* Creates a new instance of the proto_spi */
smpr_proto_spi_t * smpr_proto_spi_new (uint32_t base)
{
    smpr_proto_spi_t *self = (smpr_proto_spi_t *) zmalloc (sizeof *self);
    ASSERT_ALLOC (self, err_smpr_proto_spi_alloc);

    self->base = base;

    return self;

err_smpr_proto_spi_alloc:
    return NULL;
}

/* Destroy an instance of the proto_spi */
smpr_err_e smpr_proto_spi_destroy (smpr_proto_spi_t **self_p)
{
    assert (self_p);

    if (*self_p) {
        smpr_proto_spi_t *self = *self_p;

        free (self);
        self_p = NULL;
    }

    return SMPR_SUCCESS;
}

/************ smpr_proto_ops_spi Implementation **********/

/* Open SPI protocol */
int spi_open (smpr_t *self, uint32_t base, void *args)
{
    assert (self);

    /* Create new spi */
    smpr_proto_spi_t *spi_proto = smpr_proto_spi_new (base);
    ASSERT_TEST(spi_proto != NULL, "Could not allocate proto_handler",
            err_proto_handler_alloc);

    /* Initialize the SPI protocol with the options passed */
    spi_proto_args_t *spi_proto_args = NULL;
    if (args != NULL) {
        spi_proto_args = (spi_proto_args_t *) args;
        spi_proto->sys_freq = spi_proto_args->sys_freq;
        spi_proto->spi_freq = spi_proto_args->spi_freq;
        spi_proto->init_config = spi_proto_args->init_config;
    }
    else {
        DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO,
                "[sm_pr:spi] SPI arguments not specified. Using default values ...\n");
        spi_proto->sys_freq = SM_PR_SPI_DFLT_SYS_FREQ;
        spi_proto->spi_freq = SM_PR_SPI_DFLT_SPI_FREQ;
        spi_proto->init_config = SM_PR_SPI_DFLT_SPI_CONFIG;
    }

    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO,
            "[sm_pr:spi] Using system clock = %u Hz, spi clock = %u Hz\n"
            "\tconfig register = 0x%08X\n",
            spi_proto->sys_freq, spi_proto->spi_freq, spi_proto->init_config);

    /* Attach specific protocol handler to generic one */
    SMPR_PROTO_SPI(self) = spi_proto;

    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO, "[sm_pr:spi] Initializing SPI protocol\n");
    smpr_err_e err = _spi_init (self);
    ASSERT_TEST(err == SMPR_SUCCESS, "Could not initialize SPI protocol handler",
            err_proto_handler_init);

    return 0;

err_proto_handler_init:
    smpr_proto_spi_destroy (&SMPR_PROTO_SPI(self));
err_proto_handler_alloc:
    return -1;
}

/* Release SPI protocol device */
int spi_release (smpr_t *self)
{
    assert (self);

    /* Deattach specific protocol handler to generic one */
    smpr_err_e err = smpr_proto_spi_destroy (&SMPR_PROTO_SPI(self));
    ASSERT_TEST (err==SMPR_SUCCESS, "Could not close device appropriately", err_dealloc);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO, "[smpr:spi] Closed SPI protocol handler\n");

    return 0;

err_dealloc:
    return -1;
}

/* Read 16-bit data from SPI */
ssize_t spi_read_16 (smpr_t *self, loff_t offs, uint16_t *data, uint32_t flags)
{
    (void) offs;
    /* We want to request a read command from some off-FPGA chip. So, we
     * always use WRITE_READ mode */
    return _spi_read_write_generic (self, (uint8_t *) data, sizeof(*data),
            SPI_MODE_WRITE_READ, flags);
}

/* Write 16-bit data to SPI device */
ssize_t spi_write_16 (smpr_t *self, loff_t offs, const uint16_t *data, uint32_t flags)
{
    (void) offs;
    return _spi_read_write_generic (self, (uint8_t *) data, sizeof(*data),
            SPI_MODE_WRITE, flags);
}

/* Read 32-bit data from SPI */
ssize_t spi_read_32 (smpr_t *self, loff_t offs, uint32_t *data, uint32_t flags)
{
    (void) offs;
    /* We want to request a read command from some off-FPGA chip. So, we
     * always use WRITE_READ mode */
    return _spi_read_write_generic (self, (uint8_t *) data, sizeof(*data),
            SPI_MODE_WRITE_READ, flags);
}

/* Write 32-bit data to SPI device */
ssize_t spi_write_32 (smpr_t *self, loff_t offs, const uint32_t *data, uint32_t flags)
{
    (void) offs;
    return _spi_read_write_generic (self, (uint8_t *) data, sizeof(*data),
            SPI_MODE_WRITE, flags);
}

/* Read 64-bit data from SPI */
ssize_t spi_read_64 (smpr_t *self, loff_t offs, uint64_t *data, uint32_t flags)
{
    (void) offs;
    /* We want to request a read command from some off-FPGA chip. So, we
     * always use WRITE_READ mode */
    return _spi_read_write_generic (self, (uint8_t *) data, sizeof(*data),
            SPI_MODE_WRITE_READ, flags);
}

/* Write 64-bit data to SPI device */
ssize_t spi_write_64 (smpr_t *self, loff_t offs, const uint64_t *data, uint32_t flags)
{
    (void) offs;
    return _spi_read_write_generic (self, (uint8_t *) data, sizeof(*data),
            SPI_MODE_WRITE, flags);
}

/* Read data block from SPI device, size in bytes */
ssize_t spi_read_block (smpr_t *self, loff_t offs, size_t size, uint32_t *data,
        uint32_t flags)
{
    (void) offs;
    /* We want to request a read command from some off-FPGA chip. So, we
     * always use WRITE_READ mode */
    return _spi_read_write_generic (self, (uint8_t *) data, size,
            SPI_MODE_WRITE_READ, flags);
}

/* Write data block from SPI device, size in bytes */
ssize_t spi_write_block (smpr_t *self, loff_t offs, size_t size, const uint32_t *data,
        uint32_t flags)
{
    (void) offs;
    return _spi_read_write_generic (self, (uint8_t *) data, size,
                SPI_MODE_WRITE, flags);
}

/************ Static functions **********/
static smpr_err_e _spi_init (smpr_t *self)
{
    assert (self);

    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO, "[sm_pr:spi] Inside _spi_init\n");
    smpr_err_e err = SMPR_SUCCESS;
    smio_t *parent = SMPR_PARENT(self);
    smpr_proto_spi_t *spi_proto = SMPR_PROTO_SPI(self);

    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO, "[sm_pr:spi] Calculating SPI frequency\n");
    /* Set SPI clock */
    float f_freq = (float) spi_proto->sys_freq/(2.0 * (float) spi_proto->spi_freq) - 1.0;
    uint32_t freq = SPI_PROTO_DIVIDER_W((uint16_t) f_freq);

    /* Configure SPI divider register */
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] SPI divider = %u\n", freq);
    RW_REPLY_TYPE rw_err = SET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO, DIVIDER, /* field = NULL */,
            MULT_BIT_PARAM, /* value */ freq, /* min */, /* max */,
            NO_CHK_FUNC, SET_FIELD);
    ASSERT_TEST(rw_err == RW_OK, "Could not set freq parameter", err_exit,
            SMPR_ERR_RW_SMIO);

#ifdef SM_PR_READBACK
    /* Readback test */
    uint32_t freq_rb;
    smio_thsafe_client_read_32 (parent, spi_proto->base | SPI_PROTO_REG_DIVIDER,
            &freq_rb);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] SPI divider readback value = %u\n", SPI_PROTO_DIVIDER_R(freq_rb));
    ASSERT_TEST(SPI_PROTO_DIVIDER_R(freq_rb) == freq, "[sm_pr:spi] SPI frequency readback failed",
            err_exit, SMPR_ERR_RW_SMIO);
#endif

    /* Configure config register */
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] SPI config register = 0x%08X\n", spi_proto->init_config);
    rw_err = SET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO, CTRL, /* field = NULL */,
            MULT_BIT_PARAM, /* value */ spi_proto->init_config, /* min */, /* max */,
            NO_CHK_FUNC, SET_FIELD);
    ASSERT_TEST(rw_err == RW_OK, "Could not set control parameter", err_exit,
            SMPR_ERR_RW_SMIO);

#ifdef SM_PR_READBACK
    /* Readback test */
    uint32_t config_rb;
    smio_thsafe_client_read_32 (parent, spi_proto->base | SPI_PROTO_REG_CTRL,
            &config_rb);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] SPI config readback value = 0x%08X\n", config_rb);
    ASSERT_TEST(config_rb == spi_proto->init_config, "[sm_pr:spi] SPI initial config readback failed",
            err_exit, SMPR_ERR_RW_SMIO);
#endif

    uint32_t bidir = SM_PR_SPI_DFLT_BIDIR;
    /* Configure BIDIR register */
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] SPI bidir register = 0x%08X\n", bidir);
    rw_err = SET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO, CFG_BIDIR, /* field = NULL */,
            MULT_BIT_PARAM, /* value */ bidir, /* min */, /* max */,
            NO_CHK_FUNC, SET_FIELD);
    ASSERT_TEST(rw_err == RW_OK, "Could not set bidir parameter", err_exit,
            SMPR_ERR_RW_SMIO);

#ifdef SM_PR_READBACK
    /* Readback test */
    uint32_t bidir_rb;
    smio_thsafe_client_read_32 (parent, spi_proto->base | SPI_PROTO_REG_CFG_BIDIR,
            &bidir_rb);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] SPI bidir readback value = 0x%08X\n", bidir_rb);
    ASSERT_TEST(bidir_rb == bidir, "[sm_pr:spi] SPI Bidirectional readback failed",
            err_exit, SMPR_ERR_RW_SMIO);
#endif

err_exit:
    return err;
}

/* Generic read/write to/from SPI */
static ssize_t _spi_read_write_generic (smpr_t *self, uint8_t *data,
        size_t size, spi_mode_e mode, uint32_t flags)
{
    assert (self);

    ssize_t err = 0;
    ssize_t num_bytes = 0;
    RW_REPLY_TYPE rw_err = RW_OK;
    ASSERT_TEST(size > 0 && size*SMPR_BYTE_2_BIT /* bits */ <
            SPI_PROTO_CTRL_CHAR_LEN_MASK+1+1, "Invalid size for spi transfer",
            err_inv_size, -1);

    smio_t *parent = SMPR_PARENT(self);
    smpr_proto_spi_t *spi_proto = SMPR_PROTO_SPI(self);

    uint32_t config;
    rw_err = GET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO,
            CTRL, /* field = NULL */, MULT_BIT_PARAM, config, NO_FMT_FUNC);
    ASSERT_TEST(rw_err == RW_OK, "Could not get CONFIG parameter", err_exit, -1);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] _spi_rw_generic: Config register = 0x%08X\n", config);

    /* Decode flags */
    uint32_t ss = SMPR_PROTO_SPI_SS_FLAGS_R(flags);
    uint32_t charlen = SMPR_PROTO_SPI_CHARLEN_FLAGS_R(flags);

    /* Configure SS line */
    rw_err = SET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO, SS, /* field = NULL */,
            MULT_BIT_PARAM, /* value */ ss, /* min */, /* max */,
            NO_CHK_FUNC, SET_FIELD);
    ASSERT_TEST(rw_err == RW_OK, "Could not set SS parameter", err_exit, -1);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] _spi_rw_generic: SS register = 0x%08X\n", ss);

    /* Configure character length. For the opencores SPI,
     * 0 is 128-bit data word, 1 is 1 bit, 2 is 2-bit and so on */
    if (charlen == SPI_PROTO_REG_RXTX_NUM * SMPR_WB_REG_2_BIT) {
        charlen = 0;
    }

    rw_err = SET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO, CTRL, CHAR_LEN,
            MULT_BIT_PARAM, /* value */ charlen, /* min */ , /* max */,
            NO_CHK_FUNC, SET_FIELD);
    ASSERT_TEST(rw_err == RW_OK, "Could not set CHAR_LEN parameter", err_exit, -1);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] _spi_rw_generic: Charecter Length = 0x%08X\n",
            charlen);

    /* Write data to TX regs */
    if (mode == SPI_MODE_WRITE || mode == SPI_MODE_WRITE_READ) {
        /* Copy data to temp */
        uint8_t data_write[SPI_PROTO_REG_RXTX_NUM * SMPR_WB_REG_2_BYTE] = {0};
        memcpy (data_write, data, size);

        uint32_t i;
        /* We write 32-bit at a time */

        for (i = 0; i < size/SMPR_WB_REG_2_BYTE; ++i) {
            /* As the TXs are just a single register, we write using the SMIO
             * functions directly */
            DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
                    "[sm_pr:spi] _spi_rw_generic: Writing 0x%08X to TX%u\n",
                    *((uint32_t *) (data_write + SMPR_WB_REG_2_BYTE*i)), i);
            num_bytes = smio_thsafe_client_write_32 (parent,
                    (spi_proto->base | SPI_PROTO_REG_TX0) + i*SMPR_WB_REG_2_BYTE,
                    (uint32_t *) (data_write + SMPR_WB_REG_2_BYTE*i));
            err += (num_bytes == -1) ? 0 : num_bytes;
            ASSERT_TEST(num_bytes != -1, "Could not set TX register", err_exit);
        }

        /* Return error if we could not write everything */
        ASSERT_TEST(err == (ssize_t) size, "Could not write everything to TX registers",
                err_exit, -1);
    }

    /* Start transfer */
    rw_err = SET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO, CTRL, GO_BSY,
            SINGLE_BIT_PARAM, /* value */ 1, /* min */, /* max */,
            NO_CHK_FUNC, SET_FIELD);
    ASSERT_TEST(rw_err == RW_OK, "Could not set parameter", err_exit, -1);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] _spi_rw_generic: Transfer started\n");

    /* Check for completion */
    uint32_t busy = 0;
    uint32_t tries = 0;
    while (1) {
        rw_err = GET_PARAM(parent, sm_pr_spi, spi_proto->base, SPI_PROTO,
                CTRL, BSY, SINGLE_BIT_PARAM, busy, NO_FMT_FUNC);
        ASSERT_TEST(rw_err == RW_OK, "Could not get BUSY parameter", err_exit, -1);

        if (!busy) {
            break;
        }

        usleep (SM_PR_SPI_USLEEP);
        ++tries;
        ASSERT_TEST(tries < SM_PR_SPI_MAX_TRIES, "Transfer timeout", err_exit, -1);
    }

    DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
            "[sm_pr:spi] _spi_rw_generic: Wait completed successfully\n");

    /* Reset byte counter */
    err = 0;

    /* Read data from RX regsiters */
    uint32_t i;
    uint8_t data_read[SPI_PROTO_REG_RXTX_NUM * SMPR_WB_REG_2_BYTE] = {0};
    /* We read 32-bit at a time */
    for (i = 0; i < size/SMPR_WB_REG_2_BYTE; ++i) {
        DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
                "[sm_pr:spi] _spi_rw_generic: Reading from RX%u\n", i);
        /* As the RXs are just a single register, we write using the SMIO
         * functions directly */
        num_bytes = smio_thsafe_client_read_32 (parent,
                (spi_proto->base | SPI_PROTO_REG_RX0_SINGLE) + SMPR_WB_REG_2_BYTE*i,
                (uint32_t *)(data_read + SMPR_WB_REG_2_BYTE*i));
        DBE_DEBUG (DBG_SM_PR | DBG_LVL_TRACE,
                "[sm_pr:spi] _spi_rw_generic: Read 0x%08X from RX%u\n",
                *((uint32_t *) (data_read + SMPR_WB_REG_2_BYTE*i)), i);
        err += (num_bytes == -1) ? 0 : num_bytes;
        /* Return the number of bytes effectively read */
        ASSERT_TEST(num_bytes != -1, "Could not set RX regsiter", err_exit);
    }

    /* TODO: Reduce the ammount of memcpy () throughout this simple code*/
    memcpy (data, data_read, size);

err_exit:
err_inv_size:
    return err;
}

const smpr_proto_ops_t smpr_proto_ops_spi = {
    .proto_open           = spi_open,           /* Open device */
    .proto_release        = spi_release,        /* Release device */
    .proto_read_16        = spi_read_16,        /* Read 16-bit data */
    .proto_read_32        = spi_read_32,        /* Read 32-bit data */
    .proto_read_64        = spi_read_64,        /* Read 64-bit data */
    .proto_write_16       = spi_write_16,       /* Write 16-bit data */
    .proto_write_32       = spi_write_32,       /* Write 32-bit data */
    .proto_write_64       = spi_write_64,       /* Write 64-bit data */
    .proto_read_block     = spi_read_block,     /* Read arbitrary block size data,
                                                    parameter size in bytes */
    .proto_write_block    = spi_write_block,    /* Write arbitrary block size data,
                                                    parameter size in bytes */
    .proto_read_dma       = NULL,               /* Read arbitrary block size data via DMA,
                                                    parameter size in bytes */
    .proto_write_dma      = NULL                /* Write arbitrary block size data via DMA,
                                                    parameter size in bytes */
};
