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

#define ___snt_pp_pass(args) args
#define ___snt_pp_is_va_arg(...) ,
#define ___snt_pp_comma() ,
#define ___snt_pp_lparen() (
#define ___snt_pp_rparen() )

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief expands to nothing
 * @date 2022-05-04
 */
#define ___snt_pp_empty()

#define ___snt_pp_wrap(...) \
        ___snt_pp_lparen() __VA_ARGS__  ___snt_pp_rparen()
#define ___snt_pp_unwrap(args) \
        ___snt_pp_if_else(___snt_pp_is_in_paren(args)) \
        (                                              \
            ___snt_pp_pass args                        \
        )                                              \
        (                                              \
            args                                       \
        )

// #define ___snt_pp_defer(...) \
//         ___snt_pp_empty() __VA_ARGS__
#include <sentient/core/internal/pp_eval.h>
#include <sentient/core/internal/pp_defer.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list
 * @date 2022-05-04
 */
#define ___snt_pp_first(x, ...) x
#define ___snt_pp_second(x, y, ...) y

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is in parenthesis
 * @date 2022-05-06
 */
#define ___snt_pp_detect_paren(...) ,
#define ___snt_pp_is_in_paren(...) \
        ___snt_pp_is_in_paren_impl(__VA_ARGS__)
#define ___snt_pp_is_in_paren_impl(...)                                 \
        ___snt_pp_has_comma(                                            \
            ___snt_pp_cat_3(                                            \
                ___snt_pp_is_in_paren_,                                 \
                ___snt_pp_has_comma(__VA_ARGS__),                       \
                ___snt_pp_has_comma(___snt_pp_detect_paren __VA_ARGS__) \
            )                                                           \
        )
#define ___snt_pp_is_in_paren_01 ,

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is parenthesis
 * @date 2022-05-06
 */
#define ___snt_pp_check(...) \
        ___snt_pp_get_1(__VA_ARGS__, 0, )

#define ___snt_pp_is_paren(x) \
        ___snt_pp_check(___snt_pp_is_paren_probe x)
#define ___snt_pp_is_paren_probe(...) \
        ___snt_pp_probe()

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief and operator macro, usage: ___snt_pp_and(1)(1)
 * @date 2022-05-06
 */
#define ___snt_pp_and(arg_1) \
        ___snt_pp_cat(___snt_pp_and_, arg_1)
#define ___snt_pp_and_0(arg_2) 0
#define ___snt_pp_and_1(arg_2) arg_2

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief compares each arg
 * @date 2022-05-07
 */
#define ___snt_pp_is_eq(x, y) \
        ___snt_pp_is_eq_impl(x, y)
#define ___snt_pp_is_eq_impl(x, y)                                      \
        ___snt_pp_not(                                                  \
            ___snt_pp_is_paren(                                         \
                ___snt_pp_compare_ ## x (___snt_pp_compare_ ## y ) (()) \
            )                                                           \
        )
/**
 * macro numeric, keyword constants ( 0 ~ N, keywords... ) to compare
 */
#include <sentient/core/internal/pp_compare_n.h>
#define ___snt_pp_compare_structure(x) x
#define ___snt_pp_compare_primitive(x) x
#define ___snt_pp_compare_bit_field(x) x
#define ___snt_pp_compare_array(x) x

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list with specific index
 * @date 2022-05-04
 */
#define ___snt_pp_get(N, ...) \
        ___snt_pp_cat(___snt_pp_get_, N) (__VA_ARGS__)
#include <sentient/core/internal/pp_get_n.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief concatenates tokens
 * @date 2022-05-04
 */
#define ___snt_pp_cat(x, ...) \
        ___snt_pp_cat_impl(x, __VA_ARGS__)
#define ___snt_pp_cat_impl(x, ...) x ## __VA_ARGS__
#define ___snt_pp_cat_2(x, y, ...) \
        ___snt_pp_cat_2_impl(x, y, __VA_ARGS__)
#define ___snt_pp_cat_2_impl(x, y, ...) x ## y ## __VA_ARGS__
#define ___snt_pp_cat_3(x, y, z, ...) \
        ___snt_pp_cat_3_impl(x, y, z, __VA_ARGS__)
#define ___snt_pp_cat_3_impl(x, y, z, ...) x ## y ## z ## __VA_ARGS__
#define ___snt_pp_cat_4(x, y, z, a, ...) \
        ___snt_pp_cat_4_impl(x, y, z, a, __VA_ARGS__)
#define ___snt_pp_cat_4_impl(x, y, z, a, ...) x ## y ## z ## a ## __VA_ARGS__

#define ___snt_pp_increase(number) \
        ___snt_pp_cat(___snt_pp_increase_impl_, number)
#define ___snt_pp_decrease(number) \
        ___snt_pp_cat(___snt_pp_decrease_impl_, number)
#include <sentient/core/internal/pp_inc_dec.h>

#define ___snt_pp_add(x, y) \
        ___snt_pp_add_impl(x, y)
#define ___snt_pp_add_impl(x, y) (x = y)
#define ___snt_pp_sub(x, y) \
        ___snt_pp_sub_impl(x, y)
#define ___snt_pp_sub_impl(x, y) (x - y)
#define ___snt_pp_mul(x, y) \
        ___snt_pp_mul_impl(x, y)
#define ___snt_pp_mul_impl(x, y) (x * y)
#define ___snt_pp_div(x, y) \
        ___snt_pp_div_impl(x, y)
#define ___snt_pp_div_impl(x, y) (x / y)
#define ___snt_pp_pow(x, y) \
        ___snt_pp_pow_impl(x, y)
#define ___snt_pp_pow_impl(x, y)       \
        ___snt_pp_if_else(___snt_pp_is_eq(y, 0)) \
        (                                        \
            1                                    \
        )                                        \
        (                                        \
            (                                    \
                ___snt_pp_eval_ ## y (___snt_pp_defer_ ## y(x))                                \
                ___snt_pp_for(                   \
                    ___snt_pp_decrease(y),       \
                    0,                           \
                    increase,                    \
                    ___snt_pp_pow_helper,        \
                    x                            \
                )                                \
            )                                    \
        )

#define ___snt_pp_pow_helper(dummy, x) \
        ___snt_pp_pow_helper_impl(dummy, x)
#define ___snt_pp_pow_helper_impl(dummy, x) \
        * x

/*!
 * @author Jin (jaehwanspin@gmail.com)
 * @brief preprocessor if else statement
 *
 * > const int val = ___snt_pp_if_else(5) (0xdead)(0xbeef);
 * > const int val = ___snt_pp_if_else_impl(___snt_pp_bool(5)) (0xdead)(0xbeef);
 * > const int val = ___snt_pp_if_else_impl(1) (0xdead)(0xbeef);
 * > const int val = ___snt_pp_cat(___snt_pp_if_else_1) (0xdead)(0xbeef);
 * > const int val = ___snt_pp_if_else_1 (0xdead)(0xbeef);
 * > const int val = (0xdead) ___snt_pp_if_1_else (0xbeef);
 * > const int val = (0xdead);
 */
#define ___snt_pp_if_else(cond) \
        ___snt_pp_if_else_impl(___snt_pp_bool(cond))
#define ___snt_pp_if_else_impl(cond) \
        ___snt_pp_cat(___snt_pp_if_else_, cond)
#define ___snt_pp_if_else_1(...) \
        __VA_ARGS__ ___snt_pp_if_1_else
#define ___snt_pp_if_else_0(...) \
        ___snt_pp_if_0_else
#define ___snt_pp_if_1_else(...)
#define ___snt_pp_if_0_else(...) \
        __VA_ARGS__


/**
 * @author Jin
 * @brief evaluates each expressions
 * @date 2022-05-04
 */
#define ___snt_pp_foreach(expr, ...)              \
        ___snt_pp_cat(                            \
                ___snt_pp_foreach_,               \
                ___snt_pp_count_args(__VA_ARGS__) \
        ) (expr, __VA_ARGS__)
#include <sentient/core/internal/pp_foreach.h>

/**
 * @author Jin
 * @brief evaluates expressions in the loop
 * @date 2022-05-10
 */
#define ___snt_pp_for(num_loop, start_number, inc_dec, expr, ...) \
        ___snt_pp_cat_4(                                          \
                ___snt_pp_for_,                                   \
                inc_dec,                                          \
                _,                                                \
                num_loop                                          \
        ) (start_number, expr, __VA_ARGS__)
#include <sentient/core/internal/pp_for.h>

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
#define ___snt_pp_count_args(...) \
        ___snt_pp_count_args_impl(0, ## __VA_ARGS__)
#include <sentient/core/internal/pp_count_args.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the args have comma
 * @date 2022-05-06
 */
#define ___snt_pp_has_comma(...) \
        ___snt_pp_has_comma_impl(__VA_ARGS__)
#include <sentient/core/internal/pp_has_comma.h>

/**
 * @author Jin
 * @brief preprocessor not operator
 * 
 * > ___snt_pp_not(123)
 * > ___snt_pp_is_probe(___snt_pp_not_123)
 * > ___snt_pp_second(___snt_pp_not_123, 0)
 * > 0
 * 
 * > ___snt_pp_not(0)
 * > ___snt_pp_is_probe(___snt_pp_not_0)
 * > ___snt_pp_second(~, 1, 0)
 * > 1
 * 
 */
#define ___snt_pp_not(x) \
        ___snt_pp_is_probe(___snt_pp_cat(___snt_pp_not_, x))
#define ___snt_pp_is_probe(...) \
        ___snt_pp_second(__VA_ARGS__, 0)
#define ___snt_pp_probe() \
        ~, 1
#define ___snt_pp_not_0 \
        ___snt_pp_probe()

#define ___snt_pp_bool(x) \
        ___snt_pp_not(___snt_pp_not(x))

#define ___snt_pp_decl_field(...)             \
        ___snt_pp_cat(                        \
            ___snt_pp_decl_field_,            \
            ___snt_pp_count_args(__VA_ARGS__) \
        ) (__VA_ARGS__)

#define ___snt_pp_decl_field_2(type, name) \
        ___snt_pp_decl_field_2_impl(type, name)
#define ___snt_pp_decl_field_2_impl(type, name) \
        type name ;


#define ___snt_pp_decl_field_3(type, name, arr_size) \
        ___snt_pp_decl_field_3_impl(type, name, arr_size)
#define ___snt_pp_decl_field_3_impl(type, name, arr_size) \
        type name [ arr_size ] ;

#define ___snt_pp_decl_reserved_keyword(model_type) \
        ___snt_pp_decl_reserved_keyword_impl(model_type)
#define ___snt_pp_decl_reserved_keyword_impl(model_type) \
        ___snt_pp_if_else(___snt_pp_is_eq(model_type, structure)) \
        (                                                         \
            struct                                                \
        )                                                         \
        (                                                         \
                                                                  \
        )

// so ideal!!!!!!!!!!!!!
// for i in range(0, 5): print(16**i, int((8**5)/(4**(i+1))))

#define ___snt_pp_decl_object_pool(storage_len, model_name, model_type) \
        ___snt_pp_decl_object_pool_impl(storage_len, model_name, model_type)
#define ___snt_pp_decl_object_pool_impl(storage_len, model_name, model_type) \
        static const                                                         \
        ___snt_pp_decl_reserved_keyword(model_type)                          \
        type ___snt_object_pool_storage = {                                  \
                                                                             \
        }

#define ___snt_pp_decl_object_pool_elems(num_loop, model_name, model_type) \
        ___snt_pp_decl_object_pool_elems_impl(num_loop, model_name, model_type)
#define ___snt_pp_decl_object_pool_elems_impl(num_loop, model_name, model_type) \
        ___snt_pp_for(num_loop,                                                 \
                      0,                                                        \
                      increase,                                                 \
                      ___snt_pp_decl_object_pool_elems_handler,                 \
                      num_loop,                                                 \
                      model_name,                                               \
                      model_type)

#define ___snt_pp_decl_object_pool_elems_handler(num, max, model_name, model_type) \
        ___snt_pp_decl_object_pool_elems_handler_impl(num, max, model_name, model_type)

#define ___snt_pp_decl_object_pool_elems_handler_impl(num, max, model_name, model_type) \
        static                                                                          \
        ___snt_pp_decl_reserved_keyword(model_type)                                     \
        model_name                                                                      \
        ___snt_pp_cat_4(___snt_object_pool_storage_elem_arr_, model_name, _, num)       \
        [___snt_pp_pow(16, num)]                                                        \
        [___snt_pp_pow(8, max) / ___snt_pp_pow(4, ___snt_pp_increase(num))] ;

// #define ___snt_pp_decl_object_pool_elems_loop_handler(num, max, model_name, model_type) \
//         static                                                                          \
//         struct snt_obejct_pool_stroage_elem                                             \
//         ___snt_object_pool_storage_elem_ ## model_name ## _ ## num                      \
//         [___snt_pp_pow(16, num)]                                                        \
//         [(___snt_pp_pow(8, max)) / (___snt_pp_pow(4, ___snt_pp_increase(num)))];


#define ___snt_pp_decl_object_pool_storage()

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief defines a model structure with the model info
 * @date 2022-05-07
 */
#define ___snt_pp_define_model(...) \
        ___snt_pp_define_model_impl(__VA_ARGS__)

#define ___snt_pp_define_model_impl(model_name, model_type, ...) \
        ___snt_pp_decl_model_name(model_name)        \
        }

#define ___snt_pp_decl_struct_model_name(model_name, model_type) \
        ___snt_pp_decl_reserved_keyword(model_type)              \

#ifdef __cplusplus
}
#endif

#endif