#ifndef __SENTIENT_CORE_FIELD_INFO_H__
#define __SENTIENT_CORE_FIELD_INFO_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct snt_field_info
{
    snt_str8*            field_name;
    const ___snt_type_id type_id;
    snt_size             field_offset;
    snt_size             array_size;
    snt_bool             is_unique;
    snt_bool             is_bit_field;
    snt_bool             is_pointer;
    snt_bool             is_primary_key;
    snt_bool             is_time;
    snt_bool             is_auto_increment;
};

#ifdef __cplusplus
}
#endif

#endif