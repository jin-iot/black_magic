#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/generic.h>

#include <string.h>

void custom_print(int x, int y)
{
    printf("black magic! %d %d\n", x, y);
}
#define ___custom_print(args) \
        custom_print args ;

int main(int argc, char** argv)
{
    ___sentient_pp_foreach(
        ___custom_print,
        (1, 2),
        (3, 4),
        (5, 6)
    )

	return 0;
}