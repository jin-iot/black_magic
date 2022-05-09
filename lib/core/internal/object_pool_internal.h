#ifndef __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__
#define __SENTIENT_LIB_INTERNAL_OBJECT_POOL_INTERNAL_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_lockfree_queue_elem
{
    sentient_uptr ptr;
    sentient_uptr ref;
};

#ifdef __cplusplus
}
#endif

#endif