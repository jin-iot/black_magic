cmake_minimum_required(VERSION 3.20)
project(black_magic C)

set(SENTIENT_C_AUTOGEN_DIR
    ${CMAKE_BINARY_DIR}/generated/include/sentient)

set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_get_n.h)
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_iterations.h)

set(SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS 128)

##################
### pp_get_n.h ###
##################
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    set(TMP_SRC "")
    foreach (SENTIENT_LOOP_VAR_J RANGE 0 ${SENTIENT_LOOP_VAR} 1)
        set(TMP_SRC "${TMP_SRC} _${SENTIENT_LOOP_VAR_J},")
    endforeach()

    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH}
               "#define ___sentient_pp_get_${SENTIENT_LOOP_VAR}(${TMP_SRC} ...) _${SENTIENT_LOOP_VAR}"
               APPEND)
endforeach()

#######################
### pp_iterations.h ###
#######################

# ___sentient_pp_foreach
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH}
                   "#define ___sentient_pp_foreach_${SENTIENT_LOOP_VAR}(...)")
    else()
        math(EXPR PREVIOUS_COUNT_VAR "${SENTIENT_LOOP_VAR}-1")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH}
                   "#define ___sentient_pp_foreach_${SENTIENT_LOOP_VAR}(expr, arg, ...) "
                   "expr(arg) ___sentient_pp_foreach_${PREVIOUS_COUNT_VAR}(expr, __VA_ARGS__)" APPEND)
    endif()
endforeach()

# ___sentient_pp_args
set(SENTIENT_PP_ARGS_SRC "#define ___sentient_pp_args(")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH} "" APPEND)
foreach (SENTIENT_LOOP_VAR RANGE 1 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    set(SENTIENT_PP_ARGS_SRC "${SENTIENT_PP_ARGS_SRC}_${SENTIENT_LOOP_VAR}, ")
endforeach()
set(SENTIENT_PP_ARGS_SRC "${SENTIENT_PP_ARGS_SRC}...) _${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS}\n")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH} ${SENTIENT_PP_ARGS_SRC} APPEND)

#___sentient_pp_count_args
set(SENTIENT_PP_COUNT_ARGS_SRC "#define ___sentient_pp_count_args(...) \\\n"
                               "        ___sentient_pp_count_args_impl(0, ## __VA_ARGS__)\n"
                               "#define ___sentient_pp_count_args_impl(...) \\\n"
                               "        ___sentient_pp_args(__VA_ARGS__, ")
math(EXPR SENTIENT_COUNT_ARGS_START "${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS}-2")
foreach (SENTIENT_LOOP_VAR RANGE ${SENTIENT_COUNT_ARGS_START} 0 -1)
    set(SENTIENT_PP_COUNT_ARGS_SRC "${SENTIENT_PP_COUNT_ARGS_SRC}${SENTIENT_LOOP_VAR}, ")
endforeach()
set(SENTIENT_PP_COUNT_ARGS_SRC "${SENTIENT_PP_COUNT_ARGS_SRC})\n")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ITERATIONS_H_PATH} ${SENTIENT_PP_COUNT_ARGS_SRC} APPEND)


include_directories(${CMAKE_INCLUDE_PATH}
                    ${CMAKE_BINARY_DIR}/generated/include)

add_executable(black_magic main.c)