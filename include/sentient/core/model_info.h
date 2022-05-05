#ifndef __SENTIENT_CORE_MODEL_INFO_H__
#define __SENTIENT_CORE_MODEL_INFO_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct sentient_field_info;

struct sentient_model_info
{
    char* model_name;
    sentient_size               fields_count;
    struct sentient_field_info* fields_info;
};

#ifdef __cplusplus
}
#endif

#endif