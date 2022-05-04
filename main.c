#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>

// #define ____sentient_pp_sentient_decl___
// #define ____sentient_pp_sentient_impl___

/**
 * @author Jin
 * @brief indirective expression
 */
#define ___sentient_pp_indirect(x) x

#define ___sentient_pp_lparen (
#define ___sentient_pp_rparen )
#define ___sentient_pp_parens ()

#define ___sentient_pp_first(x, ...) x
#define ___sentient_pp_second(x, y, ...) y

/**
 * @brief the collection of ___sentient_pp_get_{N}(...)
 */
#include <sentient/core/internal/pp_get_n.h>

/**
 * @author Jin
 * @brief preprocessor not operator
 * 
 * > ___sentient_pp_not(123)
 * > ___sentient_pp_is_probe(___sentient_pp_not_123)
 * > ___sentient_pp_second(___sentient_pp_not_123, 0)
 * > 0
 * 
 * > ___sentient_pp_not(0)
 * > ___sentient_pp_is_probe(___sentient_pp_not_0)
 * > ___sentient_pp_second(~, 1, 0)
 * > 1
 * 
 */
#define ___sentient_pp_not(x) ___sentient_pp_is_probe(___sentient_pp_cat(___sentient_pp_not_, x))
#define ___sentient_pp_is_probe(...) ___sentient_pp_second(__VA_ARGS__, 0)
#define ___sentient_pp_probe() ~, 1
#define ___sentient_pp_not_0 ___sentient_pp_probe()

/**
 * @author Jin
 * @brief preprocessor 0 .. N to bool(0, 1) utility
 * 
 * > ___sentient_pp_bool(123)
 * > ___sentient_pp_not(___sentient_pp_not(123))
 * > ...
 * > ___sentient_pp_not(0)
 * > ...
 * > 1
 * 
 */
#define ___sentient_pp_bool(x) ___sentient_pp_not(___sentient_pp_not(x))


#include <sentient/core/pp_utils.h>

#include <string.h>

int main(int argc, char** argv)
{
    struct timespec ts = { 0, };

    const size_t fucking = sizeof(struct timespec);

    // const int aha = memcpy(NULL, NULL, 0) == NULL ? 
    
	return 0;
}