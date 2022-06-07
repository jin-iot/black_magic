#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>
#include <string.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/object_pool.h>
#include <sentient/core/decl_model.h>

#include "example_model.h"

thrd_t threads[4] = { 0, };

struct example_model
{
    snt_u32 number;
    snt_u32 val;
};

snt_i32 thread_handler(snt_void* arg)
{

    printf("thread %ld\n", thrd_current());
}

#define def_num(num, type, name) \
        const type name ## _ ## num = num ;
#define def_num_iter(num, type, name) \
        ___snt_pp_for(5, num, type, name)

// struct bf_model
// {
//     ___SNT_PP_DECL_FIELD((snt_u32, num, 32))
//     SNT_DECL_BIT_FIELD(
//         (snt_u32, a1, 1),
//         (snt_u32, a2, 1),
//         (snt_u32, a3, 1),
//         (snt_u32, a4, 1)
//     )
// };


___SNT_PP_DECL_OBJECT_POOL_STORAGE(snt_u32, PRIMITIVE)

// SNT_DECL_MODEL(oioi,,
//     (snt_u32, model_num),
//     (snt_str8, name, SNT_ARRAY, 30),
//     (snt_u32, hey, SNT_BIT_FIELD, 16),
//     (snt_u32, howru, SNT_BIT_FIELD, 16)
// )


int main(int argc, char** argv)
{
    struct oioi oioi = {
        .model_num = 123,
        .name = u8"jin",
        .hey = 123,
        .howru = 1234,
    };

    const snt_size iya = ___SNT_PP_COUNT_ARGS(
        (snt_u32, model_num),
        (snt_str8, name, SNT_ARRAY, 30),
        (snt_u32, hey, SNT_BIT_FIELD, 16),
        (snt_u32, howru, SNT_BIT_FIELD, 16),
        (hey(123), oioi(123))
    );



    const snt_size sizee = sizeof(struct oioi);

    // const snt_size ahah = ___SNT_PP_COUNT_ARGS(FIELD(snt_u32, num), FIELD(snt_str8, name, 30))
    
    int res = EXIT_SUCCESS;

    for (snt_i32 i = 0; i < 4; i++)
    {
        int err = thrd_create(&threads[i],
                              thread_handler,
                              snt_nullptr);

        if (err < 0)
        {
            res = EXIT_FAILURE;
            goto exit_label;
        }
    }

    for (snt_i32 i = 0; i < 4; i++)
    {
        thrd_join(threads[i],
                  snt_nullptr);
    }

exit_label:
	return 0;
}