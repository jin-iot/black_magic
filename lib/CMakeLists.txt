include(cmake/build_options.cmake)
include(cmake/autogen.cmake)

set(SENTIENT_C_LIBRARY_SRC
    core/types.c
    core/checksum_types.c
    core/object_pool.c
    core/model_info.c
    core/internal/object_pool_internal.c)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(sentient ${SENTIENT_C_LIBRARY_SRC})
target_include_directories(sentient PRIVATE
    ${CMAKE_BINARY_DIR}/generated/include)