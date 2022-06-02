#     _         _                        _   _      _             
#    / \  _   _| |_ ___  _ __ ___   __ _| |_(_) ___| |_   _       
#   / _ \| | | | __/ _ \| '_ ` _ \ / _` | __| |/ __| | | | |_____ 
#  / ___ \ |_| | || (_) | | | | | | (_| | |_| | (__| | |_| |_____|
# /_/   \_\__,_|\__\___/|_| |_| |_|\__,_|\__|_|\___|_|\__, |      
#                                                      |___/
#         ____                           _           _ 
#        / ___| ___ _ __   ___ _ __ __ _| |_ ___  __| |
#       | |  _ / _ \ '_ \ / _ \ '__/ _` | __/ _ \/ _` |
#       | |_| |  __/ | | |  __/ | | (_| | ||  __/ (_| |
#        \____|\___|_| |_|\___|_|  \__,_|\__\___|\__,_|
#
#              ____                                
#             / ___|  ___  _   _ _ __ ___ ___  ___ 
#             \___ \ / _ \| | | | '__/ __/ _ \/ __|
#              ___) | (_) | |_| | | | (_|  __/\__ \
#             |____/ \___/ \__,_|_|  \___\___||___/
#             
#

find_package(PythonInterp REQUIRED)

set(SENTIENT_C_AUTOGEN_DIR
    ${CMAKE_BINARY_DIR}/generated/include/sentient)

#########################
### snt_config.h ###
#########################
set(SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/snt_config.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#ifndef __SENTIENT_CORE_SENTIENT_CONFIG_H__\n"
           "#define __SENTIENT_CORE_SENTIENT_CONFIG_H__\n\n"
           "#ifdef __cplusplus\n"
           "extern \"C\"\n"
           "{\n"
           "#endif\n\n")
if(SENTIENT_C_USE_POOL)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_USE_POOL\n\n"
           APPEND)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_NUM_POOL_LOOP ${SENTIENT_C_NUM_POOL_LOOP}\n"
           APPEND)
endif()
if(SENTIENT_C_USE_OS)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_USE_OS\n\n"
           APPEND)
endif()
if(SENTIENT_C_OS_POSIX)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_OS_POSIX\n\n"
           APPEND)
endif()
if(SENTIENT_C_OS_ZEPHYR)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_OS_ZEPHYR\n\n"
           APPEND)
endif()
if(SENTIENT_C_OS_RIOT)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_OS_RIOT\n\n"
           APPEND)
endif()
if(SENTIENT_C_OS_MYNEWT)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_OS_MYNEWT\n\n"
           APPEND)
endif()
if(SENTIENT_C_OS_MIPOS)
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#define SENTIENT_C_OS_MIPOS\n\n"
           APPEND)
endif()
write_file(${SENTIENT_C_AUTOGEN_CORE_SENTIENT_CONFIG_H_PATH}
           "#ifdef __cplusplus\n"
           "extern \"C\"\n"
           "{\n"
           "#endif\n\n"
           "#endif"
           APPEND)

######################
### string_types.h ###
######################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_STRING_TYPES_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/string_types.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_STRING_TYPES_H_PATH} "")
foreach(SENTIENT_LOOP_VAR RANGE 1 4096 1)
    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_STRING_TYPES_H_PATH}
               "typedef snt_str8 snt_str8_${SENTIENT_LOOP_VAR}"
               "[${SENTIENT_LOOP_VAR}];"
               APPEND)
endforeach()

set(SENTIENT_C_AUTOGEN_CORE_TYPES
    snt_u32
    snt_u64
    snt_i32
    snt_i64
    snt_f32
    snt_f64)

###################
### vec_types.h ###
###################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_VEC_TYPES_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/vec_types.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_VEC_TYPES_H_PATH} "")
foreach(SENTIENT_LOOP_VAR_TYPE
        IN LISTS
        SENTIENT_C_AUTOGEN_CORE_TYPES)
    foreach(SENTIENT_LOOP_VAR RANGE 1 4 1)
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_VEC_TYPES_H_PATH}
        "typedef ${SENTIENT_LOOP_VAR_TYPE} ${SENTIENT_LOOP_VAR_TYPE}_"
        "vec${SENTIENT_LOOP_VAR}"
        "[${SENTIENT_LOOP_VAR}];"
        APPEND)
    endforeach()
endforeach()
    
###################
### mat_types.h ###
###################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_MAT_TYPES_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/mat_types.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_MAT_TYPES_H_PATH} "")
foreach(SENTIENT_LOOP_VAR_TYPE
        IN LISTS
        SENTIENT_C_AUTOGEN_CORE_TYPES)
    foreach(SENTIENT_LOOP_VAR_X RANGE 1 4 1)
        foreach(SENTIENT_LOOP_VAR_Y RANGE 1 4 1)
            write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_MAT_TYPES_H_PATH}
            "typedef ${SENTIENT_LOOP_VAR_TYPE} ${SENTIENT_LOOP_VAR_TYPE}_"
            "mat${SENTIENT_LOOP_VAR_X}x${SENTIENT_LOOP_VAR_Y}"
            "[${SENTIENT_LOOP_VAR_X}][${SENTIENT_LOOP_VAR_Y}];"
            APPEND)
        endforeach()
    endforeach()
endforeach()

######################
### pp_compare_n.h ###
######################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_COMPARE_N_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_compare_n.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_COMPARE_N_H_PATH} "")
foreach(SENTIENT_LOOP_VAR RANGE 0 65536 1)
    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_COMPARE_N_H_PATH}
                "#define ___SNT_PP_COMPARE_${SENTIENT_LOOP_VAR}(x) x"
                APPEND)
endforeach()

####################
### pp_inc_dec.h ###
####################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_INC_DEC_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_inc_dec.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_INC_DEC_H_PATH} "")
foreach(SENTIENT_LOOP_VAR RANGE 0 2048 1)
    set(TMP_INC "")
    if (${SENTIENT_LOOP_VAR} EQUAL "2048")
        set(TMP_INC ${SENTIENT_LOOP_VAR})
    else()
        math(EXPR TMP_INC "${SENTIENT_LOOP_VAR}+1")
    endif()
    
    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_INC_DEC_H_PATH}
                "#define ___SNT_PP_INCREASE_IMPL_${SENTIENT_LOOP_VAR} ${TMP_INC}"
                APPEND)
endforeach()
foreach(SENTIENT_LOOP_VAR RANGE 0 2048 1)
    set(TMP_INC "")
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        set(TMP_INC ${SENTIENT_LOOP_VAR})
    else()
        math(EXPR TMP_INC "${SENTIENT_LOOP_VAR}-1")
    endif()
    
    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_INC_DEC_H_PATH}
                "#define ___SNT_PP_DECREASE_IMPL_${SENTIENT_LOOP_VAR} ${TMP_INC}"
                APPEND)
endforeach()

set(SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS 128)

####################
### pp_arithmetic.h ###
####################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_arithmetic.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_H_PATH} "")
set(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_SRC} "")
exec_program(${PYTHON_EXECUTABLE} ${CMAKE_BINARY_DIR}
             ARGS "${CMAKE_CURRENT_SOURCE_DIR}/cmake/gen_arithmetic.py "
                  "${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_H_PATH} "
                  "64")
# foreach(SENTIENT_LOOP_I RANGE 0 64 1)
#     foreach(SENTIENT_LOOP_J RANGE 0 64 1)
#         # set(EVAL_RES "")
#         # math(EXPR EVAL_RES "${SENTIENT_LOOP_I}+${SENTIENT_LOOP_J}")

#         # set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_SRC
#         #     "${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_SRC}"
#         #     "#define ___snt_pp_add_impl_${SENTIENT_LOOP_I}_${SENTIENT_LOOP_J} ${EVAL_RES}\n")
#     endforeach()
# endforeach()
# write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_H_PATH}
#             ${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARITHMETIC_SRC})

##################
### pp_get_n.h ###
##################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_get_n.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    set(TMP_SRC "")
    foreach (SENTIENT_LOOP_VAR_J RANGE 0 ${SENTIENT_LOOP_VAR} 1)
        set(TMP_SRC "${TMP_SRC} _${SENTIENT_LOOP_VAR_J},")
    endforeach()

    write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_GET_N_H_PATH}
               "#define ___SNT_PP_GET_${SENTIENT_LOOP_VAR}(${TMP_SRC} ...) _${SENTIENT_LOOP_VAR}"
               APPEND)
endforeach()

##################
### pp_defer.h ###
##################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_DEFER_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_defer.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_DEFER_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_DEFER_H_PATH}
                    "#define ___SNT_PP_DEFER_${SENTIENT_LOOP_VAR}(...) __VA_ARGS__")
    else()
        math(EXPR PREVIOUS_COUNT_VAR "${SENTIENT_LOOP_VAR}-1")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_DEFER_H_PATH}
                    "#define ___SNT_PP_DEFER_${SENTIENT_LOOP_VAR}(...) "
                    "__VA_ARGS__ ___SNT_PP_DEFER_${PREVIOUS_COUNT_VAR}(___SNT_PP_EMPTY) ()" APPEND)
    endif()
endforeach()

####################
### pp_eval.h ###
####################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_EVAL_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_eval.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_EVAL_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_EVAL_H_PATH}
                    "#define ___SNT_PP_EVAL_${SENTIENT_LOOP_VAR}(...) __VA_ARGS__")
    else()
        math(EXPR PREVIOUS_COUNT_VAR "${SENTIENT_LOOP_VAR}-1")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_EVAL_H_PATH}
                    "#define ___SNT_PP_EVAL_${SENTIENT_LOOP_VAR}(...) "
                    "___SNT_PP_EVAL_${PREVIOUS_COUNT_VAR}(___SNT_PP_EVAL_${PREVIOUS_COUNT_VAR}(__VA_ARGS__))" APPEND)
    endif()
endforeach()

####################
### pp_foreach.h ###
####################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOREACH_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_foreach.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOREACH_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOREACH_H_PATH}
                    "#define ___SNT_PP_FOREACH_${SENTIENT_LOOP_VAR}(...)")
    else()
        math(EXPR PREVIOUS_COUNT_VAR "${SENTIENT_LOOP_VAR}-1")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOREACH_H_PATH}
                    "#define ___SNT_PP_FOREACH_${SENTIENT_LOOP_VAR}(EXPR, ARG, ...) "
                    "EXPR(ARG) ___SNT_PP_FOREACH_${PREVIOUS_COUNT_VAR}(EXPR, __VA_ARGS__)" APPEND)
    endif()
endforeach()

####################
### pp_for.h ###
####################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOR_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_for.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOR_H_PATH} "")
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOR_H_PATH}
                    "#define ___SNT_PP_FOR_INCREASE_${SENTIENT_LOOP_VAR}(IDX, EXPR, ...)\n")
    else()
        math(EXPR PREVIOUS_COUNT_VAR "${SENTIENT_LOOP_VAR}-1")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOR_H_PATH}
                    "#define ___SNT_PP_FOR_INCREASE_${SENTIENT_LOOP_VAR}(IDX, EXPR, ...) \\\n"
                    "        EXPR (IDX, __VA_ARGS__)                        \\\n"
                    "        ___SNT_PP_FOR_INCREASE_${PREVIOUS_COUNT_VAR}(                \\\n"
                    "            ___SNT_PP_INCREASE(IDX),             \\\n"
                    "                EXPR,                                 \\\n"
                    "                __VA_ARGS__                           \\\n"
                    "        )"
                    APPEND)
    endif()
endforeach()
foreach (SENTIENT_LOOP_VAR RANGE 0 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    if (${SENTIENT_LOOP_VAR} EQUAL "0")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOR_H_PATH}
                    "#define ___SNT_PP_FOR_DECREASE_${SENTIENT_LOOP_VAR}(IDX, EXPR, ...)\n" APPEND)
    else()
        math(EXPR PREVIOUS_COUNT_VAR "${SENTIENT_LOOP_VAR}-1")
        write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_FOR_H_PATH}
                    "#define ___SNT_PP_FOR_DECREASE_${SENTIENT_LOOP_VAR}(IDX, EXPR, ...) \\\n"
                    "        EXPR (IDX, __VA_ARGS__)                        \\\n"
                    "        ___SNT_PP_FOR_DECREASE_${PREVIOUS_COUNT_VAR}(                \\\n"
                    "            ___SNT_PP_DECREASE(idx),             \\\n"
                    "                EXPR,                                 \\\n"
                    "                __VA_ARGS__                           \\\n"
                    "        )"
                    APPEND)
    endif()
endforeach()

#################
### pp_args.h ###
#################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARGS_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_args.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARGS_H_PATH} "")
set(SENTIENT_PP_ARGS_SRC "#define ___SNT_PP_ARGS(")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARGS_H_PATH} "" APPEND)
foreach (SENTIENT_LOOP_VAR RANGE 1 ${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS} 1)
    set(SENTIENT_PP_ARGS_SRC "${SENTIENT_PP_ARGS_SRC} \\\n                            "
                             "_${SENTIENT_LOOP_VAR},")
endforeach()
set(SENTIENT_PP_ARGS_SRC "${SENTIENT_PP_ARGS_SRC}...) _${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS}\n")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_ARGS_H_PATH} ${SENTIENT_PP_ARGS_SRC} APPEND)

#######################
### pp_count_args.h ###
#######################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_COUNT_ARGS_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_count_args.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_COUNT_ARGS_H_PATH} "")
set(SENTIENT_PP_COUNT_ARGS_SRC "#define ___SNT_PP_COUNT_ARGS_IMPL(...) \\\n"
                               "        ___SNT_PP_ARGS(__VA_ARGS__, ")
math(EXPR SENTIENT_COUNT_ARGS_START "${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS}-2")
foreach (SENTIENT_LOOP_VAR RANGE ${SENTIENT_COUNT_ARGS_START} 0 -1)
    set(SENTIENT_PP_COUNT_ARGS_SRC "${SENTIENT_PP_COUNT_ARGS_SRC} \\\n                            "
                                   "${SENTIENT_LOOP_VAR}, ")
endforeach()
set(SENTIENT_PP_COUNT_ARGS_SRC "${SENTIENT_PP_COUNT_ARGS_SRC})\n")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_COUNT_ARGS_H_PATH} ${SENTIENT_PP_COUNT_ARGS_SRC} APPEND)

######################
### pp_has_comma.h ###
######################
set(SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_HAS_COMMA_H_PATH
    ${SENTIENT_C_AUTOGEN_DIR}/core/internal/pp_has_comma.h)
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_HAS_COMMA_H_PATH} "")
set(SENTIENT_PP_HAS_COMMA_SRC "#define ___SNT_PP_HAS_COMMA_IMPL(...) \\\n"
                               "        ___SNT_PP_ARGS(__VA_ARGS__, ")
math(EXPR SENTIENT_HAS_COMMA_ARGS_COUNT "${SENTIENT_C_AUTOGEN_MAX_NUM_ITERATIONS}-3")
foreach (SENTIENT_LOOP_VAR RANGE ${SENTIENT_HAS_COMMA_ARGS_COUNT} 0 -1)
    set(SENTIENT_PP_HAS_COMMA_SRC "${SENTIENT_PP_HAS_COMMA_SRC} \\\n                            "
                                   "1, ")
endforeach()
set(SENTIENT_PP_HAS_COMMA_SRC "${SENTIENT_PP_HAS_COMMA_SRC} "
                              "\\\n                            0)")
write_file(${SENTIENT_C_AUTOGEN_CORE_INTERNAL_PP_HAS_COMMA_H_PATH} ${SENTIENT_PP_HAS_COMMA_SRC} APPEND)