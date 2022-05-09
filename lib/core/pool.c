#include <sentient/core/pool.h>
#include <sentient/core/types.h>
#include <sentient/core/model_info.h>
#include <sentient/core/os_wrap.h>
void*
___sentient_pool_alloc_impl(
    const ___sentient_type_id type_id)
{
    void* mem = sentient_nullptr;
    const struct sentient_model_info* minfo =
        ___sentient_model_info_get_model_info(type_id);

    if (minfo != sentient_nullptr &&
        minfo->object_pool != sentient_nullptr)
    {
#ifdef SENTIENT_C_USE_OS
        sentient_mutex_lock(minfo->mutex);
#endif
        struct sentient_object_pool* pool =
            minfo->object_pool;
        mem = pool->pool_ptr + (minfo->actual_size * pool->current_index);
        if (minfo->pool_size + 1 == pool->current_index)
        {
            pool->current_index = 0;
        }
        else
        {
            pool->current_index = pool->current_index + 1;
        }
#ifdef SENTIENT_C_USE_OS
        sentient_mutex_unlock(minfo->mutex);
#endif
    }

    return mem;
}

void*
___sentient_pool_calloc_impl(
    const sentient_size count,
    const ___sentient_type_id type_id)
{
    void* mem = sentient_nullptr;

    const struct sentient_model_info* minfo =
        ___sentient_model_info_get_model_info(type_id);
    
    if (minfo != sentient_nullptr &&
        minfo->object_pool != sentient_nullptr)
    {
#ifdef SENTIENT_C_USE_OS
        sentient_mutex_lock(minfo->mutex);
#endif
        struct sentient_object_pool* pool =
            minfo->object_pool;
        mem = pool->pool_ptr + (minfo->actual_size * pool->current_index);
        if (pool->current_index + count > minfo->pool_size)
        {
            pool->current_index = 0;
        }
        else
        {
            pool->current_index = pool->current_index + 1;
        }
#ifdef SENTIENT_C_USE_OS
    sentient_mutex_unlock(minfo->mutex);
#endif
    }

    return mem;
}