#ifndef __SENTIENT_CORE_INTERNAL_BUILTIN_TYPES_H__
#define __SENTIENT_CORE_INTERNAL_BUILTIN_TYPES_H__

#include <sentient/core/types.h>
#include <sentient/core/model_info.h>

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
#define ___SNT_PP_DECL_BUILTIN_TYPES_IMPL()      \
        ___SNT_PP_FOREACH(                       \
            ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER \
            (snt_u16, PRIMITIVE),                \
            (snt_u32, PRIMITIVE),                \
            (snt_u64, PRIMITIVE),                \
            (snt_i8, PRIMITIVE),                 \
            (snt_i16, PRIMITIVE),                \
            (snt_i32, PRIMITIVE),                \
            (snt_i64, PRIMITIVE),                \
            (snt_f32, PRIMITIVE),                \
            (snt_f64, PRIMITIVE),                \
            (snt_str8, PRIMITIVE),               \
            (snt_str16, PRIMITIVE),              \
            (snt_str32, PRIMITIVE),              \
            (snt_scdt32, STRUCTURE),             \
            (snt_scdt64, STRUCTURE),             \
            (snt_pt64, STRUCTURE),               \
            (snt_ts128, STRUCTURE)               \
        )


#define ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER(X) \
        ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER_IMPL X
#define ___SNT_PP_DECL_BUILTIN_TYPES_HANDLER_IMPL(MODEL_NAME, MODEL_TYPE) \
        MODEL_NAME ___SNT_PP_CAT(MODEL_NAME, _hey) ;

#ifdef __cplusplus
}
#endif

#endif