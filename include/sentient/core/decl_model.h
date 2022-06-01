#ifndef __SENTIENT_CORE_DECL_MODEL_H__
#define __SENTIENT_CORE_DECL_MODEL_H__

/**
 * @file define_model.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief defines a macro that defines a model and stores the type info
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sentient/core/types.h>
#include <sentient/core/pp_utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define SNT_DECL_MODEL(...) \
        ___SNT_PP_DECL_MODEL(__VA_ARGS__)

#define SNT_DECL_BIT_FIELD(...) \
        ___SNT_PP_DECL_BIT_FIELD(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif