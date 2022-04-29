cmake_minimum_required(VERSION 3.20)
project(black_magic C)

set(SENTIENT_C_AUTOGEN_DIR
    ${CMAKE_BINARY_DIR}/generated/include/sentient)

set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_get_n.h)

write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 127 1)
    set(TMP_SRC "")
    foreach (SENTIENT_LOOP_VAR_J RANGE 0 ${SENTIENT_LOOP_VAR} 1)
        set(TMP_SRC "${TMP_SRC} _${SENTIENT_LOOP_VAR_J},")
    endforeach()

    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH}
               "#define pp_get_${SENTIENT_LOOP_VAR}(${TMP_SRC} ...) _${SENTIENT_LOOP_VAR}"
               APPEND)
endforeach()

include_directories(${CMAKE_INCLUDE_PATH}
                    ${CMAKE_BINARY_DIR}/generated/include)

add_executable(black_magic main.c  metaresc.c  mr_btree.c  mr_extra.c  mr_hsort.c  mr_ic.c mr_message.c  mr_save.c  mr_stringify.c)