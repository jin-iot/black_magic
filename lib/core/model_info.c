#include <sentient/core/model_info.h>

#include <stdlib.h>
#include <stdatomic.h>

#ifndef SENTIENT_MODEL_INFO_LIST_MAX_SIZE
#define SENTIENT_MODEL_INFO_LIST_MAX_SIZE (snt_size)128U
#endif

static
struct snt_model_info*
model_info_list[SENTIENT_MODEL_INFO_LIST_MAX_SIZE] = { 0, };

static
atomic_size_t
model_info_list_size = 13;

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief stores a model info when the program starts
 * 
 * @param model_info 
 * @param type_id 
 */
void
___snt_model_info_store_model_info(
    struct snt_model_info* model_info,
    ___snt_type_id type_id)
{
    model_info_list[model_info_list_size] = model_info;
    *type_id = model_info_list_size++;
}

/**
 * @brief 
 * 
 * @param type_id 
 * @return const struct snt_model_info* 
 */
const
struct snt_model_info*
___snt_model_info_get_model_info(
    const ___snt_type_id type_id)
{
    return model_info_list[*type_id];
}