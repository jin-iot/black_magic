#ifndef __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_MODEL_H__
#define __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_MODEL_H__

#include <sentient/core/pp_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief defines a model structure with the model info
 * @date 2022-05-07
 */
#define ___SNT_PP_DECL_MODEL(...) \
        ___SNT_PP_DECL_MODEL_IMPL(__VA_ARGS__)
#define ___SNT_PP_DECL_MODEL_IMPL(MODEL_NAME, ATTRS, ...) \
        extern                                            \
        ___snt_type_id                                    \
        ___SNT_PP_CAT(___snt_type_id_, MODEL_NAME) ;      \
        struct MODEL_NAME                                 \
        {                                                 \
            ___SNT_PP_FOREACH(                            \
                ___SNT_PP_DECL_FIELD,                     \
                __VA_ARGS__                               \
            )                                             \
        }                                                 \
        __attribute__((ATTRS))                            \
        ;

#define ___SNT_PP_IMPL_MODEL(...) \
        ___SNT_PP_IMPL_MODEL_IMPL(__VA_ARGS__)
#define ___SNT_PP_IMPL_MODEL_IMPL(MODEL_NAME, ATTRS, ...)
        ___snt_type_id                                    \
        ___SNT_PP_CAT(___snt_type_id_, MODEL_NAME) ;      \
        



















        