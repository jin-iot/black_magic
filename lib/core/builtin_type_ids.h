#ifndef __SENTIENT_LIB_BUILTIN_TYPE_IDS_H__
#define __SENTIENT_LIB_BUILTIN_TYPE_IDS_H__

#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>

#ifdef SENTIENT_C_USE_POOL
#include <sentient/core/object_pool.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define ___sentient_def_builtin_type(typename, id_idx)       \
        static                                               \
        ___sentient_type_id_internal                         \
        ___sentient_type_id_internal_ ## typename = id_idx ; \
        static                                               \
        ___sentient_type_id                                  \
        ___sentient_type_id_ ## typename =                   \
            &___sentient_type_id_internal_ ## typename ;     \
        static                                               \
        struct sentient_model_info                           \
        ___sentient_model_info_ ## typename = {              \
            .model_name = #typename ,                        \
            .fields_count = 0,                               \
            .fields_info = sentient_nullptr,                 \
            .actual_size = sizeof( typename ),               \
        };



static
struct sentient_object_pool
___sentient_object_pool_sentient_u8 = {
  
};
static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_u8 = 0;
const ___sentient_type_id
___sentient_type_id_sentient_u8 =
    &___sentient_type_id_internal_sentient_u8;
static
struct sentient_model_info
___sentient_model_info_sentient_u8 = {
    .model_name = "sentient_u8",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_u8),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_u16 = 1;
const ___sentient_type_id
___sentient_type_id_sentient_u16 =
    &___sentient_type_id_internal_sentient_u16;
static
struct sentient_model_info
___sentient_model_info_sentient_u16 = {
    .model_name = "sentient_u16",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_u16),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_u32 = 2;
const ___sentient_type_id
___sentient_type_id_sentient_u32 =
    &___sentient_type_id_internal_sentient_u32;
static
struct sentient_model_info
___sentient_model_info_sentient_u32 = {
    .model_name = "sentient_u32",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_u32),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_u64 = 3;
const ___sentient_type_id
___sentient_type_id_sentient_u64 =
    &___sentient_type_id_internal_sentient_u64;
static
struct sentient_model_info
___sentient_model_info_sentient_u64 = {
    .model_name = "sentient_u64",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_u64),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_i8 = 4;
const ___sentient_type_id
___sentient_type_id_sentient_i8 =
    &___sentient_type_id_internal_sentient_i8;
static
struct sentient_model_info
___sentient_model_info_sentient_i8 = {
    .model_name = "sentient_i8",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_i8),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_i16 = 5;
const ___sentient_type_id
___sentient_type_id_sentient_i16 =
    &___sentient_type_id_internal_sentient_i16;
static
struct sentient_model_info
___sentient_model_info_sentient_i16 = {
    .model_name = "sentient_i16",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_i16),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_i32 = 6;
const ___sentient_type_id
___sentient_type_id_sentient_i32 =
    &___sentient_type_id_internal_sentient_i32;
static
struct sentient_model_info
___sentient_model_info_sentient_i32 = {
    .model_name = "sentient_i32",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_i32),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_i64 = 7;
const ___sentient_type_id
___sentient_type_id_sentient_i64 =
    &___sentient_type_id_internal_sentient_i64;
static
struct sentient_model_info
___sentient_model_info_sentient_i64 = {
    .model_name = "sentient_i64",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_i64),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_f32 = 8;
const ___sentient_type_id
___sentient_type_id_sentient_f32 =
    &___sentient_type_id_internal_sentient_f32;
static
struct sentient_model_info
___sentient_model_info_sentient_f32 = {
    .model_name = "sentient_f32",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_f32),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_f64 = 9;
const ___sentient_type_id
___sentient_type_id_sentient_f64 =
    &___sentient_type_id_internal_sentient_f64;
static
struct sentient_model_info
___sentient_model_info_sentient_f64 = {
    .model_name = "sentient_f64",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_f64),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_str8 = 10;
const ___sentient_type_id
___sentient_type_id_sentient_str8 =
    &___sentient_type_id_internal_sentient_str8;
static
struct sentient_model_info
___sentient_model_info_sentient_str8 = {
    .model_name = "sentient_str8",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_str8),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_str16 = 11;
const ___sentient_type_id
___sentient_type_id_sentient_str16 =
    &___sentient_type_id_internal_sentient_str16;
static
struct sentient_model_info
___sentient_model_info_sentient_str16 = {
    .model_name = "sentient_str16",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_str16),
};

static
___sentient_type_id_internal
___sentient_type_id_internal_sentient_str32 = 12;
const ___sentient_type_id
___sentient_type_id_sentient_str32 =
    &___sentient_type_id_internal_sentient_str32;
static
struct sentient_model_info
___sentient_model_info_sentient_str32 = {
    .model_name = "sentient_str32",
    .fields_count = 0,
    .fields_info = sentient_nullptr,
    .actual_size = sizeof(sentient_str32),
};

#ifdef __cplusplus
extern "C"
}
#endif

#endif