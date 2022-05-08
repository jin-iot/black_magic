include(cmake/autogen.cmake)

set(SENTIENT_C_LIBRARY_SRC
    core/types.c
    core/checksum_types.c
    core/pool_alloc.c
    core/model_info.c)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(sentient ${SENTIENT_C_LIBRARY_SRC})
target_include_directories(sentient PRIVATE
    ${CMAKE_BINARY_DIR}/generated/include)