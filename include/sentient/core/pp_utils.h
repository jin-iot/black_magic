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

#define ___SNT_PP_PASS(ARGS) args
#define ___SNT_PP_IS_VA_ARG(...) ,
#define ___SNT_PP_COMMA()) ,
#define ___SNT_PP_LPAREN() (
#define ___SNT_PP_RPAREN() )
#define ___SNT_PP_LSQUARE() [
#define ___SNT_PP_RSQUARE() ]
#define ___SNT_PP_SEMICOLON() ;
#define ___SNT_PP_ARR(EXPR) [EXPR]
#define ___SNT_PP_BF(EXPR) : EXPR

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief expands to nothing
 * @date 2022-05-04
 */
#define ___SNT_PP_EMPTY()

#define ___SNT_PP_WRAP(...) \
        ___SNT_PP_LPAREN() __VA_ARGS__  ___SNT_PP_RPAREN()
#define ___SNT_PP_UNWRAP(ARGS) \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_IN_PAREN(ARGS)) \
        (                                              \
            ___SNT_PP_PASS ARGS                        \
        )                                              \
        (                                              \
            ARGS                                       \
        )

#include <sentient/core/internal/pp_eval.h>
#include <sentient/core/internal/pp_defer.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list
 * @date 2022-05-04
 */
#define ___SNT_PP_FIRST(X, ...) x
#define ___SNT_PP_SECOND(X, Y, ...) Y

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is in parenthesis
 * @date 2022-05-06
 */
#define ___SNT_PP_DETECT_PAREN(...) ,
#define ___SNT_PP_IS_IN_PAREN(...) \
        ___SNT_PP_IS_IN_PAREN_IMPL(__VA_ARGS__)
#define ___SNT_PP_IS_IN_PAREN_IMPL(...)                                 \
        ___SNT_PP_HAS_COMMA(                                            \
            ___SNT_PP_CAT_3(                                            \
                ___SNT_PP_IS_IN_PAREN_,                                 \
                ___SNT_PP_HAS_COMMA(__VA_ARGS__),                       \
                ___SNT_PP_HAS_COMMA(___SNT_PP_DETECT_PAREN __VA_ARGS__) \
            )                                                           \
        )
#define ___SNT_PP_IS_IN_PAREN_01 ,

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is parenthesis
 * @date 2022-05-06
 */
#define ___SNT_PP_CHECK(...) \
        ___SNT_PP_GET_1(__VA_ARGS__, 0, )

#define ___SNT_PP_IS_PAREN(x) \
        ___SNT_PP_CHECK(___SNT_PP_IS_PAREN_PROBE x)
#define ___SNT_PP_IS_PAREN_PROBE(...) \
        ___SNT_PP_PROBE()

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
 * @brief compares each arg
 * @date 2022-05-07
 */
#define ___SNT_PP_IS_EQ(X, Y) \
        ___SNT_PP_IS_EQ_IMPL(X, Y)
#define ___SNT_PP_IS_EQ_IMPL(X, Y)                                      \
        ___SNT_PP_NOT(                                                  \
            ___SNT_PP_IS_PAREN(                                         \
                ___SNT_PP_COMPARE_ ## X (___SNT_PP_COMPARE_ ## Y ) (()) \
            )                                                           \
        )
/**
 * macro numeric, keyword constants ( 0 ~ N, keywords... ) to compare
 */
#include <sentient/core/internal/pp_compare_n.h>
#define ___SNT_PP_COMPARE_(...) 
#define ___SNT_PP_COMPARE_STRUCTURE(X) X
#define ___SNT_PP_COMPARE_PRIMITIVE(X) X
#define ___SNT_PP_COMPARE_SNT_BIT_FIELD(X) X
#define ___SNT_PP_COMPARE_SNT_ARRAY(X) X
#define ___SNT_PP_COMPARE_SNT_NO_ATTR(X) X

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief gets an element from the token list with specific index
 * @date 2022-05-04
 */
#define ___SNT_PP_GET(N, ...) \
        ___SNT_PP_CAT(___SNT_PP_GET_, N) (__VA_ARGS__)
#include <sentient/core/internal/pp_get_n.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief conCATenates tokens
 * @date 2022-05-04
 */
#define ___SNT_PP_CAT(X, ...) \
        ___SNT_PP_CAT_IMPL(X, __VA_ARGS__)
#define ___SNT_PP_CAT_IMPL(X, ...) X ## __VA_ARGS__
#define ___SNT_PP_CAT_2(X, Y, ...) \
        ___SNT_PP_CAT_2_IMPL(X, Y, __VA_ARGS__)
#define ___SNT_PP_CAT_2_IMPL(X, Y, ...) X ## Y ## __VA_ARGS__
#define ___SNT_PP_CAT_3(X, Y, Z, ...) \
        ___SNT_PP_CAT_3_IMPL(X, Y, Z, __VA_ARGS__)
#define ___SNT_PP_CAT_3_IMPL(X, Y, Z, ...) X ## Y ## Z ## __VA_ARGS__
#define ___SNT_PP_CAT_4(X, Y, Z, A, ...) \
        ___SNT_PP_CAT_4_IMPL(X, Y, Z, A, __VA_ARGS__)
#define ___SNT_PP_CAT_4_IMPL(X, Y, Z, A, ...) X ## Y ## Z ## A ## __VA_ARGS__

#define ___SNT_PP_INCREASE(NUMBER) \
        ___SNT_PP_CAT(___SNT_PP_INCREASE_IMPL_, NUMBER)
#define ___SNT_PP_decrease(NUMBER) \
        ___SNT_PP_CAT(___SNT_PP_DECREASE_IMPL_, NUMBER)
#include <sentient/core/internal/pp_inc_dec.h>

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

/*!
 * @author Jin (jaehwanspin@gmail.com)
 * @brief preprocessor if else statement
 *
 * > const int val = ___SNT_PP_IF_ELSE(5) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_IF_ELSE_IMPL(___SNT_PP_bool(5)) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_IF_ELSE_IMPL(1) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_CAT(___SNT_PP_IF_ELSE_1) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_IF_ELSE_1 (0xdead)(0xbeef);
 * > const int val = (0xdead) ___SNT_PP_if_1_else (0xbeef);
 * > const int val = (0xdead);
 */
#define ___SNT_PP_IF_ELSE(COND) \
        ___SNT_PP_IF_ELSE_IMPL(___SNT_PP_BOOL(COND))
#define ___SNT_PP_IF_ELSE_IMPL(COND) \
        ___SNT_PP_CAT(___SNT_PP_IF_ELSE_, COND)
#define ___SNT_PP_IF_ELSE_1(...) \
        __VA_ARGS__ ___SNT_PP_IF_1_ELSE
#define ___SNT_PP_IF_ELSE_0(...) \
        ___SNT_PP_IF_0_ELSE
#define ___SNT_PP_IF_1_ELSE(...)
#define ___SNT_PP_IF_0_ELSE(...) \
        __VA_ARGS__


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

/**
 * @author Jin
 * @brief evaluates expressions in the loop
 * @date 2022-05-10
 */
#define ___SNT_PP_FOR(NUM_LOOP, START_NUMBER, INC_DEC, EXPR, ...) \
        ___SNT_PP_FOR_IMPL(NUM_LOOP, START_NUMBER, INC_DEC, EXPR, __VA_ARGS__)
#define ___SNT_PP_FOR_IMPL(NUM_LOOP, START_NUMBER, INC_DEC, EXPR, ...) \
        ___SNT_PP_CAT_4(                                               \
                ___SNT_PP_FOR_,                                        \
                INC_DEC,                                               \
                _,                                                     \
                NUM_LOOP                                               \
        ) (START_NUMBER, EXPR, __VA_ARGS__)
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
#define ___SNT_PP_COUNT_ARGS(...) \
        ___SNT_PP_COUNT_ARGS_IMPL(0, ## __VA_ARGS__)
#include <sentient/core/internal/pp_count_args.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the args have comma
 * @date 2022-05-06
 */
#define ___SNT_PP_HAS_COMMA(...) \
        ___SNT_PP_HAS_COMMA_IMPL(__VA_ARGS__)
#include <sentient/core/internal/pp_has_comma.h>

/**
 * @author Jin
 * @brief preprocessor not operator
 * 
 * > ___SNT_PP_not(123)
 * > ___SNT_PP_is_probe(___SNT_PP_not_123)
 * > ___SNT_PP_second(___SNT_PP_not_123, 0)
 * > 0
 * 
 * > ___SNT_PP_not(0)
 * > ___SNT_PP_is_probe(___SNT_PP_not_0)
 * > ___SNT_PP_second(~, 1, 0)
 * > 1
 * 
 */
#define ___SNT_PP_NOT(X) \
        ___SNT_PP_IS_PROBE(___SNT_PP_CAT(___SNT_PP_NOT_, X))
#define ___SNT_PP_IS_PROBE(...) \
        ___SNT_PP_SECOND(__VA_ARGS__, 0)
#define ___SNT_PP_PROBE() \
        ~, 1
#define ___SNT_PP_NOT_0 \
        ___SNT_PP_PROBE()

#define ___SNT_PP_BOOL(X) \
        ___SNT_PP_NOT(___SNT_PP_NOT(X))

#define ___SNT_PP_DECL_RESERVED_KEYWORD(MODEL_TYPE) \
        ___SNT_PP_DECL_RESERVED_KEYWORD_IMPL(MODEL_TYPE)
#define ___SNT_PP_DECL_RESERVED_KEYWORD_IMPL(MODEL_TYPE) \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(MODEL_TYPE, STRUCTURE)) \
        (                                                         \
            struct                                                \
        )                                                         \
        (                                                         \
            ___SNT_PP_EMPTY()                                     \
        )

// so ideal!!!!!!!!!!!!!
// for i in range(0, 5): print(16**i, int((8**5)/(4**(i+1))))

#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE(MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_IMPL(MODEL_NAME, MODEL_TYPE)
#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_IMPL(MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS(                 \
                SENTIENT_C_NUM_POOL_LOOP,                               \
                MODEL_NAME,                                             \
                MODEL_TYPE)                                             \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS(                       \
                SENTIENT_C_NUM_POOL_LOOP,                               \
                MODEL_NAME,                                             \
                MODEL_TYPE)                                             \
        static                                                          \
        struct snt_object_pool_storage                                  \
        ___snt_object_pool_storage_ ## MODEL_NAME = {                   \
            .storage_size = SENTIENT_C_NUM_POOL_LOOP,                   \
            .storage =                                             \
                ___snt_object_pool_storage_elems_ ## MODEL_NAME         \
        };
        

#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS(NUM_LOOP, MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS_IMPL(NUM_LOOP, MODEL_NAME, MODEL_TYPE)
#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS_IMPL(NUM_LOOP, MODEL_NAME, MODEL_TYPE) \
        static                                                                          \
        struct snt_object_pool_storage_elem                                             \
        ___snt_object_pool_storage_elems_ ## MODEL_NAME [] = {                          \
        ___SNT_PP_FOR(NUM_LOOP,                                                         \
                      0,                                                                \
                      INCREASE,                                                         \
                      ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS_HANDLER,                 \
                      NUM_LOOP,                                                         \
                      MODEL_NAME,                                                       \
                      MODEL_TYPE)                                                       \
        };

#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS_HANDLER(NUM, MAX, MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS_HANDLER_IMPL(NUM, MAX, MODEL_NAME, MODEL_TYPE)
#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEMS_HANDLER_IMPL(NUM, MAX, MODEL_NAME, MODEL_TYPE)   \
        {                                                                                         \
            .alloc_size = (snt_size)(___SNT_PP_POW( 16, NUM ) *                                   \
                sizeof(___SNT_PP_DECL_RESERVED_KEYWORD(MODEL_TYPE) MODEL_NAME)),                  \
            .array_size = (snt_size)(___SNT_PP_POW( 8, MAX )) /                                   \
                (___SNT_PP_POW( 4, ___SNT_PP_INCREASE(NUM) )),                                    \
            .elems = (snt_void*)___snt_object_pool_storage_elem_array_ ## MODEL_NAME ## _ ## NUM, \
        },



#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS(NUM_LOOP, MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS_IMPL(NUM_LOOP, MODEL_NAME, MODEL_TYPE)
#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS_IMPL(NUM_LOOP, MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_FOR(NUM_LOOP,                                                 \
                      0,                                                        \
                      INCREASE,                                                 \
                      ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS_HANDLER,   \
                      NUM_LOOP,                                                 \
                      MODEL_NAME,                                               \
                      MODEL_TYPE)

#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS_HANDLER(NUM, MAX, MODEL_NAME, MODEL_TYPE) \
        ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS_HANDLER_IMPL(NUM, MAX, MODEL_NAME, MODEL_TYPE)
#define ___SNT_PP_DECL_OBJECT_POOL_STORAGE_ELEM_ARRAYS_HANDLER_IMPL(NUM, MAX, MODEL_NAME, MODEL_TYPE) \
        static                                                                                        \
        ___SNT_PP_DECL_RESERVED_KEYWORD(MODEL_TYPE)                                                   \
        MODEL_NAME                                                                                    \
        ___snt_object_pool_storage_elem_array_ ## MODEL_NAME ## _ ## NUM                              \
        [___SNT_PP_POW( 16, NUM )]                                                                    \
        [(___SNT_PP_POW( 8, MAX )) / (___SNT_PP_POW( 4, ___SNT_PP_INCREASE(NUM) ))];

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief determines how to declare a field
 */
#define ___SNT_PP_DECL_FIELD(...)             \
        ___SNT_PP_CAT_2(                      \
            ___SNT_PP_DECL_FIELD_,            \
            ___SNT_PP_COUNT_ARGS __VA_ARGS__  \
        ) __VA_ARGS__

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief declares a field with an expression
 */
#define ___SNT_PP_DECL_FIELD_1(MODEL_EXTRA_ATTR) \
        ___SNT_PP_DECL_FIELD_1_IMPL(MODEL_EXTRA_ATTR)
#define ___SNT_PP_DECL_FIELD_1_IMPL(MODEL_EXTRA_ATTR) \
        ___SNT_PP_FOREACH(MODEL_EXTRA_ATTR)

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief common field
 */
#define ___SNT_PP_DECL_FIELD_2(TYPE, NAME) \
        ___SNT_PP_DECL_FIELD_2_IMPL(TYPE, NAME)
#define ___SNT_PP_DECL_FIELD_2_IMPL(TYPE, NAME) \
        TYPE NAME ;

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief array field
 */
#define ___SNT_PP_DECL_FIELD_4(TYPE, NAME, KEYWORD, SIZE) \
        ___SNT_PP_DECL_FIELD_4_IMPL(TYPE, NAME, KEYWORD, SIZE)
#define ___SNT_PP_DECL_FIELD_4_IMPL(TYPE, NAME, KEYWORD, SIZE)         \
        TYPE NAME                                                      \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_ARRAY))         \
        (                                                              \
            ___SNT_PP_ARR(SIZE) ;                                      \
        )                                                              \
        (                                                              \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_BIT_FIELD)) \
            (                                                          \
                ___SNT_PP_BF(SIZE) ;                                   \
            )                                                          \
            ()                                                         \
        )

#define ___SNT_PP_DECL_FIELD_5(TYPE, NAME, KEYWORD, SIZE, ATTRIBUTES) \
        ___SNT_PP_DECL_FIELD_5_IMPL(TYPE, NAME, KEYWORD, SIZE, ATTRIBUTES)
#define ___SNT_PP_DECL_FIELD_5_IMPL(TYPE, NAME, KEYWORD, SIZE, ATTRIBUTES) \
        TYPE                                                               \
        __attribute__((ATTRIBUTES))                                        \
        NAME                                                               \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_ARRAY))             \
        (                                                                  \
            ___SNT_PP_ARR(SIZE) ;                                          \
        )                                                                  \
        (                                                                  \
            ___SNT_PP_IF_ELSE(___SNT_PP_IS_EQ(KEYWORD, SNT_BIT_FIELD))     \
            (                                                              \
                ___SNT_PP_BF(SIZE) ;                                       \
            )                                                              \
            ()                                                             \
        )


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



#ifdef __cplusplus
}
#endif

#endif