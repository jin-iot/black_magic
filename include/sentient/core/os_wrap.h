#ifndef __SENTIENT_CORE_OS_WRAP_H__
#define __SENTIENT_CORE_OS_WRAP_H__

#include <sentient/core/snt_config.h>

#ifdef SENTIENT_C_USE_OS

#ifdef SENTIENT_C_OS_POSIX
#include <pthread.h>
#endif
#ifdef SENTIENT_C_OS_ZEPHYR
#include <zephyr.h>
#endif
#ifdef SENTIENT_C_OS_RIOT
#include <mutex.h>
#endif
#ifdef SENTIENT_C_OS_MIPOS
#include <mipos/mipos_mutex.h>
#endif
#ifdef SENTIENT_C_OS_MYNEWT
#include <os/os_mutex.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef SENTIENT_C_OS_POSIX
typedef pthread_mutex_t snt_mutex_t;
#define sentinet_mutex_initializer(name) \
        snt_mutex_t name = PTHREAD_MUTEX_INITIALIZER
#define snt_mutex_lock pthread_mutex_lock
#define snt_mutex_unlock pthread_mutex_unlock
#define snt_malloc malloc
#define snt_calloc calloc
#define snt_free free
#endif
#ifdef SENTIENT_C_OS_ZEPHYR
typedef struct k_mutex snt_mutex_t;
#define sentinet_mutex_initializer(name) \
        K_MUTEX_DEFINE(name)
#define snt_mutex_lock(mtx_ptr) \
        k_mutex_lock(mtx_ptr, K_FOREVER)
#define snt_mutex_unlock k_mutex_unlock
#define snt_malloc k_malloc
#define snt_calloc k_calloc
#define snt_free k_free
#endif
#ifdef SENTIENT_C_OS_RIOT
typedef struct mutex_t snt_mutex_t;
#define sentinet_mutex_initializer(name) \
       snt_mutex_t name = MUTEX_INIT
#define snt_mutex_lock mutex_lock
#define snt_mutex_unlock mutex_unlock
#define snt_malloc malloc
#define snt_calloc calloc
#define snt_free free
#endif
#ifdef SENTIENT_C_OS_MIPOS
typedef mipos_mtx_t snt_mutex_t;
#define sentinet_mutex_initializer(name) \
       snt_mutex_t name = MU_INIT
#define snt_mutex_lock mipos_mu_lock
#define snt_mutex_unlock mipos_mu_unlock
#define snt_malloc mipos_malloc
#define snt_calloc mipos_calloc
#define snt_free mipos_free
#endif
#ifdef SENTIENT_C_OS_MYNEWT
typedef os_mutex snt_mutex_t;
#define sentinet_mutex_initializer(name) \
       snt_mutex_t name = { 0, }
#define snt_mutex_lock(mtx_ptr) \
        os_mutex_pend(mtx_ptr, OS_TIMEOUT_NEVER)
#define snt_mutex_unlock os_mutex_release
#define snt_malloc os_malloc
#define snt_calloc(count, size) \
        os_malloc(count * size)
#define snt_free os_free
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif