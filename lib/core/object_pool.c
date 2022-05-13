#include <sentient/core/object_pool.h>

#include <sentient/core/types.h>
#include <sentient/core/model_info.h>
#include <sentient/core/os_wrap.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief 
 * 
 * @param type_id 
 * @return snt_void* 
 */
snt_void*
___snt_pool_alloc_impl(
    const ___snt_type_id type_id)
{
    void* mem = snt_nullptr;
    const struct snt_model_info* minfo =
        ___snt_model_info_get_model_info(type_id);

    if (minfo != snt_nullptr &&
        minfo->object_pool != snt_nullptr)
    {
        struct snt_object_pool* pool =
            minfo->object_pool;
    }

    return mem;
}

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief 
 * 
 * @param count 
 * @param type_id 
 * @return snt_void* 
 */
snt_void*
___snt_pool_calloc_impl(
    const snt_size count,
    const ___snt_type_id type_id)
{
    void* mem = snt_nullptr;

    const struct snt_model_info* minfo =
        ___snt_model_info_get_model_info(type_id);
    
    if (minfo != snt_nullptr &&
        minfo->object_pool != snt_nullptr)
    {
        struct snt_object_pool* pool =
            minfo->object_pool;
    }

    return mem;
}

snt_void
___snt_pool_free_impl(
    const ___snt_type_id type_id,
    snt_void* mem)
{

}