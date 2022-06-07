#ifndef __EXAMPLE_MODEL_H__
#define __EXAMPLE_MODEL_H__

#include <sentient/core/decl_model.h>

#ifdef __cplusplus
extern "C"
{
#endif

SNT_DECL_MODEL(oioi,,
    (snt_u32, model_num),
    (snt_str8, name, SNT_ARRAY, 30),
    (snt_u32, hey, SNT_BIT_FIELD, 16),
    (snt_u32, howru, SNT_BIT_FIELD, 16)
)

#ifdef __cplusplus
}
#endif

#endif