#ifndef __EXAMPLE_MODEL_H__
#define __EXAMPLE_MODEL_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct example_model
{
    sentient_u8 number;
    sentient_u32 children_size;
    struct example_model* children;
};

extern const ___sentient_type_id ___type_id_example_model;

#ifdef __cplusplus
}
#endif

#endif