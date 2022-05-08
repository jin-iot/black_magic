#include <sentient/core/model_info.h>

#include <stdlib.h>
#include <stdatomic.h>

#ifndef SENTIENT_MODEL_INFO_LIST_MAX_SIZE
#define SENTIENT_MODEL_INFO_LIST_MAX_SIZE (sentient_size)128U
#endif

#include "./builtin_type_ids.h"

static
struct sentient_model_info*
model_info_list[SENTIENT_MODEL_INFO_LIST_MAX_SIZE] = {
    &___sentient_model_info_sentient_u8,
    &___sentient_model_info_sentient_u16,
    &___sentient_model_info_sentient_u32,
    &___sentient_model_info_sentient_u64,
    &___sentient_model_info_sentient_i8,
    &___sentient_model_info_sentient_i16,
    &___sentient_model_info_sentient_i32,
    &___sentient_model_info_sentient_i64,
    &___sentient_model_info_sentient_f32,
    &___sentient_model_info_sentient_f64,
    &___sentient_model_info_sentient_str8,
    &___sentient_model_info_sentient_str16,
    &___sentient_model_info_sentient_str32,
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
___sentient_model_info_store_model_info(
    struct sentient_model_info* model_info,
    ___sentient_type_id type_id)
{
    model_info_list[model_info_list_size] = model_info;
    *type_id = model_info_list_size++;
}

/**
 * @brief 
 * 
 * @param type_id 
 * @return const struct sentient_model_info* 
 */
const
struct sentient_model_info*
___sentient_model_info_get_model_info(
    ___sentient_type_id type_id)
{
    return model_info_list[*type_id];
}