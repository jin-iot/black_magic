#ifndef __SENTIENT_CORE_DEFINE_MODEL_H__
#define __SENTIENT_CORE_DEFINE_MODEL_H__

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

#define snt_define_model(...) \
        ___snt_pp_define_model(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif