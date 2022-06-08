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
#include <sentient/core/detail/decl_model/decl_reserved_keyword.h>
#include <sentient/core/detail/decl_model/decl_object_pool.h>
#include <sentient/core/detail/decl_model/decl_field.h>
#include <sentient/core/detail/decl_model/decl_model.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef SNT_IMPL_MODEL
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