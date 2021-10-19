cmake_minimum_required(VERSION 3.16)

project(Cortex-M_hal)

add_library(cortex-m_hal STATIC
  src/dwt.cpp
  src/systick.cpp)

target_compile_features(cortex-m_hal
  PUBLIC
    cxx_std_20)

target_compile_options(cortex-m_hal
  PRIVATE
    -Wall
    -Wextra
    -Werror)

target_include_directories(cortex-m_hal
  PUBLIC
    inc)
target_compile_options(cortex-m_hal
  PRIVATE
    -Os)
target_link_options(cortex-m_hal
  INTERFACE
    "SHELL:-Wl,-T ${CMAKE_CURRENT_SOURCE_DIR}/cortex_m_hal.ld")
set_target_properties(cortex-m_hal
  PROPERTIES
  INTERFACE_LINK_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/cortex_m_hal.ld)
