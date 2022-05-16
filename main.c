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

#define SENTIENT_OBJECT_POOL_STORAGE_MAX_LEN 6

struct snt_object_pool_strage_elem
{
    snt_size alloc_size;
    snt_size elems_size;
    void*         elems;
};

struct snt_object_pool_storage
{
    snt_size                            storage_size;
    struct snt_object_pool_strage_elem* storage;
};


#define ahah(a, b, c, d) \
        printf("%d %d %d %d\n", a, ___snt_pp_increase(b), c, d);

___snt_pp_cat_4( ___snt_pp_for_, increase, _, 1 ) (0, ___snt_pp_decl_object_pool_elems_handler, 1, snt_u32, primitive)

// ___snt_pp_for(1, 0, increase, ___snt_pp_decl_object_pool_elems_handler, 1, snt_u32, primitive)


// ___snt_pp_decl_object_pool_elems_impl(1, snt_u32, primitive)

// ___snt_pp_decl_object_pool_elems_handler(0, 5, snt_u32, primitive);
// ___snt_pp_decl_object_pool_elems_handler(1, 5, snt_u32, primitive);
// ___snt_pp_decl_object_pool_elems_handler(2, 5, snt_u32, primitive);
// ___snt_pp_decl_object_pool_elems_handler(3, 5, snt_u32, primitive);
// ___snt_pp_decl_object_pool_elems_handler(2, 5, snt_u32, primitive);

int main(int argc, char** argv)  
{
    int res = EXIT_SUCCESS;

    ___snt_pp_for(5, 0, increase, ahah, 5, 6, 6);

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