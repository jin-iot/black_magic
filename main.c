#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>
#include <string.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/generic.h>
#include <sentient/core/define_model.h>

thrd_t threads[4] = { 0, };

int thread_handler(void* arg)
{
    printf("thread %ld\n", thrd_current());
}

#define ___sentient_pp_for_increase_0(number, expr, ...)
#define ___sentient_pp_for_increase_1(number, expr, ...) \
        expr(number, __VA_ARGS__)                     \
        ___sentient_pp_for_increase_0(                   \
            ___sentient_pp_increase(number),          \
            expr,                                     \
            __VA_ARGS__                               \
        )
#define ___sentient_pp_for_increase_2(number, expr, ...) \
        expr(number, __VA_ARGS__)                     \
        ___sentient_pp_for_increase_1(                   \
            ___sentient_pp_increase(number),          \
            expr,                                     \
            __VA_ARGS__                               \
        )
#define ___sentient_pp_for_increase_3(number, expr, ...) \
        expr(number, __VA_ARGS__)                     \
        ___sentient_pp_for_increase_2(                   \
            ___sentient_pp_increase(number),          \
            expr,                                     \
            __VA_ARGS__                               \
        )

#define def_num(num, type, name) \
        const type name_ ## num = num ;

int main(int argc, char** argv)
{
    // ___sentient_pp_for(3, 1, increase, def_num, int, fuck)
    ___sentient_pp_cat_4_impl(___sentient_pp_for_, increase, _, 3, )

    // printf("%d %d %d \n");

    int res = EXIT_SUCCESS;

    for (int i = 0; i < 4; i++)
    {
        int err = thrd_create(&threads[i],
                              thread_handler,
                              sentient_nullptr);

        if (err < 0)
        {
            res = EXIT_FAILURE;
            goto exit_label;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        thrd_join(threads[i],
                  sentient_nullptr);
    }

exit_label:
	return 0;
}