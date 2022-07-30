#ifndef CORTEX_M_HAL_CORE_H_
#define CORTEX_M_HAL_CORE_H_

namespace CortexMHal {

/**
 * @brief halts execution of the core in an infinite loop
 *
 * Prefer using this function over infinite loops with no visible side-effects,
 * which trigger undefinided behavior in both C and C++
 */
[[noreturn]] void halt() noexcept;

}  // namespace CortexMHal

#endif  // CORTEX_M_HAL_CORE_H_
