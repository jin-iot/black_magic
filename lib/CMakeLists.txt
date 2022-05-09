include(cmake/autogen.cmake)

option(SENTIENT_C_USE_OS "using OS/RTOS in sentient" ON)

if (SENTIENT_C_USE_OS)
option(SENTIENT_C_OS_POSIX "using POSIX" ON)
option(SENTIENT_C_OS_ZEPHYR "using Zephyr RTOS" OFF)
option(SENTIENT_C_OS_RIOT "using RIOT" OFF)
option(SENTIENT_C_OS_MIPOS "using MIPOS" OFF)
endif()

if (SENTIENT_C_USE_OS)
    if (SENTIENT_C_OS_POSIX)
        set(SENTIENT_C_OS_ZEPHYR OFF)
        set(SENTIENT_C_OS_RIOT OFF)
        set(SENTIENT_C_OS_MIPOS OFF)
    endif()
    if (SENTIENT_C_OS_ZEPHYR)
        set(SENTIENT_C_OS_POSIX OFF)
        set(SENTIENT_C_OS_RIOT OFF)
        set(SENTIENT_C_OS_MIPOS OFF)
    endif()
    if (SENTIENT_C_OS_RIOT)
        set(SENTIENT_C_OS_POSIX OFF)
        set(SENTIENT_C_OS_ZEPHYR OFF)
        set(SENTIENT_C_OS_MIPOS OFF)
    endif()
    if (SENTIENT_C_OS_MIPOS)
        set(SENTIENT_C_OS_POSIX OFF)
        set(SENTIENT_C_OS_ZEPHYR OFF)
        set(SENTIENT_C_OS_RIOT OFF)
    endif()

endif()

set(SENTIENT_C_LIBRARY_SRC
    core/os_wrap.c
    core/types.c
    core/checksum_types.c
    core/pool.c
    core/model_info.c)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(sentient ${SENTIENT_C_LIBRARY_SRC})
target_include_directories(sentient PRIVATE
    ${CMAKE_BINARY_DIR}/generated/include)