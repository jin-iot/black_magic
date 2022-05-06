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

#define ___sentient_pp_is_va_arg(...) ,
#define ___sentient_pp_comma() ,
#define ___sentient_pp_lparen() (
#define ___sentient_pp_rparen() (

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief expands to nothing
 * @date 2022-05-04
 */
#define ___sentient_pp_empty(...)

#define ___sentient_pp_wrap(...) \
        ___sentient_pp_lparen __VA_ARGS__  ___sentient_pp_rparen
#define ___sentient_pp_unwrap(...)


/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list
 * @date 2022-05-04
 */
#define ___sentient_pp_first(x, ...) x
#define ___sentient_pp_second(x, y, ...) y

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is in parenthesis
 * @date 2022-05-06
 */
#define ___sentient_pp_detect_paren(...) ,
#define ___sentient_pp_is_in_paren(...) \
        ___sentient_pp_is_in_paren_impl(__VA_ARGS__)
#define ___sentient_pp_is_in_paren_impl(...)                                      \
        ___sentient_pp_has_comma(                                                 \
            ___sentient_pp_cat_3(                                                 \
                ___sentient_pp_is_in_paren_,                                      \
                ___sentient_pp_has_comma(__VA_ARGS__),                            \
                ___sentient_pp_has_comma(___sentient_pp_detect_paren __VA_ARGS__) \
            )                                                                     \
        )
#define ___sentient_pp_is_in_paren_01 ,

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is parenthesis
 * @date 2022-05-06
 */
#define ___sentient_pp_check(...) \
        ___sentient_pp_get_1(__VA_ARGS__, 0, )

#define ___sentient_pp_is_paren(x) \
        ___sentient_pp_check(___sentient_pp_is_paren_probe x)
#define ___sentient_pp_is_paren_probe(...) \
        ___sentient_pp_probe()


/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief compares each arg
 * @date 2022-05-04
 */
#define ___sentient_pp_is_eq(x, y) \
        ___sentient_pp_is_eq_impl(x, y)
#define ___sentient_pp_is_eq_impl(x, y)                                           \
        ___sentient_pp_not(                                                       \
            ___sentient_pp_is_paren(                                              \
                ___sentient_pp_compare_ ## x (___sentient_pp_compare_ ## y ) (()) \
            )                                                                     \
        )
/**
 * constants ( 0 ~ N ) to compare
 */
#include <sentient/core/internal/pp_compare_n.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list with specific index
 * @date 2022-05-04
 */
#define ___sentient_pp_get(N, ...) \
        ___sentient_pp_cat(___sentient_pp_get_, N) (__VA_ARGS__)
#include <sentient/core/internal/pp_get_n.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief concatenates tokens
 * @date 2022-05-04
 */
#define ___sentient_pp_cat(x, ...) \
        ___sentient_pp_cat_impl(x, __VA_ARGS__)
#define ___sentient_pp_cat_impl(x, ...) x ## __VA_ARGS__
#define ___sentient_pp_cat_2(x, y, ...) \
        ___sentient_pp_cat_2_impl(x, y, __VA_ARGS__)
#define ___sentient_pp_cat_2_impl(x, y, ...) x ## y ## __VA_ARGS__
#define ___sentient_pp_cat_3(x, y, z, ...) \
        ___sentient_pp_cat_3_impl(x, y, z, __VA_ARGS__)
#define ___sentient_pp_cat_3_impl(x, y, z, ...) x ## y ## z ## __VA_ARGS__
#define ___sentient_pp_cat_4(x, y, z, a, ...) \
        ___sentient_pp_cat_4_impl(x, y, z, a, __VA_ARGS__)
#define ___sentient_pp_cat_4_impl(x, y, z, a, ...) x ## y ## z ## a ## __VA_ARGS__

#include <sentient/core/internal/pp_inc_dec.h>
#define ___sentient_pp_increase(number) \
        ___sentient_pp_cat(___sentient_pp_increase_impl_, number)

/*!
 * @author Jin (jaehwanspin@gmail.com)
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


/**
 * @author Jin
 * @brief evaluates each expressions
 * @date 2022-05-04
 */
#define ___sentient_pp_foreach(expr, ...)              \
        ___sentient_pp_cat(                            \
                ___sentient_pp_foreach_,               \
                ___sentient_pp_count_args(__VA_ARGS__) \
        ) (expr, __VA_ARGS__)
#include <sentient/core/internal/pp_foreach.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief for count args
 * @date 2022-05-04
 */
#include <sentient/core/internal/pp_args.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief counts number of tokens
 * @date 2022-05-04
 */
#define ___sentient_pp_count_args(...) \
        ___sentient_pp_count_args_impl(0, ## __VA_ARGS__)
#include <sentient/core/internal/pp_count_args.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the args have comma
 * @date 2022-05-06
 */
#define ___sentient_pp_has_comma(...) \
        ___sentient_pp_has_comma_impl(__VA_ARGS__)
#include <sentient/core/internal/pp_has_comma.h>

/**
 * @author Jin
 * @brief preprocessor not operator
 * 
 * > ___sentient_pp_not(123)
 * > ___sentient_pp_is_probe(___sentient_pp_not_123)
 * > ___sentient_pp_second(___sentient_pp_not_123, 0)
 * > 0
 * 
 * > ___sentient_pp_not(0)
 * > ___sentient_pp_is_probe(___sentient_pp_not_0)
 * > ___sentient_pp_second(~, 1, 0)
 * > 1
 * 
 */
#define ___sentient_pp_not(x) \
        ___sentient_pp_is_probe(___sentient_pp_cat(___sentient_pp_not_, x))
#define ___sentient_pp_is_probe(...) \
        ___sentient_pp_second(__VA_ARGS__, 0)
#define ___sentient_pp_probe() \
        ~, 1
#define ___sentient_pp_not_0 \
        ___sentient_pp_probe()

#define ___sentient_pp_bool(x) \
        ___sentient_pp_not(___sentient_pp_not(x))


#ifdef __cplusplus
}
#endif

#endif