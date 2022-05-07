#include <sentient/core/model_info.h>

#include <stdlib.h>
#include <stdatomic.h>

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_u8;
const ___sentient_type_id
___sentient_type_id_sentient_u8 =
    &___sentient_type_id_internal_sentient_u8;
static
struct sentient_model_info
___sentient_model_info_sentient_u8 = {
    .model_name = "u8",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_u8),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_u16;
const ___sentient_type_id
___sentient_type_id_sentient_u16 =
    &___sentient_type_id_internal_sentient_u16;
static
struct sentient_model_info
___sentient_model_info_sentient_u16 = {
    .model_name = "u16",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_u16),
};


#ifndef SENTIENT_MODEL_INFO_LIST_MAX_SIZE
#define SENTIENT_MODEL_INFO_LIST_MAX_SIZE (sentient_size)128U
#endif

static
struct sentient_model_info*
model_info_list[SENTIENT_MODEL_INFO_LIST_MAX_SIZE];

static
atomic_size_t
model_info_list_size = 0;

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