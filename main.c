#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>

// #define ____sentient_pp_sentient_decl___
// #define ____sentient_pp_sentient_impl___

/**
 * @author Jin
 * @brief expands to nothing
 */
#define ___sentient_pp_empty(...)

/**
 * @author Jin
 * @brief concatenates tokens
 */
#define ___sentient_pp_cat(x, ...) x ## __VA_ARGS__
#define ___sentient_pp_cat_3(x, y, ...) x ## y ## __VA_ARGS__
#define ___sentient_pp_cat_4(x, y, ...) x ## y ## __VA_ARGS__

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

/*!
 * @author Jin
 * @brief preprocessor if else statement
 *
 * > ___sentient_pp_if_else(5) (0xdead)(0xbeef)
 * > ___sentient_pp_if_else_impl(___sentient_pp_bool(5)) (0xdead)(0xbeef)
 * > ___sentient_pp_if_else_impl(1) (0xdead)(0xbeef)
 * > ___sentient_pp_cat(___sentient_pp_if_else_1) (0xdead)(0xbeef)
 * > ___sentient_pp_if_else_1 (0xdead)(0xbeef)
 * > (0xdead) ___sentient_pp_if_1_else (0xbeef)
 * > (0xdead)
 */
#define ___sentient_pp_if_else(cond) \
        ___sentient_pp_if_else_impl(___sentient_pp_bool(cond))
#define ___sentient_pp_if_else_impl(cond) \
        ___sentient_pp_cat(___sentient_pp_if_else_, cond)
#define ___sentient_pp_if_else_1(...) \
        __VA_ARGS__ ___sentient_pp_if_1_else
#define ___sentient_pp_if_else_0(...) \
        ___sentient_pp_if_0_else
#define ___sentient_pp_if_1_else(...)
#define ___sentient_pp_if_0_else(...) \
        __VA_ARGS__

/**
 * @brief 
 * 
 * count_args(4, 5, 6)
 * count_args_impl(0, 4, 5, 6)
 *                
 * args(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0, )
 * 
 *       1  2  3  4  5  6  7  8
 * args( 0, 4, 5, 6, 6, 5, 4, 3, 2, 1, 0, )
 * 
 * 3
 * 
 */
#define args(_1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define count_args(...) count_args_impl(0, __VA_ARGS__)
#define count_args_impl(...) args(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0, )

#include <sentient/core/internal/pp_iterations.h>
#define ___sentient_pp_foreach(expr, ...) \
		___sentient_pp_cat(___sentient_pp_foreach_, ___sentient_pp_count_args(__VA_ARGS__)) (expr, __VA_ARGS__)

int main(int argc, char** argv)
{
	const int num_args = ___sentient_pp_count_args();

	return 0;
}