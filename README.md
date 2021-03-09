# Cortex-M HAL

Hardware abstraction layer for Cortex-M microcontrollers. Can be used together with [builsystem](https://github.com/Javier-varez/buildsystem).

## Table of Contents

- [Getting Started](#getting-started)
  - [Dependencies](#dependencies)
  - [Getting the Source](#getting-the-source)
  - [Versioning](#versioning)
- [How to Get Help](#how-to-get-help)
- [Contributing](#contributing)
- [License](#license)
- [Authors](#authors)
- [Acknowledgments](#acknowledgments)

# Getting Started

  * Link the `libcortex_m_hal` library in your project.

```Makefile
LOCAL_DIR := $(call current-dir)

include $(CLEAR_VARS)
LOCAL_NAME := user_application

LOCAL_CFLAGS := \
    $(TARGET_CFLAGS) \
    -Os \
    -g3 \
    -I$(LOCAL_DIR)/inc \
    -Wall \
    -Werror \
    -Wextra

LOCAL_CXXFLAGS := \
    $(LOCAL_CFLAGS) \
    -fno-exceptions \
    -fno-rtti

LOCAL_SRC := \
    $(USER_SOURCES)

# The linker file for the application must define
# the memory layout as a minimum.
LOCAL_LINKER_FILE := \
    $(LOCAL_DIR)/memory.ld

# Link agains the libcortex_m_hal
LOCAL_STATIC_LIBS := \
    libcortex_m_hal

# Compiler settings
CC := gcc
CXX := g++
LOCAL_CROSS_COMPILE := arm-none-eabi-
include $(BUILD_BINARY)
```

**[Back to top](#table-of-contents)**

## Dependencies

This project relies on a custom build system based on a non-recursive set of makefile templates. You can find a link to it [here](https://github.com/Javier-varez/buildsystem). See the list of dependencies for the buildsystem [here](https://github.com/Javier-varez/buildsystem#dependencies).

## Getting the Source

This project is [hosted on GitHub](https://github.com/Javier-varez/cortex-m_hal). You can clone this project directly using this command:

```bash
git clone git@github.com:Javier-varez/cortex-m_hal.git
```

**[Back to top](#table-of-contents)**

## Versioning

This project uses [Semantic Versioning](http://semver.org/). Releases will be tagged.

**[Back to top](#table-of-contents)**

# How to Get Help

Feel free to reach out and open an issue if you need any help getting up and running.

**[Back to top](#table-of-contents)**

# Contributing

Public contributions are very welcome and appreciated.

**[Back to top](#table-of-contents)**

# License

This project is licensed under the MIT License - see [LICENSE.md](LICENSE.md) file for details.

**[Back to top](#table-of-contents)**

# Authors

* **[Javier Alvarez](https://github.com/Javier-varez)** - *Initial work* - [AllThingsEmbedded](https://allthingsembedded.net/)

See also the list of [contributors](https://github.com/Javier-varez/cortex-m_startup/graphs/contributors) who participated in this project.

**[Back to top](#table-of-contents)**

