#ifndef __SENTIENT_CORE_FIELD_INFO_H__
#define __SENTIENT_CORE_FIELD_INFO_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_field_info
{
    char*         field_name;
    sentient_size field_offset;
};

#ifdef __cplusplus
}
#endif

#endif