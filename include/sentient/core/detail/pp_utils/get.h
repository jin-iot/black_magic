#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_GET_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_GET_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list
 * @date 2022-05-04
 */
#define ___SNT_PP_FIRST(X, ...) X
#define ___SNT_PP_SECOND(X, Y, ...) Y

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list with specific index
 * @date 2022-05-04
 */
#define ___SNT_PP_GET(N, ...) \
        ___SNT_PP_CAT(___SNT_PP_GET_, N) (__VA_ARGS__)
#include <sentient/core/internal/pp_get_n.h>

#ifdef __cplusplus
}
#endif

#endif