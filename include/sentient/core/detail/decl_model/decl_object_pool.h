#ifndef __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_OBJECT_POOL_H__
#define __SENTIENT_CORE_DETAIL_DECL_MODEL_DECL_OBJECT_POOL_H__

#include <sentient/core/pp_utils.h>
#include <sentient/core/object_pool.h>

#ifdef __cplusplus
extern "C"
{
#endif

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



#ifdef __cplusplus
}
#endif

#endif