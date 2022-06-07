#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_INC_DEC_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_INC_DEC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define ___SNT_PP_INCREASE(NUMBER) \
        ___SNT_PP_CAT(___SNT_PP_INCREASE_IMPL_, NUMBER)
#define ___SNT_PP_DECREASE(NUMBER) \
        ___SNT_PP_CAT(___SNT_PP_DECREASE_IMPL_, NUMBER)
#include <sentient/core/internal/pp_inc_dec.h>

#ifdef __cplusplus
}
#endif

#endif