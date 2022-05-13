#ifndef __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__
#define __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__

#include <sentient/core/types.h>
#include <sentient/core/object_pool.h>

#ifdef __cplusplus
extern "C"
{
#endif

snt_bool
snt_object_pool_push(
    struct snt_object_pool* pool,
    snt_void* ptr);

snt_bool
snt_object_pool_pop(
    struct snt_object_pool* pool,
    snt_void** ptr);

#ifdef __cplusplus
}
#endif

#endif