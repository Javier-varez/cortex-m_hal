
#ifndef HAL_SYSTICK_H_
#define HAL_SYSTICK_H_

#include <cstdint>

extern "C" void SysTick_Handler();

class SysTick {
 public:
  class Listener {
   public:
    virtual void tickTock(std::uint32_t ticks) = 0;
    virtual ~Listener() = default;
  };

  constexpr static uint32_t TICKS_PER_SECOND = 1000;

  void init(uint32_t core_clk_mhz);

  uint64_t getTickCount();
  uint32_t getFineTickCount();
  uint32_t getCoarseTickCount() { return m_ticks; }
  void delay(uint32_t coarse_ticks);

  void set_listener(Listener* listener) { m_listener = listener; }

  static SysTick& getInstance() {
    static SysTick systick;
    return systick;
  }

 private:
  volatile uint32_t m_ticks{0};
  uint32_t m_max_count = 0;
  Listener* m_listener = nullptr;

  SysTick() = default;

  void handleIrq();

  friend void ::SysTick_Handler();
};

#endif  // HAL_SYSTICK_H_
