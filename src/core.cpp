#include "cortex_m_hal/core.h"

namespace CortexMHal {

[[noreturn, gnu::naked]] void halt() noexcept { asm volatile("b .\n"); }

}  // namespace CortexMHal
