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

#include <sentient/core/detail/pp_utils/basics.h>
#include <sentient/core/detail/pp_utils/is_eq.h>
#include <sentient/core/detail/pp_utils/cat.h>
#include <sentient/core/detail/pp_utils/inc_dec.h>
#include <sentient/core/detail/pp_utils/get.h>
#include <sentient/core/detail/pp_utils/arithmetic.h>
#include <sentient/core/detail/pp_utils/if_else.h>
#include <sentient/core/detail/pp_utils/foreach.h>
#include <sentient/core/detail/pp_utils/for.h>
#include <sentient/core/detail/pp_utils/count_args.h>
#include <sentient/core/detail/pp_utils/bool.h>

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