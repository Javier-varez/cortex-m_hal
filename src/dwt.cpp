
#include "cortex_m_hal/dwt.h"

#include "cortex_m_hal/registers.h"

volatile DwtRegs s_dwt_regs __attribute__((section(".dwt_regs")));
volatile ScbRegs s_scb_regs __attribute__((section(".scb_regs")));
volatile ScbDebugRegs s_scb_debug_regs
    __attribute__((section(".scb_debug_regs")));

static Dwt* s_dwt = nullptr;

extern "C" void DebugMonHandlerHL(void* sp) { s_dwt->DebugMonitorIsr(sp); }

extern "C" __attribute__((naked)) void DebugMon_Handler() {
#ifdef ARMV7_ARCH
  asm volatile(
      "tst lr, #4 \n"
      "ite eq \n"
      "mrseq r0, msp \n"
      "mrsne r0, psp \n"
      "b DebugMonHandlerHL \n");
#elif ARMV6_ARCH
  asm volatile(
      "movs r0, #4 \n"
      "mov r1, lr \n"
      "tst r0, r1 \n"
      "beq USE_MSP \n"
      "mrs r0, psp \n"
      "b DebugMonHandlerHL \n"
      "USE_MSP: \n"
      "mrs r0, msp \n"
      "b DebugMonHandlerHL \n");
#else
#error("Invalid architecture selected.")
#endif
}

Dwt::Dwt() { s_dwt = this; }

Dwt::~Dwt() { s_dwt = nullptr; }

void Dwt::DebugMonitorIsr(void* sp) {
  for (uint32_t i = 0; i < MAX_COMPARATORS; i++) {
    if ((s_dwt_regs.watchpoints[i].dwt_function.bits.matched) &&
        (m_callbacks[i] != nullptr)) {
      m_callbacks[i]->WatchpointTriggered(i, sp);
    }
  }
}

void Dwt::SetWatchPoint(uint32_t id, Params params, Callback* cb) {
  s_dwt_regs.watchpoints[id].dwt_comp =
      reinterpret_cast<uint32_t>(params.address);
  s_dwt_regs.watchpoints[id].dwt_mask.bits.mask = params.number_of_bits;
  s_dwt_regs.watchpoints[id].dwt_function.bits.function =
      static_cast<uint32_t>(params.access_type);

  m_callbacks[id] = cb;
}

bool Dwt::Init() {
  if (s_scb_debug_regs.dhcsr.c_debugen) {
    return false;
  }

  s_scb_debug_regs.demcr.bits.mon_en = 1;
  s_scb_debug_regs.demcr.bits.trcena = 1;

  s_scb_regs.shpr3.bits.debug_monitor_prio = 0xff;

  return true;
}
