#ifndef __SENTIENT_CORE_C_TYPES_H__
#define __SENTIENT_CORE_C_TYPES_H__

/**
 * @file types.h
 * @author Jin (jaehwanspin@gmail.com)
 * @brief General basic types definitions
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <float.h>
#include <time.h>

// so, donut(do not) use the MSVC compiler
#include <sys/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief basic types
 * 
 */

#define snt_nullptr NULL

#define snt_atomic _Atomic

typedef uintptr_t                          snt_uptr;
typedef intptr_t                           snt_iptr;

typedef void                               snt_void;
typedef bool                               snt_bool;
typedef size_t                             snt_size;
typedef ssize_t                            snt_ssize;
typedef uint8_t                            snt_u8;
typedef uint16_t                           snt_u16;
typedef uint32_t                           snt_u32;
typedef uint64_t                           snt_u64;
typedef int8_t                             snt_i8;
typedef int16_t                            snt_i16;
typedef int32_t                            snt_i32;
typedef int64_t                            snt_i64;


typedef float                              snt_f32;
typedef double                             snt_f64;

typedef char                               snt_str8;
typedef snt_i16                       snt_str16;
typedef snt_i32                       snt_str32;

typedef snt_atomic snt_uptr      snt_atomic_uptr;
typedef snt_atomic snt_iptr      snt_atomic_iptr;

typedef snt_atomic snt_size      snt_atomic_size;
typedef snt_atomic snt_bool      snt_atomic_bool;
typedef snt_atomic snt_u8        snt_atomic_u8;
typedef snt_atomic snt_u16       snt_atomic_u16;
typedef snt_atomic snt_u32       snt_atomic_u32;
typedef snt_atomic snt_u64       snt_atomic_u64;
typedef snt_atomic snt_i8        snt_atomic_i8;
typedef snt_atomic snt_i16       snt_atomic_i16;
typedef snt_atomic snt_i32       snt_atomic_i32;
typedef snt_atomic snt_i64       snt_atomic_i64;

typedef snt_atomic snt_f32       snt_atomic_f32;
typedef snt_atomic snt_f64       snt_atomic_f64;

#define snt_call_once __attribute__((constructor))
#define snt_call_once_prio(prio) __attribute__((constructor(prio)))

typedef snt_u32 ___snt_type_id_internal;
typedef ___snt_type_id_internal* ___snt_type_id;

extern ___snt_type_id ___snt_type_id_snt_u8;
extern ___snt_type_id ___snt_type_id_snt_u16;
extern ___snt_type_id ___snt_type_id_snt_u32;
extern ___snt_type_id ___snt_type_id_snt_u64;
extern ___snt_type_id ___snt_type_id_snt_i8;
extern ___snt_type_id ___snt_type_id_snt_i16;
extern ___snt_type_id ___snt_type_id_snt_i32;
extern ___snt_type_id ___snt_type_id_snt_i64;
extern ___snt_type_id ___snt_type_id_snt_f32;
extern ___snt_type_id ___snt_type_id_snt_f64;
extern ___snt_type_id ___snt_type_id_snt_str8;
extern ___snt_type_id ___snt_type_id_snt_str16;
extern ___snt_type_id ___snt_type_id_snt_str32;

typedef snt_u8   snt_stx8;
typedef snt_u8   snt_cmd8;
typedef snt_u16  snt_cmd16;
typedef snt_u32  snt_cmd32;
typedef snt_u64  snt_cmd64;

#include <sentient/core/internal/string_types.h>
#include <sentient/core/internal/vec_types.h>
#include <sentient/core/internal/mat_types.h>

struct snt_subcentury_datetime32
{
	snt_u32 year : 7;    /* [0-99] a centry */
	snt_u32 month : 4;   /* [0-11] */
	snt_u32 day : 5;     /* [0-31] */
	snt_u32 hours : 5;   /* [0-11] */
	snt_u32 minutes : 6; /* [0-59] */
	snt_u32 seconds : 5; /* [0-29] 0-59 in 2-second intervals */
};

struct snt_subcentury_datetime64
{
	snt_u32 year : 7;    /* [0-99] a centry */
	snt_u32 month : 4;   /* [0-11] */
	snt_u32 day : 5;     /* [0-31] */
	snt_u32 hours : 5;   /* [0-11] */
	snt_u32 minutes : 6; /* [0-59] */
	snt_u32 seconds : 5; /* [0-29] 0-59 in 2-second intervals */

	snt_u32 microseconds;
};

struct timespec128
{
	snt_u64 seconds;
	snt_u64 microseconds;
};

typedef snt_u64                          snt_posix_time64;

typedef struct snt_subcentury_datetime32 snt_scdt32;
typedef struct snt_subcentury_datetime64 snt_scdt64;
typedef snt_posix_time64                 snt_pt64;
typedef struct snt_timespec128           snt_ts128;

bool snt_scdt32_local_now(snt_scdt32*);
bool snt_scdt64_local_now(snt_scdt64*);
bool snt_pt64_local_now(snt_pt64*);
bool snt_ts128_local_now(snt_ts128*);
bool snt_scdt32_utc_now(snt_scdt32*);
bool snt_scdt64_utc_now(snt_scdt64*);
bool snt_pt64_utc_now(snt_pt64*);
bool snt_ts128_utc_now(snt_ts128*);
bool snt_get_tm_from_scdt32(struct tm*, snt_scdt32*);
bool snt_get_scdt32_from_tm(snt_scdt32*, struct tm*);
bool snt_get_tm_from_scdt64(struct tm*, snt_scdt32*);
bool snt_get_scdt64_from_tm(snt_scdt32*, struct tm*);

#ifdef __cplusplus
}
#endif

#endif