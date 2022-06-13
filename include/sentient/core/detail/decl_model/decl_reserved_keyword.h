#ifndef __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_RESERVED_KEYWORD_H__
#define __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_RESERVED_KEYWORD_H__

#include <sentient/core/pp_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define ___SNT_PP_DECL_RESERVED_KEYWORD(MODEL_TYPE) \
        ___SNT_PP_DECL_RESERVED_KEYWORD_IMPL(MODEL_TYPE)
#define ___SNT_PP_DECL_RESERVED_KEYWORD_IMPL(MODEL_TYPE) \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(MODEL_TYPE, SNT_STRUCTURE)) \
        (                                                             \
            struct                                                    \
        )                                                             \
        (                                                             \
            ___SNT_PP_EMPTY()                                         \
        )

#ifdef __cplusplus
}
#endif

#endif