#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <threads.h>

#define pp_cat(x, y) x ## y

#define pp_if_else(cond) \
		pp_if_else_impl(pp_bool(cond))

#define pp_if_else_impl(cond) \
		pp_cat(pp_if_, cond)

#define pp_if_1(...) \
		__VA_ARGS__ pp_if_1_else
#define pp_if_0(...) \
        pp_if_0_else

#define pp_if_1_else(...)
#define pp_if_0_else(...) __VA_ARGS__

#define pp_first(a, b, ...) a
#define pp_second(a, b, ...) b
#define pp_is_probe(...) pp_second(__VA_ARGS__, 0)
#define pp_probe() ~, 1
#define pp_not(x) \
	    pp_is_probe(pp_cat(pp_not_, x))
#define pp_not_0 pp_probe()

#define pp_bool(x) pp_not(pp_not(x))

#define pp_empty()
#define pp_eval(...) __VA_ARGS__
#define pp_eval1(...) __VA_ARGS__

int main(int argc, char** argv)
{
	const int a = pp_bool(32131231);
	const char* ah = pp_if_else(0)("fuck")("shit");

	printf("%s\n", ah);



	return 0;
}