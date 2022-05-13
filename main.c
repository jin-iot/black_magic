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

struct example_model
{
    sentient_u32 number;
    sentient_u32 val;
};

sentient_i32 thread_handler(sentient_void* arg)
{

    printf("thread %ld\n", thrd_current());
}

#define def_num(num, type, name) \
        const type name ## _ ## num = num ;

#define SENTIENT_OBJECT_POOL_STORAGE_MAX_LEN 6

// so ideal!!!!!!!!!!!!!
// for i in range(0, 5): print(16**i, int((8**5)/(4**(i+1))))

struct sentient_object_pool_strage_elem
{
    sentient_size alloc_size;
    sentient_size elems_size;
    void*         elems;
};
struct sentient_object_pool_storage
{
    sentient_size                            storage_size;
    struct sentient_object_pool_strage_elem* storage;
};

static const
struct example_model
___sentient_object_pool_storage_array_1[1][1024];
static const
struct sentient_object_pool_strage_elem
___sentient_object_pool_storage_elem_1 = {
    .alloc_size = 1,
    .elems_size =
        sizeof(___sentient_object_pool_storage_array_1[0])  / sizeof(struct example_model),
    .elems = ___sentient_object_pool_storage_array_1,
};
static const
struct example_model
___sentient_object_pool_storage_array_2[16][4096];
static const
struct sentient_object_pool_strage_elem
___sentient_object_pool_storage_elem_2 = {
    .alloc_size = 16,
    .elems_size =
        sizeof(___sentient_object_pool_storage_array_2[0])  / sizeof(struct example_model),
    .elems = ___sentient_object_pool_storage_array_1,
};
static const
struct example_model
___sentient_object_pool_storage_array_3[256][4096];
static const
struct sentient_object_pool_strage_elem
___sentient_object_pool_storage_example_model_elems[] = {
    {
        .alloc_size = 256,
        .elems_size =
            sizeof(___sentient_object_pool_storage_array_3[0])  / sizeof(struct example_model),
        .elems = ___sentient_object_pool_storage_array_1,
    }
};
static const
struct sentient_object_pool_storage
___sentient_object_pool_example_model = {
    
};

int main(int argc, char** argv)
{
    int res = EXIT_SUCCESS;

    for (int i = 0; i < ; i++)
    {
        struct example_model* elelelem = ;
        printf("elelem %d %d",)
    }

    const int asdfsadf = ___sentient_pp_is_eq(struct, struct);

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