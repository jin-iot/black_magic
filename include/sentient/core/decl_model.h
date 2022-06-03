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

#ifdef SNT_MODEL_IMPL
#define SNT_DECL_MODEL(...) \
        ___SNT_PP_IMPL_MODEL(__VA_ARGS__)
#else
#define SNT_DECL_MODEL(...) \
        ___SNT_PP_DECL_MODEL(__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif

#endif