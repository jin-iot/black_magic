#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <sentient/core/types.h>
#include <sentient/core/field_info.h>
#include <sentient/core/model_info.h>
#include <sentient/core/pp_utils.h>
#include <sentient/core/generic.h>
#include <sentient/core/define_model.h>









int main(int argc, char** argv)
{
    const struct sentient_model_info* mi = 
        ___sentient_model_info_get_model_info(
            ___sentient_type_id_sentient_u16
        );
    // printf("hey! %s\n", mi->model_name);

    printf("ah\n");

	return 0;
}