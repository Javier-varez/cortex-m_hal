
#include "cortex_m_hal/systick.h"

#include "cortex_m_hal/registers.h"

static __attribute__((section(".systick_regs"))) SysTickRegs s_systick_regs;

extern "C" void SysTick_Handler() { SysTick::getInstance().handleIrq(); }

void SysTick::init(uint32_t core_clk_hz) {
  m_ticks = 0;
  s_systick_regs.CSR.bits.enable = false;

  m_max_count = core_clk_hz / TICKS_PER_SECOND;
  const uint32_t reload_value = m_max_count - 1;
  s_systick_regs.RVR.bits.rv = reload_value;

  s_systick_regs.CSR.bits.clksource = true;
  s_systick_regs.CSR.bits.tickint = true;
  s_systick_regs.CSR.bits.enable = true;
}

uint64_t SysTick::getTickCount() {
  uint32_t coarse = getCoarseTickCount();
  uint32_t fine = getFineTickCount();

  if ((coarse != getCoarseTickCount()) && (fine < (m_max_count / 2))) {
    coarse = getCoarseTickCount();
  }

  return static_cast<uint64_t>(m_max_count) * coarse + fine;
}

uint32_t SysTick::getFineTickCount() {
  return m_max_count - s_systick_regs.CVR.reg - 1;
}

void SysTick::delay(uint32_t coarse_ticks) {
  const uint32_t start = m_ticks;
  while ((m_ticks - start) < coarse_ticks) {
  }
}

void SysTick::handleIrq() {
  m_ticks++;
  if (m_listener) {
    m_listener->tickTock(m_ticks);
  }
}
