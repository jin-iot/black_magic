#include <sentient/core/model_info.h>

#include <stdlib.h>
#include <stdatomic.h>

#ifndef SENTIENT_MODEL_INFO_LIST_MAX_SIZE
#define SENTIENT_MODEL_INFO_LIST_MAX_SIZE (snt_size)128U
#endif

#include "./builtin_type_ids.h"

static
struct snt_model_info*
model_info_list[SENTIENT_MODEL_INFO_LIST_MAX_SIZE] = {
    &___snt_model_info_snt_u8,
    &___snt_model_info_snt_u16,
    &___snt_model_info_snt_u32,
    &___snt_model_info_snt_u64,
    &___snt_model_info_snt_i8,
    &___snt_model_info_snt_i16,
    &___snt_model_info_snt_i32,
    &___snt_model_info_snt_i64,
    &___snt_model_info_snt_f32,
    &___snt_model_info_snt_f64,
    &___snt_model_info_snt_str8,
    &___snt_model_info_snt_str16,
    &___snt_model_info_snt_str32,
};

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