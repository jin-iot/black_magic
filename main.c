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

struct snt_object_pool_strage_elem
{
    snt_size alloc_size;
    snt_size elems_size;
    void*    elems;
};

struct snt_object_pool_storage
{
    snt_size                            storage_size;
    struct snt_object_pool_strage_elem* storage;
};

___snt_pp_decl_object_pool_elems(5, snt_u32, primitive)

int main(int argc, char** argv)  
{
    int res = EXIT_SUCCESS;

    

    for (int i = 0; i < 4; i++)
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

    for (int i = 0; i < 4; i++)
    {
        thrd_join(threads[i],
                  snt_nullptr);
    }

exit_label:
	return 0;
}