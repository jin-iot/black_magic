#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_COUNT_ARGS_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_COUNT_ARGS_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief for count args
 * @date 2022-05-04
 */
#include <sentient/core/internal/pp_args.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the args have comma
 * @date 2022-05-06
 */
#define ___SNT_PP_HAS_COMMA(...) \
        ___SNT_PP_HAS_COMMA_IMPL(__VA_ARGS__)
#include <sentient/core/internal/pp_has_comma.h>

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief counts number of tokens
 * @date 2022-05-04
 */
#define ___SNT_PP_COUNT_ARGS(...) \
        ___SNT_PP_COUNT_ARGS_IMPL(0, ## __VA_ARGS__)
#include <sentient/core/internal/pp_count_args.h>

#ifdef __cplusplus
}
#endif

#endif