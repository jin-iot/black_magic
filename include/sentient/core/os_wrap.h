#ifndef __SENTIENT_CORE_OS_WRAP_H__
#define __SENTIENT_CORE_OS_WRAP_H__

#include <sentient/core/sentient_config.h>

#ifdef SENTIENT_C_USE_OS

#ifdef SENTIENT_C_OS_POSIX
#include <pthread.h>
#endif
#ifdef SENTIENT_C_OS_ZEPHYR
#include <zephyr.h>
#endif
#ifdef SENTIENT_C_OS_MBED
#include "mbed.h"
#endif
#ifdef SENTIENT_C_OS_RIOT
#include <mutex.h>
#endif
#ifdef SENTIENT_C_OS_FREERTOS
#include "FreeRTOS.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef SENTIENT_C_OS_POSIX
typedef pthread_mutex_t sentient_mutex_t;
#define sentinet_mutex_initializer(name) \
        sentient_mutex_t name = PTHREAD_MUTEX_INITIALIZER
#define sentient_mutex_lock pthread_mutex_lock
#define sentient_mutex_unlock pthread_mutex_unlock
#endif
#ifdef SENTIENT_C_OS_ZEPHYR
typedef struct k_mutex sentient_mutex_t;
#define sentinet_mutex_initializer(name) \
        K_MUTEX_DEFINE(name)
#define sentient_mutex_lock k_mutex_lock
#define sentient_mutex_unlock k_mutex_unlock
#endif
#ifdef SENTIENT_C_OS_RIOT
#include <mutex.h>
typedef struct mutex_t sentient_mutex_t;
#define sentinet_mutex_initializer(name) \
       sentient_mutex_t name = MUTEX_INIT
#define sentient_mutex_lock mutex_lock
#define sentient_mutex_unlock mutex_unlock
#endif
#ifdef SENTIENT_C_OS_MIPOS
#include <mipos/mipos_mutex.h>
typedef mipos_mtx_t sentient_mutex_t;
#define sentinet_mutex_initializer(name) \
       sentient_mutex_t name = MU_INIT
#define sentient_mutex_lock mipos_mu_lock
#define sentient_mutex_unlock mipos_mu_unlock
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif