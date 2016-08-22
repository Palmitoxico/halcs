#ifndef _DDR3_MAP_H_
#define _DDR3_MAP_H_

#include "acq_chan.h"
#include "varg_macros.h"

/* Does the acquisition channel gets a memory region? */
#define DDR3_MEM_BOOL(MEM_SIZE)         IF(MEM_SIZE > 0)(1, 0)

/* Start of the acquisition memory address */
#define DDR3_ACQ_START_ADDR             0x0

/* Dummy region
 * Size: 0 DDR3 regions */
#define DDR3_DUMMY_INIT0_SAMPLE_SIZE    0
#define DDR3_DUMMY_INIT0_MEM_SIZE       0

#define DDR3_DUMMY_INIT0_MEM_BOOL       DDR3_MEM_BOOL(DDR3_DUMMY_INIT0_MEM_SIZE)
#define DDR3_DUMMY_INIT0_START_ADDR     DDR3_ACQ_START_ADDR
#define DDR3_DUMMY_INIT0_END_ADDR       (DDR3_DUMMY_INIT0_START_ADDR + DDR3_DUMMY_INIT0_MEM_SIZE*MEM_REGION_SIZE)
#define DDR3_DUMMY_INIT0_MAX_SAMPLES    (DDR3_DUMMY_INIT0_END_ADDR-DDR3_DUMMY_INIT0_START_ADDR)

/************************ Acquistion 0 Channel Parameters **************/

/* ADC 0 (shares the same memory space as the ADCSWAP0)
 * Size: 2 DDR3 regions */
#define DDR3_ADC0_SAMPLE_SIZE           ADC_SAMPLE_SIZE
#define DDR3_ADC0_MEM_SIZE              2

#define DDR3_ADC0_MEM_BOOL              DDR3_MEM_BOOL(DDR3_ADC0_MEM_SIZE)
#define DDR3_ADC0_START_ADDR            (DDR3_DUMMY_INIT0_START_ADDR + DDR3_DUMMY_INIT0_MEM_BOOL*DDR3_DUMMY_INIT0_SAMPLE_SIZE)
#define DDR3_ADC0_END_ADDR              (DDR3_ADC0_START_ADDR + DDR3_ADC0_MEM_SIZE*MEM_REGION_SIZE - DDR3_ADC0_MEM_BOOL*DDR3_ADC0_SAMPLE_SIZE)
#define DDR3_ADC0_MAX_SAMPLES           ((DDR3_ADC0_END_ADDR-DDR3_ADC0_START_ADDR) / DDR3_ADC0_SAMPLE_SIZE)

/* ADCSWAP 0 (shares the same memory space as the ADC0)
 * Size: 2 DDR3 regions */
#define DDR3_ADCSWAP0_SAMPLE_SIZE       ADCSWAP_SAMPLE_SIZE
#define DDR3_ADCSWAP0_MEM_SIZE          2

#define DDR3_ADCSWAP0_MEM_BOOL          DDR3_MEM_BOOL(DDR3_ADCSWAP0_MEM_SIZE)
#define DDR3_ADCSWAP0_START_ADDR        (DDR3_DUMMY_INIT0_START_ADDR + DDR3_DUMMY_INIT0_MEM_BOOL*DDR3_DUMMY_INIT0_SAMPLE_SIZE)
#define DDR3_ADCSWAP0_END_ADDR          (DDR3_ADCSWAP0_START_ADDR + DDR3_ADCSWAP0_MEM_SIZE*MEM_REGION_SIZE - DDR3_ADCSWAP0_MEM_BOOL*DDR3_ADCSWAP0_SAMPLE_SIZE)
#define DDR3_ADCSWAP0_MAX_SAMPLES       ((DDR3_ADCSWAP0_END_ADDR-DDR3_ADCSWAP0_START_ADDR) / DDR3_ADCSWAP0_SAMPLE_SIZE)

/* MIXER I/Q 1/2 (shares the same memory space as the DUMMY00)
 * Size: 1 DDR3 regions */
#define DDR3_MIXIQ0_SAMPLE_SIZE         MIXIQ_SAMPLE_SIZE
#define DDR3_MIXIQ0_MEM_SIZE            1

#define DDR3_MIXIQ0_MEM_BOOL            DDR3_MEM_BOOL(DDR3_MIXIQ0_MEM_SIZE)
#define DDR3_MIXIQ0_START_ADDR          (DDR3_ADCSWAP0_END_ADDR + DDR3_ADCSWAP0_MEM_BOOL*DDR3_ADCSWAP0_SAMPLE_SIZE)
#define DDR3_MIXIQ0_END_ADDR            (DDR3_MIXIQ0_START_ADDR + DDR3_MIXIQ0_MEM_SIZE*MEM_REGION_SIZE - DDR3_MIXIQ0_MEM_BOOL*DDR3_MIXIQ0_SAMPLE_SIZE)
#define DDR3_MIXIQ0_MAX_SAMPLES         ((DDR3_MIXIQ0_END_ADDR-DDR3_MIXIQ0_START_ADDR) / DDR3_MIXIQ0_SAMPLE_SIZE)

/* MIXER I/Q 3/4 (shares the same memory space as the MIXIQ0)
 * Size: 1 DDR3 regions */
#define DDR3_DUMMY00_SAMPLE_SIZE        MIXIQ_SAMPLE_SIZE
#define DDR3_DUMMY00_MEM_SIZE           0

#define DDR3_DUMMY00_MEM_BOOL           DDR3_MEM_BOOL(DDR3_DUMMY00_MEM_SIZE)
#define DDR3_DUMMY00_START_ADDR         (DDR3_ADCSWAP0_END_ADDR + DDR3_ADCSWAP0_MEM_BOOL*DDR3_ADCSWAP0_SAMPLE_SIZE)
#define DDR3_DUMMY00_END_ADDR           (DDR3_DUMMY00_START_ADDR + DDR3_DUMMY00_MEM_SIZE*MEM_REGION_SIZE - DDR3_DUMMY00_MEM_BOOL*DDR3_DUMMY00_SAMPLE_SIZE)
#define DDR3_DUMMY00_MAX_SAMPLES        ((DDR3_DUMMY00_END_ADDR-DDR3_DUMMY00_START_ADDR) / DDR3_DUMMY00_SAMPLE_SIZE)

/* TBTDECIM I/Q 1/2 (shares the same memory space as the DUMMY10 and TBTAMP0)
 * Size: 1 DDR3 regions */
#define DDR3_TBTDECIMIQ0_SAMPLE_SIZE    TBTDECIMIQ_SAMPLE_SIZE
#define DDR3_TBTDECIMIQ0_MEM_SIZE       2

#define DDR3_TBTDECIMIQ0_MEM_BOOL       DDR3_MEM_BOOL(DDR3_TBTDECIMIQ0_MEM_SIZE)
#define DDR3_TBTDECIMIQ0_START_ADDR     (DDR3_DUMMY00_END_ADDR + DDR3_DUMMY00_MEM_BOOL*DDR3_DUMMY00_SAMPLE_SIZE)
#define DDR3_TBTDECIMIQ0_END_ADDR       (DDR3_TBTDECIMIQ0_START_ADDR + DDR3_TBTDECIMIQ0_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTDECIMIQ0_MEM_BOOL*DDR3_TBTDECIMIQ0_SAMPLE_SIZE)
#define DDR3_TBTDECIMIQ0_MAX_SAMPLES    ((DDR3_TBTDECIMIQ0_END_ADDR-DDR3_TBTDECIMIQ0_START_ADDR) / DDR3_TBTDECIMIQ0_SAMPLE_SIZE)

/* TBTDECIM I/Q 3/4 (shares the same memory space as the TBTDECIMIQ0 and TBTAMP0)
 * Size: 1 DDR3 regions */
#define DDR3_DUMMY10_SAMPLE_SIZE        TBTDECIMIQ_SAMPLE_SIZE
#define DDR3_DUMMY10_MEM_SIZE           0

#define DDR3_DUMMY10_MEM_BOOL           DDR3_MEM_BOOL(DDR3_DUMMY10_MEM_SIZE)
#define DDR3_DUMMY10_START_ADDR         (DDR3_DUMMY00_END_ADDR + DDR3_DUMMY00_MEM_BOOL*DDR3_DUMMY00_SAMPLE_SIZE)
#define DDR3_DUMMY10_END_ADDR           (DDR3_DUMMY10_START_ADDR + DDR3_DUMMY10_MEM_SIZE*MEM_REGION_SIZE - DDR3_DUMMY10_MEM_BOOL*DDR3_DUMMY10_SAMPLE_SIZE)
#define DDR3_DUMMY10_MAX_SAMPLES        ((DDR3_DUMMY10_END_ADDR-DDR3_DUMMY10_START_ADDR) / DDR3_DUMMY10_SAMPLE_SIZE)

/* TBT 0 AMP (shares the same memory space as the TBTDECIMIQ0 and DUMMY10)
 * Size: 2 DDR3 regions */
#define DDR3_TBTAMP0_SAMPLE_SIZE        TBTAMP_SAMPLE_SIZE
#define DDR3_TBTAMP0_MEM_SIZE           2

#define DDR3_TBTAMP0_MEM_BOOL           DDR3_MEM_BOOL(DDR3_TBTAMP0_MEM_SIZE)
#define DDR3_TBTAMP0_START_ADDR         (DDR3_DUMMY00_END_ADDR + DDR3_DUMMY00_MEM_BOOL*DDR3_DUMMY00_SAMPLE_SIZE)
#define DDR3_TBTAMP0_END_ADDR           (DDR3_TBTAMP0_START_ADDR + DDR3_TBTAMP0_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTAMP0_MEM_BOOL*DDR3_TBTAMP0_SAMPLE_SIZE)
#define DDR3_TBTAMP0_MAX_SAMPLES        ((DDR3_TBTAMP0_END_ADDR-DDR3_TBTAMP0_START_ADDR) / DDR3_TBTAMP0_SAMPLE_SIZE)

/* TBT 0 PHA (shares the same memory space as the TBTDECIMIQ0 and DUMMY10)
 * Size: 2 DDR3 regions */
#define DDR3_TBTPHA0_SAMPLE_SIZE        TBTPHA_SAMPLE_SIZE
#define DDR3_TBTPHA0_MEM_SIZE           2

#define DDR3_TBTPHA0_MEM_BOOL           DDR3_MEM_BOOL(DDR3_TBTPHA0_MEM_SIZE)
#define DDR3_TBTPHA0_START_ADDR         (DDR3_DUMMY00_END_ADDR + DDR3_DUMMY00_MEM_BOOL*DDR3_DUMMY00_SAMPLE_SIZE)
#define DDR3_TBTPHA0_END_ADDR           (DDR3_TBTPHA0_START_ADDR + DDR3_TBTPHA0_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTPHA0_MEM_BOOL*DDR3_TBTPHA0_SAMPLE_SIZE)
#define DDR3_TBTPHA0_MAX_SAMPLES        ((DDR3_TBTPHA0_END_ADDR-DDR3_TBTPHA0_START_ADDR) / DDR3_TBTPHA0_SAMPLE_SIZE)

/* TBT 0 POS (shares the same memory space as the TBTDECIMIQ0 and DUMMY10)
 * Size: 0 DDR3 regions */
#define DDR3_TBTPOS0_SAMPLE_SIZE        TBTPOS_SAMPLE_SIZE
#define DDR3_TBTPOS0_MEM_SIZE           2

#define DDR3_TBTPOS0_MEM_BOOL           DDR3_MEM_BOOL(DDR3_TBTPOS0_MEM_SIZE)
#define DDR3_TBTPOS0_START_ADDR         (DDR3_DUMMY00_END_ADDR + DDR3_DUMMY00_MEM_BOOL*DDR3_DUMMY00_SAMPLE_SIZE)
#define DDR3_TBTPOS0_END_ADDR           (DDR3_TBTPOS0_START_ADDR + DDR3_TBTPOS0_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTPOS0_MEM_BOOL*DDR3_TBTPOS0_SAMPLE_SIZE)
#define DDR3_TBTPOS0_MAX_SAMPLES        ((DDR3_TBTPOS0_END_ADDR-DDR3_TBTPOS0_START_ADDR) / DDR3_TBTPOS0_SAMPLE_SIZE)

/* FOFBDECIM I/Q 1/2 (shares the same memory space as the DUMMY20 and FOFBAMP0)
 * Size: 1 DDR3 regions */
#define DDR3_FOFBDECIMIQ0_SAMPLE_SIZE   FOFBDECIMIQ_SAMPLE_SIZE
#define DDR3_FOFBDECIMIQ0_MEM_SIZE      2

#define DDR3_FOFBDECIMIQ0_MEM_BOOL      DDR3_MEM_BOOL(DDR3_FOFBDECIMIQ0_MEM_SIZE)
#define DDR3_FOFBDECIMIQ0_START_ADDR    (DDR3_TBTPOS0_END_ADDR + DDR3_TBTPOS0_MEM_BOOL*DDR3_TBTPOS0_SAMPLE_SIZE)
#define DDR3_FOFBDECIMIQ0_END_ADDR      (DDR3_FOFBDECIMIQ0_START_ADDR + DDR3_FOFBDECIMIQ0_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBDECIMIQ0_MEM_BOOL*DDR3_FOFBDECIMIQ0_SAMPLE_SIZE)
#define DDR3_FOFBDECIMIQ0_MAX_SAMPLES   ((DDR3_FOFBDECIMIQ0_END_ADDR-DDR3_FOFBDECIMIQ0_START_ADDR) / DDR3_FOFBDECIMIQ0_SAMPLE_SIZE)

/* FOFBDECIM I/Q 3/4 (shares the same memory space as the FOFBDECIMIQ0 and FOFBAMP0)
 * Size: 1 DDR3 regions */
#define DDR3_DUMMY20_SAMPLE_SIZE        FOFBDECIMIQ_SAMPLE_SIZE
#define DDR3_DUMMY20_MEM_SIZE           0

#define DDR3_DUMMY20_MEM_BOOL           DDR3_MEM_BOOL(DDR3_DUMMY20_MEM_SIZE)
#define DDR3_DUMMY20_START_ADDR         (DDR3_TBTPOS0_END_ADDR + DDR3_TBTPOS0_MEM_BOOL*DDR3_TBTPOS0_SAMPLE_SIZE)
#define DDR3_DUMMY20_END_ADDR           (DDR3_DUMMY20_START_ADDR + DDR3_DUMMY20_MEM_SIZE*MEM_REGION_SIZE - DDR3_DUMMY20_MEM_BOOL*DDR3_DUMMY20_SAMPLE_SIZE)
#define DDR3_DUMMY20_MAX_SAMPLES        ((DDR3_DUMMY20_END_ADDR-DDR3_DUMMY20_START_ADDR) / DDR3_DUMMY20_SAMPLE_SIZE)

/* FOFB 0 AMP
 * Size: 2 DDR3 regions */
#define DDR3_FOFBAMP0_SAMPLE_SIZE       FOFBAMP_SAMPLE_SIZE
#define DDR3_FOFBAMP0_MEM_SIZE          2

#define DDR3_FOFBAMP0_MEM_BOOL          DDR3_MEM_BOOL(DDR3_FOFBAMP0_MEM_SIZE)
#define DDR3_FOFBAMP0_START_ADDR        (DDR3_TBTPOS0_END_ADDR + DDR3_TBTPOS0_MEM_BOOL*DDR3_TBTPOS0_SAMPLE_SIZE)
#define DDR3_FOFBAMP0_END_ADDR          (DDR3_FOFBAMP0_START_ADDR + DDR3_FOFBAMP0_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBAMP0_MEM_BOOL*DDR3_FOFBAMP0_SAMPLE_SIZE)
#define DDR3_FOFBAMP0_MAX_SAMPLES       ((DDR3_FOFBAMP0_END_ADDR-DDR3_FOFBAMP0_START_ADDR) / DDR3_FOFBAMP0_SAMPLE_SIZE)

/* FOFB 0 PHA (shares the same memory space as the FOFBDECIMIQ12 and FOFBDECIMIQ34)
 * Size: 2 DDR3 regions */
#define DDR3_FOFBPHA0_SAMPLE_SIZE       FOFBPHA_SAMPLE_SIZE
#define DDR3_FOFBPHA0_MEM_SIZE          2

#define DDR3_FOFBPHA0_MEM_BOOL          DDR3_MEM_BOOL(DDR3_FOFBPHA0_MEM_SIZE)
#define DDR3_FOFBPHA0_START_ADDR        (DDR3_TBTPOS0_END_ADDR + DDR3_TBTPOS0_MEM_BOOL*DDR3_TBTPOS0_SAMPLE_SIZE)
#define DDR3_FOFBPHA0_END_ADDR          (DDR3_FOFBPHA0_START_ADDR + DDR3_FOFBPHA0_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBPHA0_MEM_BOOL*DDR3_FOFBPHA0_SAMPLE_SIZE)
#define DDR3_FOFBPHA0_MAX_SAMPLES       ((DDR3_FOFBPHA0_END_ADDR-DDR3_FOFBPHA0_START_ADDR) / DDR3_FOFBPHA0_SAMPLE_SIZE)

/* FOFB 0 POS
 * Size: 0 DDR3 regions */
#define DDR3_FOFBPOS0_SAMPLE_SIZE       FOFBPOS_SAMPLE_SIZE
#define DDR3_FOFBPOS0_MEM_SIZE          2

#define DDR3_FOFBPOS0_MEM_BOOL          DDR3_MEM_BOOL(DDR3_FOFBPOS0_MEM_SIZE)
#define DDR3_FOFBPOS0_START_ADDR        (DDR3_TBTPOS0_END_ADDR + DDR3_TBTPOS0_MEM_BOOL*DDR3_TBTPOS0_SAMPLE_SIZE)
#define DDR3_FOFBPOS0_END_ADDR          (DDR3_FOFBPOS0_START_ADDR + DDR3_FOFBPOS0_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBPOS0_MEM_BOOL*DDR3_FOFBPOS0_SAMPLE_SIZE)
#define DDR3_FOFBPOS0_MAX_SAMPLES       ((DDR3_FOFBPOS0_END_ADDR-DDR3_FOFBPOS0_START_ADDR) / DDR3_FOFBPOS0_SAMPLE_SIZE)

 /* MONIT 0 AMP
 * Size: 0 DDR3 regions */
#define DDR3_MONITAMP0_SAMPLE_SIZE      MONITAMP_SAMPLE_SIZE
#define DDR3_MONITAMP0_MEM_SIZE         0

#define DDR3_MONITAMP0_MEM_BOOL         DDR3_MEM_BOOL(DDR3_MONITAMP0_MEM_SIZE)
#define DDR3_MONITAMP0_START_ADDR       (DDR3_FOFBPOS0_END_ADDR + DDR3_FOFBPOS0_MEM_BOOL*DDR3_FOFBPOS0_SAMPLE_SIZE)
#define DDR3_MONITAMP0_END_ADDR         (DDR3_MONITAMP0_START_ADDR + DDR3_MONITAMP0_MEM_SIZE*MEM_REGION_SIZE - DDR3_MONITAMP0_MEM_BOOL*DDR3_MONITAMP0_SAMPLE_SIZE)
#define DDR3_MONITAMP0_MAX_SAMPLES      ((DDR3_MONITAMP0_END_ADDR-DDR3_MONITAMP0_START_ADDR) / DDR3_MONITAMP0_SAMPLE_SIZE)

/* MONIT 0 POS
 * Size: 0 DDR3 regions */
#define DDR3_MONITPOS0_SAMPLE_SIZE      MONITPOS_SAMPLE_SIZE
#define DDR3_MONITPOS0_MEM_SIZE         0

#define DDR3_MONITPOS0_MEM_BOOL         DDR3_MEM_BOOL(DDR3_MONITPOS0_MEM_SIZE)
#define DDR3_MONITPOS0_START_ADDR       (DDR3_MONITAMP0_END_ADDR + DDR3_MONITAMP0_MEM_BOOL*DDR3_MONITAMP0_SAMPLE_SIZE)
#define DDR3_MONITPOS0_END_ADDR         (DDR3_MONITPOS0_START_ADDR + DDR3_MONITPOS0_MEM_SIZE*MEM_REGION_SIZE - DDR3_MONITPOS0_MEM_BOOL*DDR3_MONITPOS0_SAMPLE_SIZE)
#define DDR3_MONITPOS0_MAX_SAMPLES      ((DDR3_MONITPOS0_END_ADDR-DDR3_MONITPOS0_START_ADDR) / DDR3_MONITPOS0_SAMPLE_SIZE)

/* MONIT1 0 POS
 * Size: 0 DDR3 regions */
#define DDR3_MONIT1POS0_SAMPLE_SIZE     MONIT1POS_SAMPLE_SIZE
#define DDR3_MONIT1POS0_MEM_SIZE        0

#define DDR3_MONIT1POS0_MEM_BOOL        DDR3_MEM_BOOL(DDR3_MONIT1POS0_MEM_SIZE)
#define DDR3_MONIT1POS0_START_ADDR      (DDR3_MONITPOS0_END_ADDR + DDR3_MONITPOS0_MEM_BOOL*DDR3_MONITPOS0_SAMPLE_SIZE)
#define DDR3_MONIT1POS0_END_ADDR        (DDR3_MONIT1POS0_START_ADDR + DDR3_MONIT1POS0_MEM_SIZE*MEM_REGION_SIZE - DDR3_MONIT1POS0_MEM_BOOL*DDR3_MONIT1POS0_SAMPLE_SIZE)
#define DDR3_MONIT1POS0_MAX_SAMPLES     ((DDR3_MONIT1POS0_END_ADDR-DDR3_MONIT1POS0_START_ADDR) / DDR3_MONIT1POS0_SAMPLE_SIZE)

/* End 0 Dummy region
 * Size: 0 DDR3 regions */
#define DDR3_DUMMY_END0_SAMPLE_SIZE     MONIT1POS_SAMPLE_SIZE
#define DDR3_DUMMY_END0_MEM_SIZE        0

#define DDR3_DUMMY_END0_MEM_BOOL        DDR3_MEM_BOOL(DDR3_DUMMY_END0_MEM_SIZE)
#define DDR3_DUMMY_END0_START_ADDR      DDR3_MONIT1POS0_END_ADDR
#define DDR3_DUMMY_END0_END_ADDR        (DDR3_DUMMY_END0_START_ADDR + DDR3_DUMMY_END0_MEM_SIZE*MEM_REGION_SIZE)
#define DDR3_DUMMY_END0_MAX_SAMPLES     (DDR3_DUMMY_END0_END_ADDR-DDR3_DUMMY_END0_START_ADDR)

/************************ Acquistion 1 Channel Parameters **************/

/* ADC 1
 * Size: 2 DDR3 regions */
#define DDR3_ADC1_SAMPLE_SIZE           ADC_SAMPLE_SIZE
#define DDR3_ADC1_MEM_SIZE              2

#define DDR3_ADC1_MEM_BOOL              DDR3_MEM_BOOL(DDR3_ADC1_MEM_SIZE)
#define DDR3_ADC1_START_ADDR            (DDR3_DUMMY_END0_START_ADDR + DDR3_DUMMY_END0_MEM_BOOL*DDR3_DUMMY_END0_SAMPLE_SIZE)
#define DDR3_ADC1_END_ADDR              (DDR3_ADC1_START_ADDR + DDR3_ADC1_MEM_SIZE*MEM_REGION_SIZE - DDR3_ADC1_MEM_BOOL*DDR3_ADC1_SAMPLE_SIZE)
#define DDR3_ADC1_MAX_SAMPLES           ((DDR3_ADC1_END_ADDR-DDR3_ADC1_START_ADDR) / DDR3_ADC1_SAMPLE_SIZE)

/* ADCSWAP 1
 * Size: 2 DDR3 regions */
#define DDR3_ADCSWAP1_SAMPLE_SIZE       ADCSWAP_SAMPLE_SIZE
#define DDR3_ADCSWAP1_MEM_SIZE          2

#define DDR3_ADCSWAP1_MEM_BOOL          DDR3_MEM_BOOL(DDR3_ADCSWAP1_MEM_SIZE)
#define DDR3_ADCSWAP1_START_ADDR        (DDR3_DUMMY_END0_START_ADDR + DDR3_DUMMY_END0_MEM_BOOL*DDR3_DUMMY_END0_SAMPLE_SIZE)
#define DDR3_ADCSWAP1_END_ADDR          (DDR3_ADCSWAP1_START_ADDR + DDR3_ADCSWAP1_MEM_SIZE*MEM_REGION_SIZE - DDR3_ADCSWAP1_MEM_BOOL*DDR3_ADCSWAP1_SAMPLE_SIZE)
#define DDR3_ADCSWAP1_MAX_SAMPLES       ((DDR3_ADCSWAP1_END_ADDR-DDR3_ADCSWAP1_START_ADDR) / DDR3_ADCSWAP1_SAMPLE_SIZE)

/* MIXER I/Q 1/2 (shares the same memory space as the DUMMY01)
 * Size: 1 DDR3 regions */
#define DDR3_MIXIQ1_SAMPLE_SIZE         MIXIQ_SAMPLE_SIZE
#define DDR3_MIXIQ1_MEM_SIZE            1

#define DDR3_MIXIQ1_MEM_BOOL            DDR3_MEM_BOOL(DDR3_MIXIQ1_MEM_SIZE)
#define DDR3_MIXIQ1_START_ADDR          (DDR3_ADCSWAP1_END_ADDR + DDR3_ADCSWAP0_MEM_BOOL*DDR3_ADCSWAP0_SAMPLE_SIZE)
#define DDR3_MIXIQ1_END_ADDR            (DDR3_MIXIQ1_START_ADDR + DDR3_MIXIQ1_MEM_SIZE*MEM_REGION_SIZE - DDR3_MIXIQ1_MEM_BOOL*DDR3_MIXIQ1_SAMPLE_SIZE)
#define DDR3_MIXIQ1_MAX_SAMPLES         ((DDR3_MIXIQ1_END_ADDR-DDR3_MIXIQ1_START_ADDR) / DDR3_MIXIQ1_SAMPLE_SIZE)

/* MIXER I/Q 3/4 (shares the same memory space as the MIXIQ1)
 * Size: 1 DDR3 regions */
#define DDR3_DUMMY01_SAMPLE_SIZE       MIXIQ_SAMPLE_SIZE
#define DDR3_DUMMY01_MEM_SIZE          1

#define DDR3_DUMMY01_MEM_BOOL          DDR3_MEM_BOOL(DDR3_DUMMY01_MEM_SIZE)
#define DDR3_DUMMY01_START_ADDR        (DDR3_ADCSWAP1_END_ADDR + DDR3_ADCSWAP0_MEM_BOOL*DDR3_ADCSWAP0_SAMPLE_SIZE)
#define DDR3_DUMMY01_END_ADDR          (DDR3_DUMMY01_START_ADDR + DDR3_DUMMY01_MEM_SIZE*MEM_REGION_SIZE - DDR3_DUMMY01_MEM_BOOL*DDR3_DUMMY01_SAMPLE_SIZE)
#define DDR3_DUMMY01_MAX_SAMPLES       ((DDR3_DUMMY01_END_ADDR-DDR3_DUMMY01_START_ADDR) / DDR3_DUMMY01_SAMPLE_SIZE)

/* TBTDECIM I/Q 1/2 (shares the same memory space as the DUMMY11 and TBTAMP1)
 * Size: 1 DDR3 regions */
#define DDR3_TBTDECIMIQ1_SAMPLE_SIZE    TBTDECIMIQ_SAMPLE_SIZE
#define DDR3_TBTDECIMIQ1_MEM_SIZE       2

#define DDR3_TBTDECIMIQ1_MEM_BOOL       DDR3_MEM_BOOL(DDR3_TBTDECIMIQ1_MEM_SIZE)
#define DDR3_TBTDECIMIQ1_START_ADDR     (DDR3_DUMMY01_END_ADDR + DDR3_DUMMY01_MEM_BOOL*DDR3_DUMMY01_SAMPLE_SIZE)
#define DDR3_TBTDECIMIQ1_END_ADDR       (DDR3_TBTDECIMIQ1_START_ADDR + DDR3_TBTDECIMIQ1_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTDECIMIQ1_MEM_BOOL*DDR3_TBTDECIMIQ1_SAMPLE_SIZE)
#define DDR3_TBTDECIMIQ1_MAX_SAMPLES    ((DDR3_TBTDECIMIQ1_END_ADDR-DDR3_TBTDECIMIQ1_START_ADDR) / DDR3_TBTDECIMIQ1_SAMPLE_SIZE)

/* TBTDECIM I/Q 3/4 (shares the same memory space as the TBTDECIMIQ1 and TBTAMP1)
 * Size: 1 DDR3 regions */
#define DDR3_DUMMY11_SAMPLE_SIZE        TBTDECIMIQ_SAMPLE_SIZE
#define DDR3_DUMMY11_MEM_SIZE           2

#define DDR3_DUMMY11_MEM_BOOL           DDR3_MEM_BOOL(DDR3_DUMMY11_MEM_SIZE)
#define DDR3_DUMMY11_START_ADDR         (DDR3_DUMMY01_END_ADDR + DDR3_DUMMY01_MEM_BOOL*DDR3_DUMMY01_SAMPLE_SIZE)
#define DDR3_DUMMY11_END_ADDR           (DDR3_DUMMY11_START_ADDR + DDR3_DUMMY11_MEM_SIZE*MEM_REGION_SIZE - DDR3_DUMMY11_MEM_BOOL*DDR3_DUMMY11_SAMPLE_SIZE)
#define DDR3_DUMMY11_MAX_SAMPLES        ((DDR3_DUMMY11_END_ADDR-DDR3_DUMMY11_START_ADDR) / DDR3_DUMMY11_SAMPLE_SIZE)

/* TBT 1 AMP
 * Size: 2 DDR3 regions */
#define DDR3_TBTAMP1_SAMPLE_SIZE        TBTAMP_SAMPLE_SIZE
#define DDR3_TBTAMP1_MEM_SIZE           2

#define DDR3_TBTAMP1_MEM_BOOL           DDR3_MEM_BOOL(DDR3_TBTAMP1_MEM_SIZE)
#define DDR3_TBTAMP1_START_ADDR         (DDR3_DUMMY01_END_ADDR + DDR3_DUMMY01_MEM_BOOL*DDR3_DUMMY01_SAMPLE_SIZE)
#define DDR3_TBTAMP1_END_ADDR           (DDR3_TBTAMP1_START_ADDR + DDR3_TBTAMP1_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTAMP1_MEM_BOOL*DDR3_TBTAMP1_SAMPLE_SIZE)
#define DDR3_TBTAMP1_MAX_SAMPLES        ((DDR3_TBTAMP1_END_ADDR-DDR3_TBTAMP1_START_ADDR) / DDR3_TBTAMP1_SAMPLE_SIZE)

/* TBT 1 PHA (shares the same memory space as the TBTDECIMIQ1 and DUMMY11)
 * Size: 2 DDR3 regions */
#define DDR3_TBTPHA1_SAMPLE_SIZE        TBTPHA_SAMPLE_SIZE
#define DDR3_TBTPHA1_MEM_SIZE           2

#define DDR3_TBTPHA1_MEM_BOOL           DDR3_MEM_BOOL(DDR3_TBTPHA1_MEM_SIZE)
#define DDR3_TBTPHA1_START_ADDR         (DDR3_DUMMY01_END_ADDR + DDR3_DUMMY01_MEM_BOOL*DDR3_DUMMY01_SAMPLE_SIZE)
#define DDR3_TBTPHA1_END_ADDR           (DDR3_TBTPHA1_START_ADDR + DDR3_TBTPHA1_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTPHA1_MEM_BOOL*DDR3_TBTPHA1_SAMPLE_SIZE)
#define DDR3_TBTPHA1_MAX_SAMPLES        ((DDR3_TBTPHA1_END_ADDR-DDR3_TBTPHA1_START_ADDR) / DDR3_TBTPHA1_SAMPLE_SIZE)

/* TBT 1 POS
 * Size: 1 DDR3 regions */
#define DDR3_TBTPOS1_SAMPLE_SIZE        TBTPOS_SAMPLE_SIZE
#define DDR3_TBTPOS1_MEM_SIZE           2

#define DDR3_TBTPOS1_MEM_BOOL           DDR3_MEM_BOOL(DDR3_TBTPOS1_MEM_SIZE)
#define DDR3_TBTPOS1_START_ADDR         (DDR3_DUMMY01_END_ADDR + DDR3_DUMMY01_MEM_BOOL*DDR3_DUMMY01_SAMPLE_SIZE)
#define DDR3_TBTPOS1_END_ADDR           (DDR3_TBTPOS1_START_ADDR + DDR3_TBTPOS1_MEM_SIZE*MEM_REGION_SIZE - DDR3_TBTPOS1_MEM_BOOL*DDR3_TBTPOS1_SAMPLE_SIZE)
#define DDR3_TBTPOS1_MAX_SAMPLES        ((DDR3_TBTPOS1_END_ADDR-DDR3_TBTPOS1_START_ADDR) / DDR3_TBTPOS1_SAMPLE_SIZE)

/* FOFBDECIM I/Q 1/2 (shares the same memory space as the DUMMY21 and FOFBAMP1)
 * Size: 1 DDR3 regions */
#define DDR3_FOFBDECIMIQ1_SAMPLE_SIZE   FOFBDECIMIQ_SAMPLE_SIZE
#define DDR3_FOFBDECIMIQ1_MEM_SIZE      2

#define DDR3_FOFBDECIMIQ1_MEM_BOOL      DDR3_MEM_BOOL(DDR3_FOFBDECIMIQ1_MEM_SIZE)
#define DDR3_FOFBDECIMIQ1_START_ADDR    (DDR3_TBTPOS1_END_ADDR + DDR3_TBTPOS1_MEM_BOOL*DDR3_TBTPOS1_SAMPLE_SIZE)
#define DDR3_FOFBDECIMIQ1_END_ADDR      (DDR3_FOFBDECIMIQ1_START_ADDR + DDR3_FOFBDECIMIQ1_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBDECIMIQ1_MEM_BOOL*DDR3_FOFBDECIMIQ1_SAMPLE_SIZE)
#define DDR3_FOFBDECIMIQ1_MAX_SAMPLES   ((DDR3_FOFBDECIMIQ1_END_ADDR-DDR3_FOFBDECIMIQ1_START_ADDR) / DDR3_FOFBDECIMIQ1_SAMPLE_SIZE)

/* FOFBDECIM I/Q 3/4 (shares the same memory space as the FOFBDECIMIQ1 and FOFBAMP1)
 * Size: 1 DDR3 regions */
#define DDR3_DUMMY21_SAMPLE_SIZE        FOFBDECIMIQ_SAMPLE_SIZE
#define DDR3_DUMMY21_MEM_SIZE           2

#define DDR3_DUMMY21_MEM_BOOL           DDR3_MEM_BOOL(DDR3_DUMMY21_MEM_SIZE)
#define DDR3_DUMMY21_START_ADDR         (DDR3_TBTPOS1_END_ADDR + DDR3_TBTPOS1_MEM_BOOL*DDR3_TBTPOS1_SAMPLE_SIZE)
#define DDR3_DUMMY21_END_ADDR           (DDR3_DUMMY21_START_ADDR + DDR3_DUMMY21_MEM_SIZE*MEM_REGION_SIZE - DDR3_DUMMY21_MEM_BOOL*DDR3_DUMMY21_SAMPLE_SIZE)
#define DDR3_DUMMY21_MAX_SAMPLES        ((DDR3_DUMMY21_END_ADDR-DDR3_DUMMY21_START_ADDR) / DDR3_DUMMY21_SAMPLE_SIZE)

/* FOFB 1 AMP
 * Size: 2 DDR3 regions */
#define DDR3_FOFBAMP1_SAMPLE_SIZE       FOFBAMP_SAMPLE_SIZE
#define DDR3_FOFBAMP1_MEM_SIZE          2

#define DDR3_FOFBAMP1_MEM_BOOL          DDR3_MEM_BOOL(DDR3_FOFBAMP1_MEM_SIZE)
#define DDR3_FOFBAMP1_START_ADDR        (DDR3_TBTPOS1_END_ADDR + DDR3_TBTPOS1_MEM_BOOL*DDR3_TBTPOS1_SAMPLE_SIZE)
#define DDR3_FOFBAMP1_END_ADDR          (DDR3_FOFBAMP1_START_ADDR + DDR3_FOFBAMP1_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBAMP1_MEM_BOOL*DDR3_FOFBAMP1_SAMPLE_SIZE)
#define DDR3_FOFBAMP1_MAX_SAMPLES       ((DDR3_FOFBAMP1_END_ADDR-DDR3_FOFBAMP1_START_ADDR) / DDR3_FOFBAMP1_SAMPLE_SIZE)

/* FOFB 1 PHA (shares the same memory space as the FOFBDECIMIQ1 and DUMMY21)
 * Size: 2 DDR3 regions */
#define DDR3_FOFBPHA1_SAMPLE_SIZE       FOFBPHA_SAMPLE_SIZE
#define DDR3_FOFBPHA1_MEM_SIZE          2

#define DDR3_FOFBPHA1_MEM_BOOL          DDR3_MEM_BOOL(DDR3_FOFBPHA1_MEM_SIZE)
#define DDR3_FOFBPHA1_START_ADDR        (DDR3_TBTPOS1_END_ADDR + DDR3_TBTPOS1_MEM_BOOL*DDR3_TBTPOS1_SAMPLE_SIZE)
#define DDR3_FOFBPHA1_END_ADDR          (DDR3_FOFBPHA1_START_ADDR + DDR3_FOFBPHA1_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBPHA1_MEM_BOOL*DDR3_FOFBPHA1_SAMPLE_SIZE)
#define DDR3_FOFBPHA1_MAX_SAMPLES       ((DDR3_FOFBPHA1_END_ADDR-DDR3_FOFBPHA1_START_ADDR) / DDR3_FOFBPHA1_SAMPLE_SIZE)

/* FOFB 1 POS
 * Size: 1 DDR3 regions */
#define DDR3_FOFBPOS1_SAMPLE_SIZE       FOFBPOS_SAMPLE_SIZE
#define DDR3_FOFBPOS1_MEM_SIZE          2

#define DDR3_FOFBPOS1_MEM_BOOL          DDR3_MEM_BOOL(DDR3_FOFBPOS1_MEM_SIZE)
#define DDR3_FOFBPOS1_START_ADDR        (DDR3_TBTPOS1_END_ADDR + DDR3_TBTPOS1_MEM_BOOL*DDR3_TBTPOS1_SAMPLE_SIZE)
#define DDR3_FOFBPOS1_END_ADDR          (DDR3_FOFBPOS1_START_ADDR + DDR3_FOFBPOS1_MEM_SIZE*MEM_REGION_SIZE - DDR3_FOFBPOS1_MEM_BOOL*DDR3_FOFBPOS1_SAMPLE_SIZE)
#define DDR3_FOFBPOS1_MAX_SAMPLES       ((DDR3_FOFBPOS1_END_ADDR-DDR3_FOFBPOS1_START_ADDR) / DDR3_FOFBPOS1_SAMPLE_SIZE)

 /* MONIT 1 AMP
 * Size: 1 DDR3 regions */
#define DDR3_MONITAMP1_SAMPLE_SIZE      MONITAMP_SAMPLE_SIZE
#define DDR3_MONITAMP1_MEM_SIZE         0

#define DDR3_MONITAMP1_MEM_BOOL         DDR3_MEM_BOOL(DDR3_MONITAMP1_MEM_SIZE)
#define DDR3_MONITAMP1_START_ADDR       (DDR3_FOFBPOS1_END_ADDR + DDR3_FOFBPOS1_MEM_BOOL*DDR3_FOFBPOS1_SAMPLE_SIZE)
#define DDR3_MONITAMP1_END_ADDR         (DDR3_MONITAMP1_START_ADDR + DDR3_MONITAMP1_MEM_SIZE*MEM_REGION_SIZE - DDR3_MONITAMP1_MEM_BOOL*DDR3_MONITAMP1_SAMPLE_SIZE)
#define DDR3_MONITAMP1_MAX_SAMPLES      ((DDR3_MONITAMP1_END_ADDR-DDR3_MONITAMP1_START_ADDR) / DDR3_MONITAMP1_SAMPLE_SIZE)

/* MONIT 1 POS
 * Size: 1 DDR3 regions */
#define DDR3_MONITPOS1_SAMPLE_SIZE      MONITPOS_SAMPLE_SIZE
#define DDR3_MONITPOS1_MEM_SIZE         0

#define DDR3_MONITPOS1_MEM_BOOL         DDR3_MEM_BOOL(DDR3_MONITPOS1_MEM_SIZE)
#define DDR3_MONITPOS1_START_ADDR       (DDR3_MONITAMP1_END_ADDR + DDR3_MONITAMP1_MEM_BOOL*DDR3_MONITAMP1_SAMPLE_SIZE)
#define DDR3_MONITPOS1_END_ADDR         (DDR3_MONITPOS1_START_ADDR + DDR3_MONITPOS1_MEM_SIZE*MEM_REGION_SIZE - DDR3_MONITPOS1_MEM_BOOL*DDR3_MONITPOS1_SAMPLE_SIZE)
#define DDR3_MONITPOS1_MAX_SAMPLES      ((DDR3_MONITPOS1_END_ADDR-DDR3_MONITPOS1_START_ADDR) / DDR3_MONITPOS1_SAMPLE_SIZE)

/* MONIT1 1 POS
 * Size: 1 DDR3 regions */
#define DDR3_MONIT1POS1_SAMPLE_SIZE     MONIT1POS_SAMPLE_SIZE
#define DDR3_MONIT1POS1_MEM_SIZE        0

#define DDR3_MONIT1POS1_MEM_BOOL        DDR3_MEM_BOOL(DDR3_MONIT1POS1_MEM_SIZE)
#define DDR3_MONIT1POS1_START_ADDR      (DDR3_MONITPOS1_END_ADDR + DDR3_MONITPOS1_MEM_BOOL*DDR3_MONITPOS1_SAMPLE_SIZE)
#define DDR3_MONIT1POS1_END_ADDR        (DDR3_MONIT1POS1_START_ADDR + DDR3_MONIT1POS1_MEM_SIZE*MEM_REGION_SIZE - DDR3_MONIT1POS1_MEM_BOOL*DDR3_MONIT1POS1_SAMPLE_SIZE)
#define DDR3_MONIT1POS1_MAX_SAMPLES     ((DDR3_MONIT1POS1_END_ADDR-DDR3_MONIT1POS1_START_ADDR) / DDR3_MONIT1POS1_SAMPLE_SIZE)

/* End 1 Dummy region
 * Size: 0 DDR3 regions */
#define DDR3_DUMMY_END1_SAMPLE_SIZE     MONIT1POS_SAMPLE_SIZE
#define DDR3_DUMMY_END1_MEM_SIZE        0

#define DDR3_DUMMY_END1_MEM_BOOL        DDR3_MEM_BOOL(DDR3_DUMMY_END1_MEM_SIZE)
#define DDR3_DUMMY_END1_START_ADDR      DDR3_MONIT1POS1_END_ADDR
#define DDR3_DUMMY_END1_END_ADDR        (DDR3_DUMMY_END1_START_ADDR + DDR3_DUMMY_END1_MEM_SIZE*MEM_REGION_SIZE)
#define DDR3_DUMMY_END1_MAX_SAMPLES     (DDR3_DUMMY_END1_END_ADDR-DDR3_DUMMY_END1_START_ADDR)

#endif

