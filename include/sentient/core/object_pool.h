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
#include <sentient/core/sentient_config.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_object_pool_elem;

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief object pool descriptor
 */
struct sentient_object_pool
{
    sentient_atomic_size              pool_size;
    struct sentient_object_pool_elem* pool_elem;
    sentient_uptr                     rear;
    sentient_uptr                     front;

};

sentient_void*
___sentient_pool_alloc_impl(
    const ___sentient_type_id type_id);

sentient_void*
___sentient_pool_calloc_impl(
    const sentient_size count,
    const ___sentient_type_id type_id);

sentient_void
___sentient_pool_free_impl(
    const ___sentient_type_id type_id,
    sentient_void* mem);

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

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief free pool memory
 * 
 * @param type_id 
 * @param mem 
 * @return sentient_void 
 */
#define sentient_pool_free(typename, mem_ptr) \
        sentient_pool_free_impl(typename, mem_ptr)
#define sentient_pool_free_impl(typename, mem_ptr) \
        ___sentient_pool_calloc_impl(              \
            ___sentient_type_id_ ## typename,      \
            mem_ptr)


#ifdef __cplusplus
}
#endif

#endif