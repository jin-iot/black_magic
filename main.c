#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>

/**
 * @author Jin
 * @brief expands to nothing
 */
#define pp_empty(...)

/**
 * @author Jin
 * @brief concatenates two tokens
 */
#define pp_cat(x, y) x ## y

/**
 * @author Jin
 * @brief indirective expression
 */
#define pp_indirect(x) x

#define pp_lparen (
#define pp_rparen )
#define pp_parens ()

#define pp_first(x, ...) x
#define pp_second(x, y, ...) y
#include <sentient/core/internal/pp_get_n.h>

/**
 * @author Jin
 * @brief preprocessor not operator
 * 
 * > pp_not(123)
 * > pp_is_probe(pp_not_123)
 * > pp_second(pp_not_123, 0)
 * > 0
 * 
 * > pp_not(0)
 * > pp_is_probe(pp_not_0)
 * > pp_second(~, 1, 0)
 * > 1
 * 
 */
#define pp_not(x) pp_is_probe(pp_cat(pp_not_, x))
#define pp_is_probe(...) pp_second(__VA_ARGS__, 0)
#define pp_probe() ~, 1
#define pp_not_0 pp_probe()

/**
 * @author Jin
 * @brief preprocessor 0 .. N to bool(0, 1) utility
 * 
 * > pp_bool(123)
 * > pp_not(pp_not(123))
 * > ...
 * > pp_not(0)
 * > ...
 * > 1
 * 
 */
#define pp_bool(x) pp_not(pp_not(x))

/*!
 * @author Jin
 * @brief preprocessor if else statement
 *
 * > pp_if_else(5) (0xdead)(0xbeef)
 * > pp_if_else_impl(pp_bool(5)) (0xdead)(0xbeef)
 * > pp_if_else_impl(1) (0xdead)(0xbeef)
 * > pp_cat(pp_if_else_1) (0xdead)(0xbeef)
 * > pp_if_else_1 (0xdead)(0xbeef)
 * > (0xdead) pp_if_1_else (0xbeef)
 * > (0xdead)
 */
#define pp_if_else(cond)      pp_if_else_impl(pp_bool(cond))
#define pp_if_else_impl(cond) pp_cat(pp_if_else_, cond)
#define pp_if_else_1(...)     __VA_ARGS__ pp_if_1_else
#define pp_if_else_0(...)                 pp_if_0_else
#define pp_if_1_else(...)
#define pp_if_0_else(...)     __VA_ARGS__

/**
 * @author Jin
 * @brief postpones an evaluation once
 * 
 * > #define ah() 1
 * >
 * > pp_defer(ah) () // postpones the macro
 * > ah empty() ()
 * > ah ()
 * > 1
 */
#define pp_defer(x) x pp_empty()
#define pp_defer_2(x) \
		x pp_empty pp_empty()()
#define pp_defer_3(x) \
        x pp_empty pp_empty pp_empty()()()
#define pp_defer_4(x) \
        x pp_empty pp_empty pp_empty pp_empty()()()()
#define pp_defer_5(x) \
        x pp_empty pp_empty pp_empty pp_empty pp_empty()()()()
#define pp_defer_6(x) \
        x pp_empty pp_empty pp_empty pp_empty pp_empty pp_empty()()()()

/**
 * @author Jin
 * @brief evaluates an expression immediately
 */
#define pp_eval(...) pp_eval_128(__VA_ARGS__)
#define pp_eval_128(...) pp_eval_64(__VA_ARGS__)
#define pp_eval_64(...) pp_eval_32(__VA_ARGS__)
#define pp_eval_32(...) pp_eval_16(__VA_ARGS__)
#define pp_eval_16(...) pp_eval_8(__VA_ARGS__)
#define pp_eval_8(...) pp_eval_4(__VA_ARGS__)
#define pp_eval_4(...) pp_eval_2(__VA_ARGS__)
#define pp_eval_2(...) pp_eval_1(__VA_ARGS__)
#define pp_eval_1(...) __VA_ARGS__

#define pp_terminate_args() 0

#define pp_has_args(...) \
		pp_bool(pp_first(pp_terminate_args __VA_ARGS__)())

/**
 * @author Jin
 * @brief repeats each macro arg
 * 
 * >
 * >
 * >
 * >
 * >
 * >
 */
#define pp_map(macro, _arg1, ...)                         \
		macro(_arg1)                                      \
		pp_if_else(pp_has_args(__VA_ARGS__))              \
		(                                                 \
			pp_defer_2(pp_map_next)()(macro, __VA_ARGS__) \
		)                                                 \
		(                                                 \
                                                          \
		)
		
#define pp_map_next() pp_map

void ah(int i)
{
	printf("%d\n", i);
}

#define pp_define_field(type, name, ...) type name __VA_ARGS__;

#define hey(x) ah pp_lparen x pp_rparen ;

struct fuck
{
	pp_map(pp_define_field, int, ah)
};

int main(int argc, char** argv)
{

	pp_eval(pp_map(hey, 5, 4));
	

	return 0;
}