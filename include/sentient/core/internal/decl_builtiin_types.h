#ifndef __SENTIENT_CORE_INTERNAL_DECL_BUILTIN_TYPES_H__
#define __SENTIENT_CORE_INTERNAL_DECL_BUILTIN_TYPES_H__

#include <sentient/core/types.h>
#include <sentient/core/model_info.h>
#include <sentient/core/decl_model.h>

#ifdef __cplusplus
extern "C"
{
#endif

___snt_type_id ___snt_type_id_snt_u8;
static
struct snt_model_info
___snt_model_info_snt_u8 = {
    .model_name = "snt_u8",
};
static inline
void __attribute__((constructor)) ___snt_type_init_snt_u8(void)
{
    ___snt_model_info_store_model_info(
        &___snt_model_info_snt_u8,
        ___snt_type_id_snt_u8);
}
___snt_type_id ___snt_type_id_snt_u16;
___snt_type_id ___snt_type_id_snt_u32;
___snt_type_id ___snt_type_id_snt_u64;

#ifdef __cplusplus
}
#endif

#endif