#ifndef __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__
#define __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

void
sentient_object_pool_push(
    struct sentient_object_pool* pool,
    sentient_atomic_uptr ptr);

sentient_atomic_uptr
sentient_object_pool_pop(
    struct sentient_object_pool* pool);

#ifdef __cplusplus
}
#endif

#endif