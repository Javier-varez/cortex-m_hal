#ifndef CORTEX_M_HAL_REGISTERS_H_
#define CORTEX_M_HAL_REGISTERS_H_

#include <cstdint>

// Structure for the systick registers
struct SysTickRegs {
  volatile union {
    uint32_t reg;
    struct {
      uint32_t enable : 1;
      uint32_t tickint : 1;
      uint32_t clksource : 1;
      uint32_t : 13;
      uint32_t countflag : 1;
    } bits;
  } CSR;
  volatile union {
    uint32_t reg;
    struct {
      uint32_t rv : 24;
    } bits;
  } RVR;
  volatile union {
    uint32_t reg;
    struct {
      uint32_t cv : 24;
    } bits;
  } CVR;
  volatile union {
    uint32_t reg;
    struct {
      uint32_t cal_value : 24;
      uint32_t : 6;
      uint32_t skew : 1;
      uint32_t noref : 1;
    } bits;
  } CALVR;
};

// Structure for DWT registers
struct DwtWatchPointRegs {
  uint32_t dwt_comp;
  union {
    uint32_t reg;
    struct {
      uint32_t mask : 5;
    } bits;
  } dwt_mask;
  union {
    uint32_t reg;
    struct {
      uint32_t function : 4;
      uint32_t : 1;
      uint32_t emitrange : 1;
      uint32_t : 1;
      uint32_t cycmatch : 1;
      uint32_t datavmatch : 1;
      uint32_t lnk1ena : 1;
      uint32_t datavsize : 2;
      uint32_t datavaddr0 : 4;
      uint32_t datavaddr1 : 4;
      uint32_t : 4;
      uint32_t matched : 1;
    } bits;
  } dwt_function;
  uint32_t reserved;
};

struct DwtRegs {
  uint32_t cont;
  uint32_t cyccnt;
  uint32_t cpicnt;
  uint32_t exccnt;
  uint32_t sleepcnt;
  uint32_t lsucnt;
  uint32_t foldcnt;
  uint32_t pcsr;
  DwtWatchPointRegs watchpoints[4];
};

// System control block registers
struct ScbRegs {
  uint32_t cpuid;
  uint32_t icsr;
  uint32_t vtor;
  uint32_t aircr;
  uint32_t scr;
  uint32_t ccr;
  union {
    uint32_t reg;
    struct {
      uint32_t mem_manage_prio : 8;
      uint32_t bus_fault_prio : 8;
      uint32_t usage_fault_prio : 8;
    } bits;
  } shpr1;
  union {
    uint32_t reg;
    struct {
      uint32_t : 8;
      uint32_t : 8;
      uint32_t : 8;
      uint32_t svc_prio : 8;
    } bits;
  } shpr2;
  union {
    uint32_t reg;
    struct {
      uint32_t debug_monitor_prio : 8;
      uint32_t : 8;
      uint32_t pendsv_prio : 8;
      uint32_t systick_prio : 8;
    } bits;
  } shpr3;
  uint32_t shcsr;
  uint32_t cfsr;
  uint32_t hfsr;
  uint32_t dfsr;
  uint32_t mmfar;
  uint32_t bfar;
  uint32_t afsr;
  uint32_t reserved[18];
  uint32_t cpacr;
};

struct ScbDebugRegs {
  struct Dhcsr {
    uint32_t c_debugen : 1;
    uint32_t c_halt : 1;
    uint32_t c_step : 1;
    uint32_t c_maskints : 1;
    uint32_t : 1;
    uint32_t c_snapstall : 1;
    uint32_t : 10;
    uint32_t s_regrdy : 1;
    uint32_t s_halt : 1;
    uint32_t s_sleep : 1;
    uint32_t s_lockup : 1;
    uint32_t : 4;
    uint32_t s_retire_st : 1;
    uint32_t s_reset_st : 1;
  } dhcsr;
  uint32_t dcsrs;
  uint32_t dcrdr;
  union {
    uint32_t reg;
    struct {
      uint32_t vc_corereset : 1;
      uint32_t : 3;
      uint32_t vc_mmerr : 1;
      uint32_t vc_nocperr : 1;
      uint32_t vc_chkerr : 1;
      uint32_t vc_staterr : 1;
      uint32_t vc_buserr : 1;
      uint32_t vc_interr : 1;
      uint32_t vc_harderr : 1;
      uint32_t : 5;
      uint32_t mon_en : 1;
      uint32_t mon_pend : 1;
      uint32_t mon_step : 1;
      uint32_t mon_req : 1;
      uint32_t : 4;
      uint32_t trcena : 1;
    } bits;
  } demcr;
};

#endif  // CORTEX_M_HAL_REGISTERS_H_
