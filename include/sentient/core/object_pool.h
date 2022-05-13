#ifndef __SENTIENT_CORE_POOL_H__
#define __SENTIENT_CORE_POOL_H__

/**
 * @file pool.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief about object pool
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sentient/core/types.h>
#include <sentient/core/hardware_traits.h>
#include <sentient/core/snt_config.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief object pool element descriptor
 */
struct snt_object_pool_element
{
    snt_atomic_uptr next_object_ptr;
    snt_u32         magic;
    snt_size        index;
    snt_atomic_uptr object_ptr;
};

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief object pool descriptor
 */
struct
#ifdef SENTIENT_MULTIPROCESSING
__attribute__((aligned(SENTIENT_CACHELINE_SIZE)))
#endif
snt_object_pool
{
    snt_atomic_uptr head_object_ptr;
    snt_size        pool_size;
    snt_size        object_size;
};

// #define snt_define_object_pool(type, name, size) \
//         struct snt_object_pool \
//             ___snt_object_pool_ ## name = { \
                
//             }

snt_void*
___snt_pool_alloc_impl(
    const ___snt_type_id type_id);

snt_void*
___snt_pool_calloc_impl(
    const snt_size count,
    const ___snt_type_id type_id);

snt_void
___snt_pool_free_impl(
    const ___snt_type_id type_id,
    snt_void* mem);

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief similar to malloc
 * 
 * @param type_id 
 * @return void* 
 */
#define snt_pool_alloc(typename) \
        snt_pool_alloc_impl(typename)
#define snt_pool_alloc_impl(typename) \
        ___snt_pool_alloc_impl(       \
        ___snt_type_id_ ## typename)

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief similar to calloc
 * 
 * @param count 
 * @param type_id 
 * @return void* 
 */
#define snt_pool_calloc(typename) \
        snt_pool_calloc_impl(count, typename)
#define snt_pool_calloc_impl(count, typename) \
        ___snt_pool_calloc_impl(              \
            count,                                 \
            ___snt_type_id_ ## typename)

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief free pool memory
 * 
 * @param type_id 
 * @param mem 
 * @return snt_void 
 */
#define snt_pool_free(typename, mem_ptr) \
        snt_pool_free_impl(typename, mem_ptr)
#define snt_pool_free_impl(typename, mem_ptr) \
        ___snt_pool_calloc_impl(              \
            ___snt_type_id_ ## typename,      \
            mem_ptr)


#ifdef __cplusplus
}
#endif

#endif