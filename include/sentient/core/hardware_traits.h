#ifndef __SENTIENT_CORE_HARDWARE_TRAITS_H__
#define __SENTIENT_CORE_HARDWARE_TRAITS_H__

/**
 * @file hardware_traits.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief determines hardware concurrency by predefined macros
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sentient/core/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __x86_64__
#define SENTIENT_MULTIPROCESSING 1
#define SENTIENT_CACHELINE_SIZE (snt_size)64U
#elif __ARM__
#define SENTIENT_MULTIPROCESSING 1
#define SENTIENT_CACHELINE_SIZE (snt_size)64U
#else
#define SENTIENT_MULTIPROCESSING 1
#define SENTIENT_CACHELINE_SIZE (snt_size)64U
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SENTIENT_CORE_HARDWARE_TRAITS_H__