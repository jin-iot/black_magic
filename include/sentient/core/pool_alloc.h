#ifndef __SENTIENT_CORE_POOL_ALLOC_H__
#define __SENTIENT_CORE_POOL_ALLOC_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

void*
___sentient_pool_alloc_impl(
    ___sentient_type_id type_id);

void*
___sentient_pool_calloc_impl(
    sentient_size count,
    ___sentient_type_id type_id);

#define sentient_pool_alloc(typename) \
        sentient_pool_alloc_impl(typename)
#define sentient_pool_alloc_impl(typename)
        ___sentient_pool_alloc_impl()

#define sentient_pool_calloc(typename) \
        sentient_pool_calloc_impl(count, typename)

#ifdef __cplusplus
}
#endif

#endif