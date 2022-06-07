#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_FOREACH_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_FOREACH_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin
 * @brief evaluates each expressions
 * @date 2022-05-04
 */
#define ___SNT_PP_FOREACH(EXPR, ...)              \
        ___SNT_PP_CAT(                            \
                ___SNT_PP_FOREACH_,               \
                ___SNT_PP_COUNT_ARGS(__VA_ARGS__) \
        ) (EXPR, __VA_ARGS__)
#include <sentient/core/internal/pp_foreach.h>

#ifdef __cplusplus
}
#endif

#endif