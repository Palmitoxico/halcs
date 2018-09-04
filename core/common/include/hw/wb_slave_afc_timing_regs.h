/*
  Register definitions for slave core: AFC Timing Sirius

  * File           : wb_slave_afc_timing_regs.h
  * Author         : auto-generated by wbgen2 from wb_slave_afc_timing_sirius.wb
  * Created        : Tue Sep  4 10:28:53 2018
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE wb_slave_afc_timing_sirius.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_WB_SLAVE_AFC_TIMING_SIRIUS_WB
#define __WBGEN2_REGDEFS_WB_SLAVE_AFC_TIMING_SIRIUS_WB

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <inttypes.h>
#endif

#if defined( __GNUC__)
#define PACKED __attribute__ ((packed))
#else
#error "Unsupported compiler?"
#endif

#ifndef __WBGEN2_MACROS_DEFINED__
#define __WBGEN2_MACROS_DEFINED__
#define WBGEN2_GEN_MASK(offset, size) (((1<<(size))-1) << (offset))
#define WBGEN2_GEN_WRITE(value, offset, size) (((value) & ((1<<(size))-1)) << (offset))
#define WBGEN2_GEN_READ(reg, offset, size) (((reg) >> (offset)) & ((1<<(size))-1))
#define WBGEN2_SIGN_EXTEND(value, bits) (((value) & (1<<bits) ? ~((1<<(bits))-1): 0 ) | (value))
#endif


/* definitions for register: Status */

/* definitions for field: Fiber link in reg: Status */
#define TIMING_STAT_LINK                      WBGEN2_GEN_MASK(0, 1)

/* definitions for field: RX enable in reg: Status */
#define TIMING_STAT_RXEN                      WBGEN2_GEN_MASK(1, 1)

/* definitions for field: Ref clk locked in reg: Status */
#define TIMING_STAT_REFCLKLOCK                WBGEN2_GEN_MASK(2, 1)

/* definitions for field: evren in reg: Status */
#define TIMING_STAT_EVREN                     WBGEN2_GEN_MASK(3, 1)

/* definitions for register: alive */

/* definitions for register: freq_sample_rate_prescale */

/* definitions for register: RTM Si57x RFREQ[37-20] */

/* definitions for register: RTM Si57x RFREQ[19-0] */

/* definitions for register: RTM Si57x N1 & DIV */

/* definitions for field: RTM Si57x N1 in reg: RTM Si57x N1 & DIV */
#define TIMING_RTM_N1_MASK                    WBGEN2_GEN_MASK(0, 7)
#define TIMING_RTM_N1_SHIFT                   0
#define TIMING_RTM_N1_W(value)                WBGEN2_GEN_WRITE(value, 0, 7)
#define TIMING_RTM_N1_R(reg)                  WBGEN2_GEN_READ(reg, 0, 7)

/* definitions for field: RTM Si57x HS_DIV in reg: RTM Si57x N1 & DIV */
#define TIMING_RTM_HS_DIV_MASK                WBGEN2_GEN_MASK(7, 3)
#define TIMING_RTM_HS_DIV_SHIFT               7
#define TIMING_RTM_HS_DIV_W(value)            WBGEN2_GEN_WRITE(value, 7, 3)
#define TIMING_RTM_HS_DIV_R(reg)              WBGEN2_GEN_READ(reg, 7, 3)

/* definitions for register: RTM Freq loop */

/* definitions for field: Proportional gain frequency in reg: RTM Freq loop */
#define TIMING_RTM_FREQ_KP_MASK               WBGEN2_GEN_MASK(0, 16)
#define TIMING_RTM_FREQ_KP_SHIFT              0
#define TIMING_RTM_FREQ_KP_W(value)           WBGEN2_GEN_WRITE(value, 0, 16)
#define TIMING_RTM_FREQ_KP_R(reg)             WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for field: Integral gain frequency in reg: RTM Freq loop */
#define TIMING_RTM_FREQ_KI_MASK               WBGEN2_GEN_MASK(16, 16)
#define TIMING_RTM_FREQ_KI_SHIFT              16
#define TIMING_RTM_FREQ_KI_W(value)           WBGEN2_GEN_WRITE(value, 16, 16)
#define TIMING_RTM_FREQ_KI_R(reg)             WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: RTM Phase loop */

/* definitions for field: Proportional gain phase in reg: RTM Phase loop */
#define TIMING_RTM_PHASE_KP_MASK              WBGEN2_GEN_MASK(0, 16)
#define TIMING_RTM_PHASE_KP_SHIFT             0
#define TIMING_RTM_PHASE_KP_W(value)          WBGEN2_GEN_WRITE(value, 0, 16)
#define TIMING_RTM_PHASE_KP_R(reg)            WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for field: Integral gain phase in reg: RTM Phase loop */
#define TIMING_RTM_PHASE_KI_MASK              WBGEN2_GEN_MASK(16, 16)
#define TIMING_RTM_PHASE_KI_SHIFT             16
#define TIMING_RTM_PHASE_KI_W(value)          WBGEN2_GEN_WRITE(value, 16, 16)
#define TIMING_RTM_PHASE_KI_R(reg)            WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: RTM phase setpoint */

/* definitions for register: RTM DDMTD config */

/* definitions for field: DDMTD average number in reg: RTM DDMTD config */
#define TIMING_RTM_MAF_NAVG_MASK              WBGEN2_GEN_MASK(0, 12)
#define TIMING_RTM_MAF_NAVG_SHIFT             0
#define TIMING_RTM_MAF_NAVG_W(value)          WBGEN2_GEN_WRITE(value, 0, 12)
#define TIMING_RTM_MAF_NAVG_R(reg)            WBGEN2_GEN_READ(reg, 0, 12)

/* definitions for field: DDMTD divider exponent in reg: RTM DDMTD config */
#define TIMING_RTM_MAF_DIV_EXP_MASK           WBGEN2_GEN_MASK(12, 5)
#define TIMING_RTM_MAF_DIV_EXP_SHIFT          12
#define TIMING_RTM_MAF_DIV_EXP_W(value)       WBGEN2_GEN_WRITE(value, 12, 5)
#define TIMING_RTM_MAF_DIV_EXP_R(reg)         WBGEN2_GEN_READ(reg, 12, 5)

/* definitions for register: AFC Si57x RFREQ[37-20] */

/* definitions for register: AFC Si57x RFREQ[19-0] */

/* definitions for register: AFC Si57x N1 & div */

/* definitions for field: AFC Si57x N1 in reg: AFC Si57x N1 & div */
#define TIMING_AFC_N1_MASK                    WBGEN2_GEN_MASK(0, 7)
#define TIMING_AFC_N1_SHIFT                   0
#define TIMING_AFC_N1_W(value)                WBGEN2_GEN_WRITE(value, 0, 7)
#define TIMING_AFC_N1_R(reg)                  WBGEN2_GEN_READ(reg, 0, 7)

/* definitions for field: AFC Si57x HS_DIV in reg: AFC Si57x N1 & div */
#define TIMING_AFC_HS_DIV_MASK                WBGEN2_GEN_MASK(7, 3)
#define TIMING_AFC_HS_DIV_SHIFT               7
#define TIMING_AFC_HS_DIV_W(value)            WBGEN2_GEN_WRITE(value, 7, 3)
#define TIMING_AFC_HS_DIV_R(reg)              WBGEN2_GEN_READ(reg, 7, 3)

/* definitions for register: AFC Freq loop */

/* definitions for field: Proportional gain frequency in reg: AFC Freq loop */
#define TIMING_AFC_FREQ_KP_MASK               WBGEN2_GEN_MASK(0, 16)
#define TIMING_AFC_FREQ_KP_SHIFT              0
#define TIMING_AFC_FREQ_KP_W(value)           WBGEN2_GEN_WRITE(value, 0, 16)
#define TIMING_AFC_FREQ_KP_R(reg)             WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for field: Integral gain frequency in reg: AFC Freq loop */
#define TIMING_AFC_FREQ_KI_MASK               WBGEN2_GEN_MASK(16, 16)
#define TIMING_AFC_FREQ_KI_SHIFT              16
#define TIMING_AFC_FREQ_KI_W(value)           WBGEN2_GEN_WRITE(value, 16, 16)
#define TIMING_AFC_FREQ_KI_R(reg)             WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: AFC Phase loop */

/* definitions for field: Proportional gain phase in reg: AFC Phase loop */
#define TIMING_AFC_PHASE_KP_MASK              WBGEN2_GEN_MASK(0, 16)
#define TIMING_AFC_PHASE_KP_SHIFT             0
#define TIMING_AFC_PHASE_KP_W(value)          WBGEN2_GEN_WRITE(value, 0, 16)
#define TIMING_AFC_PHASE_KP_R(reg)            WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for field: Integral gain phase in reg: AFC Phase loop */
#define TIMING_AFC_PHASE_KI_MASK              WBGEN2_GEN_MASK(16, 16)
#define TIMING_AFC_PHASE_KI_SHIFT             16
#define TIMING_AFC_PHASE_KI_W(value)          WBGEN2_GEN_WRITE(value, 16, 16)
#define TIMING_AFC_PHASE_KI_R(reg)            WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: AFC phase setpoint */

/* definitions for register: AFC DDMTD config */

/* definitions for field: DDMTD average number in reg: AFC DDMTD config */
#define TIMING_AFC_MAF_NAVG_MASK              WBGEN2_GEN_MASK(0, 12)
#define TIMING_AFC_MAF_NAVG_SHIFT             0
#define TIMING_AFC_MAF_NAVG_W(value)          WBGEN2_GEN_WRITE(value, 0, 12)
#define TIMING_AFC_MAF_NAVG_R(reg)            WBGEN2_GEN_READ(reg, 0, 12)

/* definitions for field: DDMTD divider exponent in reg: AFC DDMTD config */
#define TIMING_AFC_MAF_DIV_EXP_MASK           WBGEN2_GEN_MASK(12, 5)
#define TIMING_AFC_MAF_DIV_EXP_SHIFT          12
#define TIMING_AFC_MAF_DIV_EXP_W(value)       WBGEN2_GEN_WRITE(value, 12, 5)
#define TIMING_AFC_MAF_DIV_EXP_R(reg)         WBGEN2_GEN_READ(reg, 12, 5)

/* definitions for register: AMC 0 */

/* definitions for field: enable in reg: AMC 0 */
#define TIMING_AMC0_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 0 */
#define TIMING_AMC0_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 0 */
#define TIMING_AMC0_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 0 */
#define TIMING_AMC0_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 0 */
#define TIMING_AMC0_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC0_SRC_SHIFT                 4
#define TIMING_AMC0_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC0_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 0 */
#define TIMING_AMC0_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 0 */

/* definitions for register: AMC event 0 */

/* definitions for register: AMC delay 0 */

/* definitions for register: AMC width 0 */

/* definitions for register: AMC 1 */

/* definitions for field: enable in reg: AMC 1 */
#define TIMING_AMC1_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 1 */
#define TIMING_AMC1_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 1 */
#define TIMING_AMC1_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 1 */
#define TIMING_AMC1_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 1 */
#define TIMING_AMC1_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC1_SRC_SHIFT                 4
#define TIMING_AMC1_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC1_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 1 */
#define TIMING_AMC1_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 1 */

/* definitions for register: AMC event 1 */

/* definitions for register: AMC delay 1 */

/* definitions for register: AMC width 1 */

/* definitions for register: AMC 2 */

/* definitions for field: enable in reg: AMC 2 */
#define TIMING_AMC2_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 2 */
#define TIMING_AMC2_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 2 */
#define TIMING_AMC2_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 2 */
#define TIMING_AMC2_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 2 */
#define TIMING_AMC2_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC2_SRC_SHIFT                 4
#define TIMING_AMC2_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC2_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 2 */
#define TIMING_AMC2_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 2 */

/* definitions for register: AMC event 2 */

/* definitions for register: AMC delay 2 */

/* definitions for register: AMC width 2 */

/* definitions for register: AMC 3 */

/* definitions for field: enable in reg: AMC 3 */
#define TIMING_AMC3_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 3 */
#define TIMING_AMC3_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 3 */
#define TIMING_AMC3_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 3 */
#define TIMING_AMC3_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 3 */
#define TIMING_AMC3_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC3_SRC_SHIFT                 4
#define TIMING_AMC3_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC3_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 3 */
#define TIMING_AMC3_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 3 */

/* definitions for register: AMC event 3 */

/* definitions for register: AMC delay 3 */

/* definitions for register: AMC width 3 */

/* definitions for register: AMC 4 */

/* definitions for field: enable in reg: AMC 4 */
#define TIMING_AMC4_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 4 */
#define TIMING_AMC4_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 4 */
#define TIMING_AMC4_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 4 */
#define TIMING_AMC4_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 4 */
#define TIMING_AMC4_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC4_SRC_SHIFT                 4
#define TIMING_AMC4_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC4_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 4 */
#define TIMING_AMC4_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 4 */

/* definitions for register: AMC event 4 */

/* definitions for register: AMC delay 4 */

/* definitions for register: AMC width 4 */

/* definitions for register: AMC 5 */

/* definitions for field: enable in reg: AMC 5 */
#define TIMING_AMC5_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 5 */
#define TIMING_AMC5_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 5 */
#define TIMING_AMC5_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 5 */
#define TIMING_AMC5_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 5 */
#define TIMING_AMC5_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC5_SRC_SHIFT                 4
#define TIMING_AMC5_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC5_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 5 */
#define TIMING_AMC5_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 5 */

/* definitions for register: AMC event 5 */

/* definitions for register: AMC delay 5 */

/* definitions for register: AMC width 5 */

/* definitions for register: AMC 6 */

/* definitions for field: enable in reg: AMC 6 */
#define TIMING_AMC6_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 6 */
#define TIMING_AMC6_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 6 */
#define TIMING_AMC6_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 6 */
#define TIMING_AMC6_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 6 */
#define TIMING_AMC6_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC6_SRC_SHIFT                 4
#define TIMING_AMC6_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC6_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 6 */
#define TIMING_AMC6_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 6 */

/* definitions for register: AMC event 6 */

/* definitions for register: AMC delay 6 */

/* definitions for register: AMC width 6 */

/* definitions for register: AMC 7 */

/* definitions for field: enable in reg: AMC 7 */
#define TIMING_AMC7_EN                        WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: AMC 7 */
#define TIMING_AMC7_POL                       WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: AMC 7 */
#define TIMING_AMC7_LOG                       WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: AMC 7 */
#define TIMING_AMC7_ITL                       WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: AMC 7 */
#define TIMING_AMC7_SRC_MASK                  WBGEN2_GEN_MASK(4, 4)
#define TIMING_AMC7_SRC_SHIFT                 4
#define TIMING_AMC7_SRC_W(value)              WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_AMC7_SRC_R(reg)                WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: AMC 7 */
#define TIMING_AMC7_DIR                       WBGEN2_GEN_MASK(8, 1)

/* definitions for register: AMC pulses 7 */

/* definitions for register: AMC event 7 */

/* definitions for register: AMC delay 7 */

/* definitions for register: AMC width 7 */

/* definitions for register: FMC1 ch0 */

/* definitions for field: enable in reg: FMC1 ch0 */
#define TIMING_FMC1CH0_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC1 ch0 */
#define TIMING_FMC1CH0_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC1 ch0 */
#define TIMING_FMC1CH0_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC1 ch0 */
#define TIMING_FMC1CH0_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC1 ch0 */
#define TIMING_FMC1CH0_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC1CH0_SRC_SHIFT              4
#define TIMING_FMC1CH0_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC1CH0_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC1 ch0 */
#define TIMING_FMC1CH0_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC1 pulses 0 */

/* definitions for register: FMC1 event 0 */

/* definitions for register: FMC1 delay 0 */

/* definitions for register: FMC1 width 0 */

/* definitions for register: FMC1 ch1 */

/* definitions for field: enable in reg: FMC1 ch1 */
#define TIMING_FMC1CH1_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC1 ch1 */
#define TIMING_FMC1CH1_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC1 ch1 */
#define TIMING_FMC1CH1_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC1 ch1 */
#define TIMING_FMC1CH1_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC1 ch1 */
#define TIMING_FMC1CH1_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC1CH1_SRC_SHIFT              4
#define TIMING_FMC1CH1_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC1CH1_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC1 ch1 */
#define TIMING_FMC1CH1_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC1 pulses 1 */

/* definitions for register: FMC1 event 1 */

/* definitions for register: FMC1 delay 1 */

/* definitions for register: FMC1 width 1 */

/* definitions for register: FMC1 ch2 */

/* definitions for field: enable in reg: FMC1 ch2 */
#define TIMING_FMC1CH2_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC1 ch2 */
#define TIMING_FMC1CH2_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC1 ch2 */
#define TIMING_FMC1CH2_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC1 ch2 */
#define TIMING_FMC1CH2_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC1 ch2 */
#define TIMING_FMC1CH2_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC1CH2_SRC_SHIFT              4
#define TIMING_FMC1CH2_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC1CH2_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC1 ch2 */
#define TIMING_FMC1CH2_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC1 pulses 2 */

/* definitions for register: FMC1 event 2 */

/* definitions for register: FMC1 delay 2 */

/* definitions for register: FMC1 width 2 */

/* definitions for register: FMC1 ch3 */

/* definitions for field: enable in reg: FMC1 ch3 */
#define TIMING_FMC1CH3_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC1 ch3 */
#define TIMING_FMC1CH3_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC1 ch3 */
#define TIMING_FMC1CH3_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC1 ch3 */
#define TIMING_FMC1CH3_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC1 ch3 */
#define TIMING_FMC1CH3_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC1CH3_SRC_SHIFT              4
#define TIMING_FMC1CH3_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC1CH3_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC1 ch3 */
#define TIMING_FMC1CH3_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC1 pulses 3 */

/* definitions for register: FMC1 event 3 */

/* definitions for register: FMC1 delay 3 */

/* definitions for register: FMC1 width 3 */

/* definitions for register: FMC1 ch4 */

/* definitions for field: enable in reg: FMC1 ch4 */
#define TIMING_FMC1CH4_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC1 ch4 */
#define TIMING_FMC1CH4_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC1 ch4 */
#define TIMING_FMC1CH4_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC1 ch4 */
#define TIMING_FMC1CH4_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC1 ch4 */
#define TIMING_FMC1CH4_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC1CH4_SRC_SHIFT              4
#define TIMING_FMC1CH4_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC1CH4_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC1 ch4 */
#define TIMING_FMC1CH4_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC1 pulses 4 */

/* definitions for register: FMC1 event 4 */

/* definitions for register: FMC1 delay 4 */

/* definitions for register: FMC1 width 4 */

/* definitions for register: FMC2 ch0 */

/* definitions for field: enable in reg: FMC2 ch0 */
#define TIMING_FMC2CH0_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC2 ch0 */
#define TIMING_FMC2CH0_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC2 ch0 */
#define TIMING_FMC2CH0_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC2 ch0 */
#define TIMING_FMC2CH0_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC2 ch0 */
#define TIMING_FMC2CH0_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC2CH0_SRC_SHIFT              4
#define TIMING_FMC2CH0_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC2CH0_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC2 ch0 */
#define TIMING_FMC2CH0_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC2 pulses 0 */

/* definitions for register: FMC2 event 0 */

/* definitions for register: FMC2 delay 0 */

/* definitions for register: FMC2 width 0 */

/* definitions for register: FMC2 ch1 */

/* definitions for field: enable in reg: FMC2 ch1 */
#define TIMING_FMC2CH1_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC2 ch1 */
#define TIMING_FMC2CH1_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC2 ch1 */
#define TIMING_FMC2CH1_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC2 ch1 */
#define TIMING_FMC2CH1_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC2 ch1 */
#define TIMING_FMC2CH1_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC2CH1_SRC_SHIFT              4
#define TIMING_FMC2CH1_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC2CH1_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC2 ch1 */
#define TIMING_FMC2CH1_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC2 pulses 1 */

/* definitions for register: FMC2 event 1 */

/* definitions for register: FMC2 delay 1 */

/* definitions for register: FMC2 width 1 */

/* definitions for register: FMC2 ch2 */

/* definitions for field: enable in reg: FMC2 ch2 */
#define TIMING_FMC2CH2_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC2 ch2 */
#define TIMING_FMC2CH2_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC2 ch2 */
#define TIMING_FMC2CH2_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC2 ch2 */
#define TIMING_FMC2CH2_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC2 ch2 */
#define TIMING_FMC2CH2_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC2CH2_SRC_SHIFT              4
#define TIMING_FMC2CH2_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC2CH2_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC2 ch2 */
#define TIMING_FMC2CH2_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC2 pulses 2 */

/* definitions for register: FMC2 event 2 */

/* definitions for register: FMC2 delay 2 */

/* definitions for register: FMC2 width 2 */

/* definitions for register: FMC2 ch3 */

/* definitions for field: enable in reg: FMC2 ch3 */
#define TIMING_FMC2CH3_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC2 ch3 */
#define TIMING_FMC2CH3_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC2 ch3 */
#define TIMING_FMC2CH3_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC2 ch3 */
#define TIMING_FMC2CH3_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC2 ch3 */
#define TIMING_FMC2CH3_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC2CH3_SRC_SHIFT              4
#define TIMING_FMC2CH3_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC2CH3_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC2 ch3 */
#define TIMING_FMC2CH3_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC2 pulses 3 */

/* definitions for register: FMC2 event 3 */

/* definitions for register: FMC2 delay 3 */

/* definitions for register: FMC2 width 3 */

/* definitions for register: FMC2 ch4 */

/* definitions for field: enable in reg: FMC2 ch4 */
#define TIMING_FMC2CH4_EN                     WBGEN2_GEN_MASK(0, 1)

/* definitions for field: polarity in reg: FMC2 ch4 */
#define TIMING_FMC2CH4_POL                    WBGEN2_GEN_MASK(1, 1)

/* definitions for field: time log in reg: FMC2 ch4 */
#define TIMING_FMC2CH4_LOG                    WBGEN2_GEN_MASK(2, 1)

/* definitions for field: interlock in reg: FMC2 ch4 */
#define TIMING_FMC2CH4_ITL                    WBGEN2_GEN_MASK(3, 1)

/* definitions for field: source in reg: FMC2 ch4 */
#define TIMING_FMC2CH4_SRC_MASK               WBGEN2_GEN_MASK(4, 4)
#define TIMING_FMC2CH4_SRC_SHIFT              4
#define TIMING_FMC2CH4_SRC_W(value)           WBGEN2_GEN_WRITE(value, 4, 4)
#define TIMING_FMC2CH4_SRC_R(reg)             WBGEN2_GEN_READ(reg, 4, 4)

/* definitions for field: diretion in reg: FMC2 ch4 */
#define TIMING_FMC2CH4_DIR                    WBGEN2_GEN_MASK(8, 1)

/* definitions for register: FMC2 pulses 4 */

/* definitions for register: FMC2 event 4 */

/* definitions for register: FMC2 delay 4 */

/* definitions for register: FMC2 width 4 */
/* [0x0]: REG Status */
#define TIMING_REG_STAT 0x00000000
/* [0x4]: REG alive */
#define TIMING_REG_ALIVE 0x00000004
/* [0x8]: REG freq_sample_rate_prescale */
#define TIMING_REG_FREQ_SAMPLE_RATE_PRESCALE 0x00000008
/* [0xc]: REG RTM Si57x RFREQ[37-20] */
#define TIMING_REG_RTM_RFREQ_HI 0x0000000c
/* [0x10]: REG RTM Si57x RFREQ[19-0] */
#define TIMING_REG_RTM_RFREQ_LO 0x00000010
/* [0x14]: REG RTM Si57x N1 & DIV */
#define TIMING_REG_RTM 0x00000014
/* [0x18]: REG RTM Freq loop */
#define TIMING_REG_RTM_FREQ 0x00000018
/* [0x1c]: REG RTM Phase loop */
#define TIMING_REG_RTM_PHASE 0x0000001c
/* [0x20]: REG RTM phase setpoint */
#define TIMING_REG_RTM_PHASE_SET 0x00000020
/* [0x24]: REG RTM DDMTD config */
#define TIMING_REG_RTM_MAF 0x00000024
/* [0x28]: REG AFC Si57x RFREQ[37-20] */
#define TIMING_REG_AFC_RFREQ_HI 0x00000028
/* [0x2c]: REG AFC Si57x RFREQ[19-0] */
#define TIMING_REG_AFC_RFREQ_LO 0x0000002c
/* [0x30]: REG AFC Si57x N1 & div */
#define TIMING_REG_AFC 0x00000030
/* [0x34]: REG AFC Freq loop */
#define TIMING_REG_AFC_FREQ 0x00000034
/* [0x38]: REG AFC Phase loop */
#define TIMING_REG_AFC_PHASE 0x00000038
/* [0x3c]: REG AFC phase setpoint */
#define TIMING_REG_AFC_PHASE_SET 0x0000003c
/* [0x40]: REG AFC DDMTD config */
#define TIMING_REG_AFC_MAF 0x00000040
/* [0x44]: REG AMC 0 */
#define TIMING_REG_AMC0 0x00000044
/* [0x48]: REG AMC pulses 0 */
#define TIMING_REG_AMC0_PULSES 0x00000048
/* [0x4c]: REG AMC event 0 */
#define TIMING_REG_AMC0_EVT 0x0000004c
/* [0x50]: REG AMC delay 0 */
#define TIMING_REG_AMC0_DLY 0x00000050
/* [0x54]: REG AMC width 0 */
#define TIMING_REG_AMC0_WDT 0x00000054
/* [0x58]: REG AMC 1 */
#define TIMING_REG_AMC1 0x00000058
/* [0x5c]: REG AMC pulses 1 */
#define TIMING_REG_AMC1_PULSES 0x0000005c
/* [0x60]: REG AMC event 1 */
#define TIMING_REG_AMC1_EVT 0x00000060
/* [0x64]: REG AMC delay 1 */
#define TIMING_REG_AMC1_DLY 0x00000064
/* [0x68]: REG AMC width 1 */
#define TIMING_REG_AMC1_WDT 0x00000068
/* [0x6c]: REG AMC 2 */
#define TIMING_REG_AMC2 0x0000006c
/* [0x70]: REG AMC pulses 2 */
#define TIMING_REG_AMC2_PULSES 0x00000070
/* [0x74]: REG AMC event 2 */
#define TIMING_REG_AMC2_EVT 0x00000074
/* [0x78]: REG AMC delay 2 */
#define TIMING_REG_AMC2_DLY 0x00000078
/* [0x7c]: REG AMC width 2 */
#define TIMING_REG_AMC2_WDT 0x0000007c
/* [0x80]: REG AMC 3 */
#define TIMING_REG_AMC3 0x00000080
/* [0x84]: REG AMC pulses 3 */
#define TIMING_REG_AMC3_PULSES 0x00000084
/* [0x88]: REG AMC event 3 */
#define TIMING_REG_AMC3_EVT 0x00000088
/* [0x8c]: REG AMC delay 3 */
#define TIMING_REG_AMC3_DLY 0x0000008c
/* [0x90]: REG AMC width 3 */
#define TIMING_REG_AMC3_WDT 0x00000090
/* [0x94]: REG AMC 4 */
#define TIMING_REG_AMC4 0x00000094
/* [0x98]: REG AMC pulses 4 */
#define TIMING_REG_AMC4_PULSES 0x00000098
/* [0x9c]: REG AMC event 4 */
#define TIMING_REG_AMC4_EVT 0x0000009c
/* [0xa0]: REG AMC delay 4 */
#define TIMING_REG_AMC4_DLY 0x000000a0
/* [0xa4]: REG AMC width 4 */
#define TIMING_REG_AMC4_WDT 0x000000a4
/* [0xa8]: REG AMC 5 */
#define TIMING_REG_AMC5 0x000000a8
/* [0xac]: REG AMC pulses 5 */
#define TIMING_REG_AMC5_PULSES 0x000000ac
/* [0xb0]: REG AMC event 5 */
#define TIMING_REG_AMC5_EVT 0x000000b0
/* [0xb4]: REG AMC delay 5 */
#define TIMING_REG_AMC5_DLY 0x000000b4
/* [0xb8]: REG AMC width 5 */
#define TIMING_REG_AMC5_WDT 0x000000b8
/* [0xbc]: REG AMC 6 */
#define TIMING_REG_AMC6 0x000000bc
/* [0xc0]: REG AMC pulses 6 */
#define TIMING_REG_AMC6_PULSES 0x000000c0
/* [0xc4]: REG AMC event 6 */
#define TIMING_REG_AMC6_EVT 0x000000c4
/* [0xc8]: REG AMC delay 6 */
#define TIMING_REG_AMC6_DLY 0x000000c8
/* [0xcc]: REG AMC width 6 */
#define TIMING_REG_AMC6_WDT 0x000000cc
/* [0xd0]: REG AMC 7 */
#define TIMING_REG_AMC7 0x000000d0
/* [0xd4]: REG AMC pulses 7 */
#define TIMING_REG_AMC7_PULSES 0x000000d4
/* [0xd8]: REG AMC event 7 */
#define TIMING_REG_AMC7_EVT 0x000000d8
/* [0xdc]: REG AMC delay 7 */
#define TIMING_REG_AMC7_DLY 0x000000dc
/* [0xe0]: REG AMC width 7 */
#define TIMING_REG_AMC7_WDT 0x000000e0
/* [0xe4]: REG FMC1 ch0 */
#define TIMING_REG_FMC1CH0 0x000000e4
/* [0xe8]: REG FMC1 pulses 0 */
#define TIMING_REG_FMC1CH0_PULSES 0x000000e8
/* [0xec]: REG FMC1 event 0 */
#define TIMING_REG_FMC1CH0_EVT 0x000000ec
/* [0xf0]: REG FMC1 delay 0 */
#define TIMING_REG_FMC1CH0_DLY 0x000000f0
/* [0xf4]: REG FMC1 width 0 */
#define TIMING_REG_FMC1CH0_WDT 0x000000f4
/* [0xf8]: REG FMC1 ch1 */
#define TIMING_REG_FMC1CH1 0x000000f8
/* [0xfc]: REG FMC1 pulses 1 */
#define TIMING_REG_FMC1CH1_PULSES 0x000000fc
/* [0x100]: REG FMC1 event 1 */
#define TIMING_REG_FMC1CH1_EVT 0x00000100
/* [0x104]: REG FMC1 delay 1 */
#define TIMING_REG_FMC1CH1_DLY 0x00000104
/* [0x108]: REG FMC1 width 1 */
#define TIMING_REG_FMC1CH1_WDT 0x00000108
/* [0x10c]: REG FMC1 ch2 */
#define TIMING_REG_FMC1CH2 0x0000010c
/* [0x110]: REG FMC1 pulses 2 */
#define TIMING_REG_FMC1CH2_PULSES 0x00000110
/* [0x114]: REG FMC1 event 2 */
#define TIMING_REG_FMC1CH2_EVT 0x00000114
/* [0x118]: REG FMC1 delay 2 */
#define TIMING_REG_FMC1CH2_DLY 0x00000118
/* [0x11c]: REG FMC1 width 2 */
#define TIMING_REG_FMC1CH2_WDT 0x0000011c
/* [0x120]: REG FMC1 ch3 */
#define TIMING_REG_FMC1CH3 0x00000120
/* [0x124]: REG FMC1 pulses 3 */
#define TIMING_REG_FMC1CH3_PULSES 0x00000124
/* [0x128]: REG FMC1 event 3 */
#define TIMING_REG_FMC1CH3_EVT 0x00000128
/* [0x12c]: REG FMC1 delay 3 */
#define TIMING_REG_FMC1CH3_DLY 0x0000012c
/* [0x130]: REG FMC1 width 3 */
#define TIMING_REG_FMC1CH3_WDT 0x00000130
/* [0x134]: REG FMC1 ch4 */
#define TIMING_REG_FMC1CH4 0x00000134
/* [0x138]: REG FMC1 pulses 4 */
#define TIMING_REG_FMC1CH4_PULSES 0x00000138
/* [0x13c]: REG FMC1 event 4 */
#define TIMING_REG_FMC1CH4_EVT 0x0000013c
/* [0x140]: REG FMC1 delay 4 */
#define TIMING_REG_FMC1CH4_DLY 0x00000140
/* [0x144]: REG FMC1 width 4 */
#define TIMING_REG_FMC1CH4_WDT 0x00000144
/* [0x148]: REG FMC2 ch0 */
#define TIMING_REG_FMC2CH0 0x00000148
/* [0x14c]: REG FMC2 pulses 0 */
#define TIMING_REG_FMC2CH0_PULSES 0x0000014c
/* [0x150]: REG FMC2 event 0 */
#define TIMING_REG_FMC2CH0_EVT 0x00000150
/* [0x154]: REG FMC2 delay 0 */
#define TIMING_REG_FMC2CH0_DLY 0x00000154
/* [0x158]: REG FMC2 width 0 */
#define TIMING_REG_FMC2CH0_WDT 0x00000158
/* [0x15c]: REG FMC2 ch1 */
#define TIMING_REG_FMC2CH1 0x0000015c
/* [0x160]: REG FMC2 pulses 1 */
#define TIMING_REG_FMC2CH1_PULSES 0x00000160
/* [0x164]: REG FMC2 event 1 */
#define TIMING_REG_FMC2CH1_EVT 0x00000164
/* [0x168]: REG FMC2 delay 1 */
#define TIMING_REG_FMC2CH1_DLY 0x00000168
/* [0x16c]: REG FMC2 width 1 */
#define TIMING_REG_FMC2CH1_WDT 0x0000016c
/* [0x170]: REG FMC2 ch2 */
#define TIMING_REG_FMC2CH2 0x00000170
/* [0x174]: REG FMC2 pulses 2 */
#define TIMING_REG_FMC2CH2_PULSES 0x00000174
/* [0x178]: REG FMC2 event 2 */
#define TIMING_REG_FMC2CH2_EVT 0x00000178
/* [0x17c]: REG FMC2 delay 2 */
#define TIMING_REG_FMC2CH2_DLY 0x0000017c
/* [0x180]: REG FMC2 width 2 */
#define TIMING_REG_FMC2CH2_WDT 0x00000180
/* [0x184]: REG FMC2 ch3 */
#define TIMING_REG_FMC2CH3 0x00000184
/* [0x188]: REG FMC2 pulses 3 */
#define TIMING_REG_FMC2CH3_PULSES 0x00000188
/* [0x18c]: REG FMC2 event 3 */
#define TIMING_REG_FMC2CH3_EVT 0x0000018c
/* [0x190]: REG FMC2 delay 3 */
#define TIMING_REG_FMC2CH3_DLY 0x00000190
/* [0x194]: REG FMC2 width 3 */
#define TIMING_REG_FMC2CH3_WDT 0x00000194
/* [0x198]: REG FMC2 ch4 */
#define TIMING_REG_FMC2CH4 0x00000198
/* [0x19c]: REG FMC2 pulses 4 */
#define TIMING_REG_FMC2CH4_PULSES 0x0000019c
/* [0x1a0]: REG FMC2 event 4 */
#define TIMING_REG_FMC2CH4_EVT 0x000001a0
/* [0x1a4]: REG FMC2 delay 4 */
#define TIMING_REG_FMC2CH4_DLY 0x000001a4
/* [0x1a8]: REG FMC2 width 4 */
#define TIMING_REG_FMC2CH4_WDT 0x000001a8
#endif
