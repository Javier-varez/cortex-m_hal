
#include <array>
#include <cstdint>

extern "C" void DebugMonHandlerHL(void* sp);

class Dwt {
 public:
  enum class AccessType : uint32_t { RO = 5, WO, RW };

  struct Params {
    void* address;
    AccessType access_type;
    uint8_t number_of_bits;
  };

  class Callback {
   public:
    virtual ~Callback() = default;
    virtual void WatchpointTriggered(uint8_t watchpoint_index,
                                     void* stack_ptr) = 0;
  };

  Dwt();
  ~Dwt();
  auto Init() -> bool;
  void SetWatchPoint(uint32_t id, Params params, Callback* cb);
  void ClearWatchPoint(uint32_t id);

  constexpr static uint32_t MAX_COMPARATORS = 4;

 private:
  std::array<Callback*, MAX_COMPARATORS> m_callbacks{
      nullptr,
      nullptr,
      nullptr,
      nullptr,
  };

  void DebugMonitorIsr(void* sp);
  friend void ::DebugMonHandlerHL(void*);
};
