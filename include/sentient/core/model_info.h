#ifndef __SENTIENT_CORE_MODEL_INFO_H__
#define __SENTIENT_CORE_MODEL_INFO_H__

/**
 * @file model_info.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sentient/core/types.h>
#include <sentient/core/snt_config.h>
#include <sentient/core/os_wrap.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct snt_field_info;
struct snt_object_pool;

struct snt_model_info
{
    snt_str8*               model_name;
    snt_size                actual_size;
    snt_size                fields_count;
    struct snt_field_info*  fields_info;
    snt_size                pool_size;
    struct snt_object_pool* object_pool;
#ifdef SENTIENT_C_USE_OS
    snt_mutex_t*            mutex;
#endif
};

void
___snt_model_info_store_model_info(
    struct snt_model_info* model_info,
    ___snt_type_id type_id);

const
struct snt_model_info*
___snt_model_info_get_model_info(
    const ___snt_type_id type_id);


#ifdef __cplusplus
}
#endif

#endif