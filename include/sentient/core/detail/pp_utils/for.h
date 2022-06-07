#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_FOR_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_FOR_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin
 * @brief evaluates expressions in the loop
 * @date 2022-05-10
 */
#define ___SNT_PP_FOR(NUM_LOOP, START_NUMBER, INC_DEC, EXPR, ...) \
        ___SNT_PP_FOR_IMPL(NUM_LOOP, START_NUMBER, INC_DEC, EXPR, __VA_ARGS__)
#define ___SNT_PP_FOR_IMPL(NUM_LOOP, START_NUMBER, INC_DEC, EXPR, ...) \
        ___SNT_PP_CAT_4(                                               \
                ___SNT_PP_FOR_,                                        \
                INC_DEC,                                               \
                _,                                                     \
                NUM_LOOP                                               \
        ) (START_NUMBER, EXPR, __VA_ARGS__)
#include <sentient/core/internal/pp_for.h>

#ifdef __cplusplus
}
#endif

#endif