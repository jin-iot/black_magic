#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/generic.h>

#include <string.h>

#define hey(a)              \
        ({                  \
            int a = 1;      \
            a = hey(a + 1); \
            a;              \
        })

void custom_print(int x, int y)
{
    printf("black magic! %d %d\n", x, y);
}
#define ___custom_print(args) \
        custom_print args ;

#define ___custom_def(args) \
        ___custom_def_impl args
#define ___custom_def_impl(type, name) \
        type name ;


int main(int argc, char** argv)
{
    struct fuck
    {
    ___sentient_pp_foreach(
        ___custom_def,
        (int, a),
        (int, b),
        (int, c)
    )
    };

    struct fuck shit = { 0, };

	return 0;
}