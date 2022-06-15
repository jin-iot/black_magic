#ifndef __SENTIENT_CORE_INTERNAL_BUILTIN_TYPES_H__
#define __SENTIENT_CORE_INTERNAL_BUILTIN_TYPES_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SNT_DECL_BUILTIN_TYPES() \
        SNT_DECL_BUILTIN_TYPES_IMPL()
#define SNT_DECL_BUILTIN_TYPES_IMPL() \
        ___SNT_PP_DECL_BUILTIN_TYPES()

#define ___SNT_PP_DECL_BUILTIN_TYPES() \
        ___SNT_PP_DECL_BUILTIN_TYPES_IMPL()
#define ___SNT_PP_DECL_BUILTIN_TYPES_IMPL()       \
        ___SNT_PP_FOREACH(                        \
            ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER, \
            (snt_u8, SNT_PRIMITIVE),              \
            (snt_u16, SNT_PRIMITIVE),             \
            (snt_u32, SNT_PRIMITIVE),             \
            (snt_u64, SNT_PRIMITIVE),             \
            (snt_i8, SNT_PRIMITIVE),              \
            (snt_i16, SNT_PRIMITIVE),             \
            (snt_i32, SNT_PRIMITIVE),             \
            (snt_i64, SNT_PRIMITIVE),             \
            (snt_f32, SNT_PRIMITIVE),             \
            (snt_f64, SNT_PRIMITIVE),             \
            (snt_str8, SNT_PRIMITIVE),            \
            (snt_str16, SNT_PRIMITIVE),           \
            (snt_str32, SNT_PRIMITIVE),           \
            (snt_scdt32, SNT_STRUCTURE),          \
            (snt_scdt64, SNT_STRUCTURE),          \
            (snt_pt64, SNT_PRIMITIVE),            \
            (snt_ts128, SNT_STRUCTURE)            \
        )

#define ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER(X) \
        ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER_IMPL X
#define ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER_IMPL(MODEL_NAME, MODEL_TYPE) \
        MODEL_NAME ___SNT_PP_CAT(MODEL_NAME, _hey) ;

#define ___SNT_PP_DECL_BUILTIN_MODEL_INFO(MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_BUILTIN_MODEL_INFO_IMPL(MODEL_NAME, MODEL_TYPE)
#define ___SNT_PP_DECL_BUILTIN_MODEL_INFO_IMPL(MODEL_NAME, MODEL_TYPE) \
        static                                                         \
        struct snt_model_info                                          \
        ___SNT_PP_CAT(___snt_model_info_, MODEL_NAME) = {              \
            .model_name = #MODEL_NAME,                                 \
            .actual_size = sizeof(MODEL_NAME),                         \
        };                                                             

#define ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_2(FIELD_TYPE, FIELD_NAME) \
        ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_2_IMPL(FIELD_TYPE, FIELD_NAME)
#define ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_2_IMPL(FIELD_TYPE, FIELD_NAME) \
        {                                                                    \
            .field_name = FIELD_NAME,                                        \
            .field_offset = __builtin_offsetof(FIELD_TYPE, FIELD_NAME),      \
        },

#define ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_3(FIELD_TYPE, FIELD_NAME, KEYWORD) \
        ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_3_IMPL(FIELD_TYPE, FIELD_NAME, KEYWORD)
#define ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_3_IMPL(FIELD_TYPE, FIELD_NAME, KEYWORD) \
        {                                                                             \
            .field_name = FIELD_NAME,                                                 \
            .field_offset = __builtin_offsetof(FIELD_TYPE, FIELD_NAME),               \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(SNT_POINTER, KEYWORD))                      \
            (                                                                         \
                .is_pointer = true,                                                   \
            )                                                                         \
            (                                                                         \
                                                                                      \
            )                                                                         \
        },

#define ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_4(FIELD_TYPE, FIELD_NAME, KEYWORD, SIZE) \
        ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_4_IMPL(FIELD_TYPE, FIELD_NAME, KEYWORD, SIZE)
#define ___SNT_PP_REGISTER_BUILTIN_FIELD_INFO_4_IMPL(FIELD_TYPE, FIELD_NAME, KEYWORD, SIZE) \
        {                                                                                   \
            .field_name = FIELD_NAME,                                                       \
            .field_offset = __builtin_offsetof(FIELD_TYPE, FIELD_NAME),                     \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_ARRAY))         \
            (                                                              \
                .array_size = SIZE,                                        \
            )                                                              \
            (                                                              \
                ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_BIT_FIELD)) \
                (                                                          \
                    .is_bit_field = true,                                  \
                )                                                          \
                ()                                                         \
            )                                                              \
        },

#ifdef __cplusplus
}
#endif

#endif