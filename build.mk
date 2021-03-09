LOCAL_DIR := $(call current-dir)

include $(CLEAR_VARS)
LOCAL_NAME := cortex_m_hal
LOCAL_CFLAGS := \
    -mcpu=cortex-m3 \
    -mfloat-abi=soft \
    -mthumb \
    -I$(LOCAL_DIR)/inc \
    -Os \
    -g3 \
    -Wall \
    -Werror \
    -Wextra \
    -Wpedantic \
    -ffunction-sections \
    -fdata-sections
LOCAL_CXXFLAGS := \
    $(LOCAL_CFLAGS) \
    -std=gnu++17 \
    -fno-exceptions \
    -fno-rtti
LOCAL_SRC := \
    $(LOCAL_DIR)/src/systick.cpp
LOCAL_ARM_ARCHITECTURE := v7-m
LOCAL_ARM_FPU := nofp
LOCAL_COMPILER := arm_clang
LOCAL_ARFLAGS := -rcs
LOCAL_EXPORTED_DIRS := \
    $(LOCAL_DIR)/inc
LOCAL_LINKER_FILE := \
    $(LOCAL_DIR)/cortex_m_hal.ld
include $(BUILD_STATIC_LIB)

