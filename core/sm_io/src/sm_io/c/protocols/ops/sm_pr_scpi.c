/****************************************************************************
 * core/sm_io/src/sm_io/c/protocols/ops/sm_pr_scpi.c
 *
 *   Copyright (C) 2014 LNLS (www.lnls.br). All rights reserved.
 *   Copyright (C) 2019 Augusto Fraga Giachero. All rights reserved.
 *   Author: Augusto Fraga Giachero <afg@augustofg.net>
 *
 * This file is part of HALCS.
 *
 * HALCS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HALCS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HALCS. If not, see <https://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

#include "halcs_server.h"

/* Undef ASSERT_ALLOC to avoid conflicting with other ASSERT_ALLOC */
#ifdef ASSERT_TEST
#undef ASSERT_TEST
#endif
#define ASSERT_TEST(test_boolean, err_str, err_goto_label, /* err_core */ ...) \
    ASSERT_HAL_TEST(test_boolean, SM_PR, "[sm_pr:scpi]",            \
            err_str, err_goto_label, /* err_core */ __VA_ARGS__)

#ifdef ASSERT_ALLOC
#undef ASSERT_ALLOC
#endif
#define ASSERT_ALLOC(ptr, err_goto_label, /* err_core */ ...)       \
    ASSERT_HAL_ALLOC(ptr, SM_PR, "[sm_pr:scpi]",                    \
            smpr_err_str(SMPR_ERR_ALLOC),                           \
            err_goto_label, /* err_core */ __VA_ARGS__)

#ifdef CHECK_ERR
#undef CHECK_ERR
#endif
#define CHECK_ERR(err, err_type)                                    \
    CHECK_HAL_ERR(err, SM_PR, "[sm_pr:scpi]",                       \
            smpr_err_str (err_type))

#define SMPR_PROTO_SCPI_CLIENT(smpr_handler)         (smpr_handler->client)

/* SCPI glue structure. Needed to overcome the need of global variables */
typedef struct {
    smio_t *parent;
} smpr_proto_glue_scpi_t;

/* SCPI glue structure */
smpr_proto_glue_scpi_t scpi_glue;

/* Device endpoint */
typedef struct {
    uint64_t base;                                      /* Core base address */
    struct scpi_func_info_list *funcs_list;             /* SCPI function handler */
    struct scpi_var_info_list *vars_list;               /* SCPI variables handler */
    struct scpi_curve_info_list *curves_list;           /* SCPI curves handler */
    /* Unused */
    struct scpi_group_list *groups_list;                /* SCPI groups handler */
} smpr_proto_scpi_t;

/* Protocol object specification */
struct _smpr_scpi_t {
    /* Must be located first */
    smpr_proto_ops_t proto_ops;       /* SCPI protocol operations */
};

//static smpr_err_e _smpr_proto_scpi_get_handlers (smpr_t *self);

/*************** Our methods implementation **********/

/* Creates a new instance of the proto_scpi */
static smpr_proto_scpi_t * smpr_proto_scpi_new (uint64_t base)
{
    smpr_proto_scpi_t *self = (smpr_proto_scpi_t *) zmalloc (sizeof *self);
    ASSERT_ALLOC (self, err_smpr_proto_scpi_alloc);

    self->base = base;

    return self;

//err_smpr_proto_client_alloc:
    free (self);
err_smpr_proto_scpi_alloc:
    return NULL;
}

/* Destroy an instance of the proto_scpi */
static smpr_err_e smpr_proto_scpi_destroy (smpr_proto_scpi_t **self_p)
{
    assert (self_p);

    if (*self_p) {
        smpr_proto_scpi_t *self = *self_p;

        free (self);
        self_p = NULL;
    }

    return SMPR_SUCCESS;
}

/************ smpr_proto_ops_scpi Implementation **********/

/* Open SCPI protocol */
static int scpi_open (smpr_t *self, uint64_t base, void *args)
{
    UNUSED(args);
    UNUSED(base);
    assert (self);

    /* Create new scpi */
    smpr_proto_scpi_t *scpi_proto = smpr_proto_scpi_new (base);
    ASSERT_TEST(scpi_proto != NULL, "Could not allocate proto_handler",
            err_proto_handler_alloc);

    /* We need to initialize the SCPI protocol here, as we don't have access to
     * to parent pointer inside the smpr_proto_scpi_new () */
    smio_t *parent = smpr_get_parent (self);
    /* Initialize global glue SCPI variable for usage with the send and recv
     * functions */
    scpi_glue.parent = parent;

    /* Attach specific protocol handler to generic one */
    smpr_err_e err = smpr_set_handler (self, scpi_proto);
    ASSERT_TEST(err == SMPR_SUCCESS, "Could not set protocol handler",
            err_proto_handler_set);

    /* Finish initializing SCPI protocol here */
    /* enum scpi_err berr = scpi_client_init (scpi_proto->client, _smpr_proto_scpi_send, */
    /*         _smpr_proto_scpi_recv); */
    /* if (berr != SCPI_SUCCESS) { */
    /*     DBE_DEBUG (DBG_SM_PR | DBG_LVL_ERR, "[sm_pr:scpi] Could not initialize " */
    /*             "SCPI protocol handler: %s\n", scpi_error_str (berr)); */
    /*         goto err_proto_handler_init; */
    /* } */

    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO, "[sm_pr:scpi] Created SCPI client "
            "instance\n");

    return 0;

//err_scpi_handler_init:
    /* There is no scpi_destroy, as it has nothing allocated dynamically */
//err_proto_handler_init:
//    smpr_unset_handler (self);
err_proto_handler_set:
    smpr_proto_scpi_destroy (&scpi_proto);
err_proto_handler_alloc:
    return -1;
}

/* Release SCPI protocol device */
static int scpi_release (smpr_t *self)
{
    assert (self);

    /* Deattach specific protocol handler to generic one */
    smpr_proto_scpi_t *scpi_proto = (smpr_proto_scpi_t *) smpr_unset_handler (self);
    ASSERT_TEST (scpi_proto != NULL, "Could not unset protocol handler",
            err_proto_handler_unset);

    /* Destroy SCPI client instance. Ne need to call any destroy function,
     * as the SCPI library does not dynamically allocates anything */

    /* Null the parent SMIO pointer */
    scpi_glue.parent = NULL;

    /* Deattach specific protocol handler to generic one */
    smpr_err_e err = smpr_proto_scpi_destroy (&scpi_proto);
    ASSERT_TEST (err==SMPR_SUCCESS, "Could not close device appropriately", err_dealloc);
    DBE_DEBUG (DBG_SM_PR | DBG_LVL_INFO, "[sm_pr:scpi] Closed SCPI protocol handler\n");

    return 0;

err_dealloc:
err_proto_handler_unset:
    return -1;
}

/*************************** Static functions *********************************/
/* /\* SCPI function I/O *\/ */
/* static int _smpr_proto_scpi_send (uint8_t *data, uint32_t *count) */
/* { */
/*     int err = 0; */

/*     DBE_DEBUG (DBG_LL_IO | DBG_LVL_TRACE, "[sm_pr:scpi] Sending %u bytes\n", *count); */
/*     ssize_t ret = smio_thsafe_client_write_block (scpi_glue.parent, 0, *count, */
/*             (uint32_t *) data); */
/*     DBE_DEBUG (DBG_LL_IO | DBG_LVL_TRACE, "[sm_pr:scpi] Sent %u bytes\n", *count); */

/*     if (ret < 0) { */
/*         *count = 0; */
/*         err = -1; */
/*         goto err_packet_send; */
/*     } */

/*     /\* Update count with the number of bytes received *\/ */
/*     *count = ret; */

/* err_packet_send: */
/*     return err; */
/* } */

/* static int _smpr_proto_scpi_recv (uint8_t *data, uint32_t *count) */
/* { */
/*     uint32_t len = SCPI_HEADER_SIZE; */
/*     int err = 0; */

/*     /\* First we must received the packet header *\/ */
/*     DBE_DEBUG (DBG_LL_IO | DBG_LVL_TRACE, "[sm_pr:scpi] Receiving %u bytes\n", len); */
/*     ssize_t ret = smio_thsafe_client_read_block (scpi_glue.parent, 0, len, */
/*             (uint32_t *) data); */
/*     DBE_DEBUG (DBG_LL_IO | DBG_LVL_TRACE, "[sm_pr:scpi] Received %zd bytes\n", ret); */

/*     if (ret < 0) { */
/*         *count = 0; */
/*         err = -1; */
/*         goto err_packet_header; */
/*     } */

/*     *count = ret; */

/*     /\* Now, we parse the protocol header and determine how many bytes */
/*      * we have left to read. Very protocol dependent. See SCPI documentation. */
/*      * and example located in */
/*      * https://github.com/lerwys/libscpi/blob/master/examples/client/puc_serial/main.c */
/*      * FIXME *\/ */
/*     len = (data [1] << 8) + data [2]; */

/*     DBE_DEBUG (DBG_LL_IO | DBG_LVL_TRACE, "[sm_pr:scpi] Receiving another %u " */
/*             "bytes\n", len); */
/*     ret = smio_thsafe_client_read_block (scpi_glue.parent, 0, len, */
/*             (uint32_t *)(data + *count)); */
/*     DBE_DEBUG (DBG_LL_IO | DBG_LVL_TRACE, "[sm_pr:scpi] Received another %zd " */
/*             "bytes\n", ret); */

/*     if (ret < 0) { */
/*         *count = 0; */
/*         err = -1; */
/*         goto err_packet_payload; */
/*     } */

/*     *count += ret; */

/* err_packet_payload: */
/* err_packet_header: */
/*     return err; */
/* } */

static const smpr_proto_ops_t smpr_proto_ops_scpi = {
    .proto_name           = "SCPI",             /* Protocol name */
    .proto_open           = scpi_open,          /* Open device */
    .proto_release        = scpi_release,       /* Release device */
    .proto_read_16        = NULL,               /* Read 16-bit data */
    .proto_read_32        = NULL,               /* Read 32-bit data */
    .proto_read_64        = NULL,               /* Read 64-bit data */
    .proto_write_16       = NULL,               /* Write 16-bit data */
    .proto_write_32       = NULL,               /* Write 32-bit data */
    .proto_write_64       = NULL,               /* Write 64-bit data */
    .proto_read_block     = NULL,               /* Read arbitrary block size data,
                                                    parameter size in bytes */
    .proto_write_block    = NULL,               /* Write arbitrary block size data,
                                                    parameter size in bytes */
    .proto_read_dma       = NULL,               /* Read arbitrary block size data via DMA,
                                                    parameter size in bytes */
    .proto_write_dma      = NULL                /* Write arbitrary block size data via DMA,
                                                    parameter size in bytes */
};

/************ Our methods implementation **********/

/* Creates a new instance of the proto_scpi */
smpr_scpi_t *smpr_scpi_new ()
{
    smpr_scpi_t *self = (smpr_scpi_t *) zmalloc (sizeof *self);
    ASSERT_ALLOC (self, err_smpr_scpi_alloc);

    /* copy SCPI operations */
    self->proto_ops = smpr_proto_ops_scpi;

    return self;

err_smpr_scpi_alloc:
    return NULL;
}

/* Destroy an instance of the scpi */
smpr_err_e smpr_scpi_destroy (smpr_scpi_t **self_p)
{
    assert (self_p);

    if (*self_p) {
        smpr_scpi_t *self = *self_p;

        free (self);
        self_p = NULL;
    }

    return SMPR_SUCCESS;
}

const smpr_proto_ops_t *smpr_scpi_get_ops (smpr_scpi_t *self)
{
    assert (self);
    return &self->proto_ops;
}
