#ifndef __SENTIENT_CORE_PP_UTILS_H__
#define __SENTIENT_CORE_PP_UTILS_H__

/**
 * @file pp_utils.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief preprocessor utils
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief expands to nothing
 * @date 2022-05-04
 */
#define ___sentient_pp_empty(...)

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief concatenates tokens
 * @date 2022-05-04
 */
#define ___sentient_pp_cat(x, ...) x ## __VA_ARGS__
#define ___sentient_pp_cat_3(x, y, ...) x ## y ## __VA_ARGS__
#define ___sentient_pp_cat_4(x, y, ...) x ## y ## __VA_ARGS__


#include <sentient/core/internal/pp_inc_dec.h>
#define ___sentient_pp_increase(number) \
        ___sentient_pp_cat(___sentient_pp_increase_impl_, number)

/*!
 * @author Jin
 * @brief preprocessor if else statement
 *
 * > const int val = ___sentient_pp_if_else(5) (0xdead)(0xbeef);
 * > const int val = ___sentient_pp_if_else_impl(___sentient_pp_bool(5)) (0xdead)(0xbeef);
 * > const int val = ___sentient_pp_if_else_impl(1) (0xdead)(0xbeef);
 * > const int val = ___sentient_pp_cat(___sentient_pp_if_else_1) (0xdead)(0xbeef);
 * > const int val = ___sentient_pp_if_else_1 (0xdead)(0xbeef);
 * > const int val = (0xdead) ___sentient_pp_if_1_else (0xbeef);
 * > const int val = (0xdead);
 */
#define ___sentient_pp_if_else(cond) \
        ___sentient_pp_if_else_impl(___sentient_pp_bool(cond))
#define ___sentient_pp_if_else_impl(cond) \
        ___sentient_pp_cat(___sentient_pp_if_else_, cond)
#define ___sentient_pp_if_else_1(...) \
        __VA_ARGS__ ___sentient_pp_if_1_else
#define ___sentient_pp_if_else_0(...) \
        ___sentient_pp_if_0_else
#define ___sentient_pp_if_1_else(...)
#define ___sentient_pp_if_0_else(...) \
        __VA_ARGS__


#define ___sentient_pp_foreach(expr, ...) \
	    ___sentient_pp_cat(___sentient_pp_foreach_, ___sentient_pp_count_args(__VA_ARGS__)) (expr, __VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif