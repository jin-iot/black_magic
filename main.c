#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/generic.h>


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
    const int fdsafdsa =
        ___sentient_pp_if_else(___sentient_pp_is_eq(1, 2))
        (
            666
        )
        (
            777
        );

    struct fuck
    {
        ___sentient_pp_foreach(
            ___custom_def,
            (int, a),
            (int, b),
            (int, c)
        )
    };

	return 0;
}