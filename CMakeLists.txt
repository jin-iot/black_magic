cmake_minimum_required(VERSION 3.20)
project(black_magic C)

set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH
${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_iterations.h)


add_subdirectory(lib)

include_directories(${CMAKE_INCLUDE_PATH}
                    include
                    ${CMAKE_BINARY_DIR}/generated/include)

add_executable(black_magic main.c)
target_link_libraries(black_magic sentient)