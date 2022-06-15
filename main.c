#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>
#include <string.h>
#include <time.h>

#include <sentient/core/types.h>

#include "example_model.h"

thrd_t threads[4] = { 0, };

snt_i32 thread_handler(snt_void* arg)
{
    printf("thread %ld\n", thrd_current());
}

___SNT_PP_DECL_OBJECT_POOL_STORAGE(snt_i32, SNT_PRIMITIVE)

int main(int argc, char** argv)
{
    const snt_bool fucking = __builtin_types_compatible_p(void*, void*);

    struct oioi oioi = {
        .model_num = 123,
        .name = u8"jin",
        .hey = 123,
        .howru = 1234,
    };

    struct snt_subcentury_datetime64 ahah = {
        .microseconds = 5,
    };

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