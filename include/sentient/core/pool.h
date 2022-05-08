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

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_object_pool
{
    sentient_atomic_size current_index;
    sentient_atomic_size using_index;
    sentient_void*       pool_ptr;
};

void*
___sentient_pool_alloc_impl(
    const ___sentient_type_id type_id);

void*
___sentient_pool_calloc_impl(
    const sentient_size count,
    const ___sentient_type_id type_id);

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief similar to malloc
 * 
 * @param type_id 
 * @return void* 
 */
#define sentient_pool_alloc(typename) \
        sentient_pool_alloc_impl(typename)
#define sentient_pool_alloc_impl(typename) \
        ___sentient_pool_alloc_impl(       \
        ___sentient_type_id_ ## typename)

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief similar to calloc
 * 
 * @param count 
 * @param type_id 
 * @return void* 
 */
#define sentient_pool_calloc(typename) \
        sentient_pool_calloc_impl(count, typename)
#define sentient_pool_calloc_impl(count, typename) \
        ___sentient_pool_calloc_impl(              \
            count,                                 \
            ___sentient_type_id_ ## typename)

#ifdef __cplusplus
}
#endif

#endif