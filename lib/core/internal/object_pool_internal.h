#ifndef __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__
#define __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__

#include <sentient/core/types.h>
#include <sentient/core/object_pool.h>

#ifdef __cplusplus
extern "C"
{
#endif

sentient_bool
sentient_object_pool_push(
    struct sentient_object_pool* pool,
    sentient_void* ptr);

sentient_bool
sentient_object_pool_pop(
    struct sentient_object_pool* pool,
    sentient_void** ptr);

#ifdef __cplusplus
}
#endif

#endif