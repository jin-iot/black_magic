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
 * @brief concatenates two tokens
 */
#define ___sentient_pp_cat(x, y) x ## y

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
#define ___sentient_pp_if_else(cond)      ___sentient_pp_if_else_impl(___sentient_pp_bool(cond))
#define ___sentient_pp_if_else_impl(cond) ___sentient_pp_cat(___sentient_pp_if_else_, cond)
#define ___sentient_pp_if_else_1(...)     __VA_ARGS__ ___sentient_pp_if_1_else
#define ___sentient_pp_if_else_0(...)                 ___sentient_pp_if_0_else
#define ___sentient_pp_if_1_else(...)
#define ___sentient_pp_if_0_else(...)     __VA_ARGS__

/**
 * @author Jin
 * @brief postpones an evaluation once
 * 
 * > #define ah() 1
 * >
 * > ___sentient_pp_defer(ah) () // postpones the macro
 * > ah empty() ()
 * > ah ()
 * > 1
 */
#define ___sentient_pp_defer(x) x ___sentient_pp_empty()
#define ___sentient_pp_defer_2(x) \
		x ___sentient_pp_empty ___sentient_pp_empty()()
#define ___sentient_pp_defer_3(x) \
        x ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty()()()
#define ___sentient_pp_defer_4(x) \
        x ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty()()()()
#define ___sentient_pp_defer_5(x) \
        x ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty()()()()
#define ___sentient_pp_defer_6(x) \
        x ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty ___sentient_pp_empty()()()()

/**
 * @author Jin
 * @brief evaluates an expression immediately
 */
#define ___sentient_pp_eval(...) ___sentient_pp_eval_128(__VA_ARGS__)
#define ___sentient_pp_eval_128(...) ___sentient_pp_eval_64(__VA_ARGS__)
#define ___sentient_pp_eval_64(...) ___sentient_pp_eval_32(__VA_ARGS__)
#define ___sentient_pp_eval_32(...) ___sentient_pp_eval_16(__VA_ARGS__)
#define ___sentient_pp_eval_16(...) ___sentient_pp_eval_8(__VA_ARGS__)
#define ___sentient_pp_eval_8(...) ___sentient_pp_eval_4(__VA_ARGS__)
#define ___sentient_pp_eval_4(...) ___sentient_pp_eval_2(__VA_ARGS__)
#define ___sentient_pp_eval_2(...) ___sentient_pp_eval_1(__VA_ARGS__)
#define ___sentient_pp_eval_1(...) __VA_ARGS__

#define ___sentient_pp_terminate_args() 0

#define ___sentient_pp_has_args(...) \
		___sentient_pp_bool(___sentient_pp_first(___sentient_pp_terminate_args __VA_ARGS__)())

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
#define ___sentient_pp_map(macro, _arg1, ...)                         \
		macro(_arg1)                                      \
		___sentient_pp_if_else(___sentient_pp_has_args(__VA_ARGS__))              \
		(                                                 \
			___sentient_pp_defer_2(___sentient_pp_map_next)()(macro, __VA_ARGS__) \
		)                                                 \
		(                                                 \
                                                          \
		)
		
#define ___sentient_pp_map_next() ___sentient_pp_map

#define ___sentient_pp_is_sentient_impl 0

/**
 * @author Jin
 * @brief defines a model struct with the type info
 */
#define sentient_define_model(...) \
		sentient_define_model_impl(__VA_ARGS__)

#define sentient_define_model_impl(...)                                               \
		___sentient_pp_if_else(___sentient_pp_cat(___sentient_pp_is_sentient_, impl)) \
		(                                                                             \
			sentient_define_model_impl_mode(__VA_ARGS__)                              \
		)                                                                             \
		(                                                                             \
			sentient_define_model_decl_mode(__VA_ARGS__)                              \
		)



int main(int argc, char** argv)
{


	return 0;
}