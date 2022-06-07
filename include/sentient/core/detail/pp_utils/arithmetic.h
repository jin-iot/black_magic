#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_ARITHMETIC_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_ARITHMETIC_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief and operator macro, usage: ___SNT_PP_AND(1)(1)
 * @date 2022-05-06
 */
#define ___SNT_PP_AND(ARG_1) \
        ___SNT_PP_CAT(___SNT_PP_AND_, ARG_1)
#define ___SNT_PP_AND_0(ARG_2) 0
#define ___SNT_PP_AND_1(ARG_2) ARG_2

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief arithmetic operations
 * @date 2022-06-07
 */
#define ___SNT_PP_ADD(X, Y) \
        ___SNT_PP_ADD_IMPL(X, Y)
#define ___SNT_PP_ADD_IMPL(X, Y) \
        ___SNT_PP_CAT_4(___SNT_PP_ADD_IMPL_, X, _, Y)
#define ___SNT_PP_SUB(X, Y) \
        ___SNT_PP_SUB_IMPL(X, Y)
#define ___SNT_PP_SUB_IMPL(X, Y) \
        ___SNT_PP_CAT_4(___SNT_PP_SUB_IMPL_, X, _, Y)
#define ___SNT_PP_MUL(X, Y) \
        ___SNT_PP_MUL_IMPL(X, Y)
#define ___SNT_PP_MUL_IMPL(X, Y) \
        ___SNT_PP_CAT_4(___SNT_PP_mul_IMPL_, X, _, Y)
#define ___SNT_PP_DIV(X, Y) \
        ___SNT_PP_DIV_IMPL(X, Y)
#define ___SNT_PP_DIV_IMPL(X, Y) \
        ___SNT_PP_CAT_4(___SNT_PP_div_IMPL_, X, _, Y)
#define ___SNT_PP_POW(X, Y) \
        ___SNT_PP_POW_IMPL(X, Y)
#define ___SNT_PP_POW_IMPL(X, Y) \
        ___SNT_PP_CAT_4(___SNT_PP_POW_IMPL_, X, _, Y)
#include <sentient/core/internal/pp_arithmetic.h>

#ifdef __cplusplus
}
#endif

#endif