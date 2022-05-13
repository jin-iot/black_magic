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

#define ___snt_def_builtin_type(typename, id_idx)       \
        static                                               \
        ___snt_type_id_internal                         \
        ___snt_type_id_internal_ ## typename = id_idx ; \
        static                                               \
        ___snt_type_id                                  \
        ___snt_type_id_ ## typename =                   \
            &___snt_type_id_internal_ ## typename ;     \
        static                                               \
        struct snt_model_info                           \
        ___snt_model_info_ ## typename = {              \
            .model_name = #typename ,                        \
            .fields_count = 0,                               \
            .fields_info = snt_nullptr,                 \
            .actual_size = sizeof( typename ),               \
        };



static
struct snt_object_pool
___snt_object_pool_snt_u8 = {
  
};
static
___snt_type_id_internal
___snt_type_id_internal_snt_u8 = 0;
const ___snt_type_id
___snt_type_id_snt_u8 =
    &___snt_type_id_internal_snt_u8;
static
struct snt_model_info
___snt_model_info_snt_u8 = {
    .model_name = "snt_u8",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_u8),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_u16 = 1;
const ___snt_type_id
___snt_type_id_snt_u16 =
    &___snt_type_id_internal_snt_u16;
static
struct snt_model_info
___snt_model_info_snt_u16 = {
    .model_name = "snt_u16",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_u16),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_u32 = 2;
const ___snt_type_id
___snt_type_id_snt_u32 =
    &___snt_type_id_internal_snt_u32;
static
struct snt_model_info
___snt_model_info_snt_u32 = {
    .model_name = "snt_u32",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_u32),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_u64 = 3;
const ___snt_type_id
___snt_type_id_snt_u64 =
    &___snt_type_id_internal_snt_u64;
static
struct snt_model_info
___snt_model_info_snt_u64 = {
    .model_name = "snt_u64",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_u64),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_i8 = 4;
const ___snt_type_id
___snt_type_id_snt_i8 =
    &___snt_type_id_internal_snt_i8;
static
struct snt_model_info
___snt_model_info_snt_i8 = {
    .model_name = "snt_i8",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_i8),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_i16 = 5;
const ___snt_type_id
___snt_type_id_snt_i16 =
    &___snt_type_id_internal_snt_i16;
static
struct snt_model_info
___snt_model_info_snt_i16 = {
    .model_name = "snt_i16",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_i16),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_i32 = 6;
const ___snt_type_id
___snt_type_id_snt_i32 =
    &___snt_type_id_internal_snt_i32;
static
struct snt_model_info
___snt_model_info_snt_i32 = {
    .model_name = "snt_i32",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_i32),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_i64 = 7;
const ___snt_type_id
___snt_type_id_snt_i64 =
    &___snt_type_id_internal_snt_i64;
static
struct snt_model_info
___snt_model_info_snt_i64 = {
    .model_name = "snt_i64",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_i64),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_f32 = 8;
const ___snt_type_id
___snt_type_id_snt_f32 =
    &___snt_type_id_internal_snt_f32;
static
struct snt_model_info
___snt_model_info_snt_f32 = {
    .model_name = "snt_f32",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_f32),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_f64 = 9;
const ___snt_type_id
___snt_type_id_snt_f64 =
    &___snt_type_id_internal_snt_f64;
static
struct snt_model_info
___snt_model_info_snt_f64 = {
    .model_name = "snt_f64",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_f64),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_str8 = 10;
const ___snt_type_id
___snt_type_id_snt_str8 =
    &___snt_type_id_internal_snt_str8;
static
struct snt_model_info
___snt_model_info_snt_str8 = {
    .model_name = "snt_str8",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_str8),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_str16 = 11;
const ___snt_type_id
___snt_type_id_snt_str16 =
    &___snt_type_id_internal_snt_str16;
static
struct snt_model_info
___snt_model_info_snt_str16 = {
    .model_name = "snt_str16",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_str16),
};

static
___snt_type_id_internal
___snt_type_id_internal_snt_str32 = 12;
const ___snt_type_id
___snt_type_id_snt_str32 =
    &___snt_type_id_internal_snt_str32;
static
struct snt_model_info
___snt_model_info_snt_str32 = {
    .model_name = "snt_str32",
    .fields_count = 0,
    .fields_info = snt_nullptr,
    .actual_size = sizeof(snt_str32),
};

#ifdef __cplusplus
extern "C"
}
#endif

#endif