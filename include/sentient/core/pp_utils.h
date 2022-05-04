#ifndef __SENTIENT_CORE_PP_UTILS_H__
#define __SENTIENT_CORE_PP_UTILS_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define ___sentient_pp_cat(x, y) x ## y

#include <sentient/core/internal/pp_inc_dec.h>
#define ___sentient_pp_increase(number) \
        ___sentient_pp_cat(___sentient_pp_increase_impl_, number)

#ifdef __cplusplus
}
#endif

#endif