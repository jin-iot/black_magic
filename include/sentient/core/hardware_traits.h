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

#else

#ifdef __arm__
#if __TARGET_FEATURE_MULTIPROCESSING
#define SENTIENT_MULTIPROCESSING 1
#define SENTIENT_CACHELINE_SIZE (snt_size)64U

#ifdef __TARGET_CPU_CORTEX_A5
#define SENTIENT_CACHELINE_SIZE (snt_size)32U
#endif

#ifdef __TARGET_CPU_CORTEX_A7
#define SENTIENT_CACHELINE_SIZE (snt_size)64U
#endif

#ifdef __TARGET_CPU_CORTEX_A8
#define SENTIENT_CACHELINE_SIZE (snt_size)64U
#endif

#ifdef __TARGET_CPU_CORTEX_A9
#define SENTIENT_CACHELINE_SIZE (snt_size)32U
#endif

#ifdef __TARGET_CPU_CORTEX_A15
#define SENTIENT_CACHELINE_SIZE (snt_size)64U
#endif

#endif // __TARGET_FEATURE_MULTIPROCESSING

#else

#define SENTIENT_MULTIPROCESSING 

#endif // __arm__

#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SENTIENT_CORE_HARDWARE_TRAITS_H__