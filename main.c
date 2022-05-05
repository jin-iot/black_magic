#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/generic.h>

#include <string.h>

struct fuck
{
    int a;
};

struct fuuck
{
    int aa;
};

struct fuuck you = { .aa = 4 };
struct fuuck hey = { .aa = 3 };

#define fucking_type(var)    \
        sentient_generic(    \
            (var),           \
            default: hey,    \
            struct fuck: you \
        )

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
    // printf("ah %d\n", ah);

    int a = 5;
    struct fuck aa = { .a = 5 };
    typeof(aa) fdsa;

    printf("%d\n", fucking_type(a).aa);

    printf("%s\n", __typeof__(aa));

	return 0;
}