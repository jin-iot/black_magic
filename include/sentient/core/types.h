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
 * @author Jin
 * @brief basic types
 * 
 */

#ifndef sentient_nullptr
#define sentient_nullptr NULL
#endif

typedef uintptr_t     sentient_uptr;
typedef intptr_t      sentient_iptr;

typedef void          sentient_void;
typedef bool          sentient_bool;
typedef size_t        sentient_size;
typedef ssize_t       sentient_ssize;
typedef uint8_t       sentient_u8;
typedef uint16_t      sentient_u16;
typedef uint32_t      sentient_u32;
typedef uint64_t      sentient_u64;
typedef int8_t        sentient_i8;
typedef int16_t       sentient_i16;
typedef int32_t       sentient_i32;
typedef int64_t       sentient_i64;

typedef float         sentient_f32;
typedef double        sentient_f64;

typedef char          sentient_str8;
typedef sentient_i16  sentient_str16;
typedef sentient_i32  sentient_str32;

typedef atomic_size_t sentient_atomic_size;

#define sentient_call_once __attribute__((constructor))
#define sentient_call_once_prio(prio) __attribute__((constructor(prio)))

typedef sentient_u32 ___sentient_type_id_internal;
typedef ___sentient_type_id_internal* ___sentient_type_id;

extern const ___sentient_type_id ___sentient_type_id_sentient_u8;
extern const ___sentient_type_id ___sentient_type_id_sentient_u16;
extern const ___sentient_type_id ___sentient_type_id_sentient_u32;
extern const ___sentient_type_id ___sentient_type_id_sentient_u64;
extern const ___sentient_type_id ___sentient_type_id_sentient_i8;
extern const ___sentient_type_id ___sentient_type_id_sentient_i16;
extern const ___sentient_type_id ___sentient_type_id_sentient_i32;
extern const ___sentient_type_id ___sentient_type_id_sentient_i64;
extern const ___sentient_type_id ___sentient_type_id_sentient_f32;
extern const ___sentient_type_id ___sentient_type_id_sentient_f64;
extern const ___sentient_type_id ___sentient_type_id_sentient_str8;
extern const ___sentient_type_id ___sentient_type_id_sentient_str16;
extern const ___sentient_type_id ___sentient_type_id_sentient_str32;

typedef sentient_u8   sentient_stx8;
typedef sentient_u8   sentient_cmd8;
typedef sentient_u16  sentient_cmd16;
typedef sentient_u32  sentient_cmd32;
typedef sentient_u64  sentient_cmd64;

#include <sentient/core/internal/string_types.h>
#include <sentient/core/internal/vec_types.h>
#include <sentient/core/internal/mat_types.h>

struct sentient_subcentury_datetime32
{
	sentient_u32 year : 7;    /* [0-99] a centry */
	sentient_u32 month : 4;   /* [0-11] */
	sentient_u32 day : 5;     /* [0-31] */
	sentient_u32 hours : 5;   /* [0-11] */
	sentient_u32 minutes : 6; /* [0-59] */
	sentient_u32 seconds : 5; /* [0-29] 0-59 in 2-second intervals */
};

struct sentient_subcentury_datetime64
{
	sentient_u32 year : 7;    /* [0-99] a centry */
	sentient_u32 month : 4;   /* [0-11] */
	sentient_u32 day : 5;     /* [0-31] */
	sentient_u32 hours : 5;   /* [0-11] */
	sentient_u32 minutes : 6; /* [0-59] */
	sentient_u32 seconds : 5; /* [0-29] 0-59 in 2-second intervals */

	sentient_u32 microseconds;
};

struct timespec128
{
	sentient_u64 seconds;
	sentient_u64 microseconds;
};

typedef sentient_u64                          sentient_posix_time64;

typedef struct sentient_subcentury_datetime32 sentient_scdt32;
typedef struct sentient_subcentury_datetime64 sentient_scdt64;
typedef sentient_posix_time64                 sentient_pt64;
typedef struct sentient_timespec128           sentient_ts128;

bool sentient_scdt32_local_now(sentient_scdt32*);
bool sentient_scdt64_local_now(sentient_scdt64*);
bool sentient_pt64_local_now(sentient_pt64*);
bool sentient_ts128_local_now(sentient_ts128*);
bool sentient_scdt32_utc_now(sentient_scdt32*);
bool sentient_scdt64_utc_now(sentient_scdt64*);
bool sentient_pt64_utc_now(sentient_pt64*);
bool sentient_ts128_utc_now(sentient_ts128*);
bool sentient_get_tm_from_scdt32(struct tm*, sentient_scdt32*);
bool sentient_get_scdt32_from_tm(sentient_scdt32*, struct tm*);
bool sentient_get_tm_from_scdt64(struct tm*, sentient_scdt32*);
bool sentient_get_scdt64_from_tm(sentient_scdt32*, struct tm*);

#ifdef __cplusplus
}
#endif

#endif