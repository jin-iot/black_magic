#ifndef __SENTIENT_CORE_FIELD_INFO_H__
#define __SENTIENT_CORE_FIELD_INFO_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_field_info
{
    sentient_str8*            field_name;
    const ___sentient_type_id type_id;
    sentient_size             field_offset;
    sentient_size             array_size;
    sentient_bool             is_pointer;
    sentient_bool             is_primary_key;
};

#ifdef __cplusplus
}
#endif

#endif