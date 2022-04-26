#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>

/**
 * @author Jin
 * @brief
 * @param[in] ... variadic args
 * @return  
 */
#define pp_empty(...)

#define pp_cat(x, y) x ## y

#define pp_lparen() (
#define pp_rparen() )


#define pp_first(x, ...) x
#define pp_second(x, y, ...) y
#include <sentient/core/internal/pp_get_n.h>

/*!
 * @author Jin
 * @brief preprocessor if else statement
 * @param[in] cond condition token
 * @return expression pp_if_else_{cond}
 * 
 * ** how to use **
 *
 * pp_if_else(a_condition) (
 * 
 *     call_true()
 * 
 * ) (
 * 
 *     call_another()
 * 
 * )
 * 
 */
#define pp_if_else(cond)      pp_if_else_impl(pp_bool(cond))
#define pp_if_else_impl(cond) pp_cat(pp_if_else_ ## cond)
#define pp_if_else_1(...)     __VA_ARGS__ pp_if_1_else
#define pp_if_else_0(...)                 pp_if_0_else
#define pp_if_1_else(...)
#define pp_if_0_else(...)     __VA_ARGS__

/**
 * @author Jin
 * @brief preprocessor not operator
 * @param[in] x expression
 * @return expression pp_is_probe(pp_not_{x})
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
 * @brief preprocessor 0 ~ ANY to bool utility
 * @param[in] x expression
 * @return bool value
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

#define pp_defer(x) x pp_empty()

#define pp_eval(...) pp_eval_1024(__VA_ARGS__)
#define pp_eval_1024(...) pp_eval_512(pp_eval_512(__VA_ARGS__))
#define pp_eval_512(...) pp_eval_256(pp_eval_256(__VA_ARGS__))
#define pp_eval_256(...) pp_eval_128(pp_eval_128(__VA_ARGS__))
#define pp_eval_128(...) pp_eval_64(pp_eval_64(__VA_ARGS__))
#define pp_eval_64(...) pp_eval_32(pp_eval_32(__VA_ARGS__))
#define pp_eval_32(...) pp_eval_16(pp_eval_16(__VA_ARGS__))
#define pp_eval_16(...) pp_eval_8(pp_eval_8(__VA_ARGS__))
#define pp_eval_8(...) pp_eval_4(pp_eval_4(__VA_ARGS__))
#define pp_eval_4(...) pp_eval_2(pp_eval_2(__VA_ARGS__))
#define pp_eval_2(...) pp_eval_1(pp_eval_1(__VA_ARGS__))
#define pp_eval_1(...) __VA_ARGS__

int main(int argc, char** argv)
{
	

	return 0;
}