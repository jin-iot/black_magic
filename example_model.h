#ifndef __EXAMPLE_MODEL_H__
#define __EXAMPLE_MODEL_H__

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct example_model
{
    snt_u8 number;
    snt_u32 children_size;
    struct example_model* children;
};

extern const ___snt_type_id ___type_id_example_model;

#ifdef __cplusplus
}
#endif

#endif