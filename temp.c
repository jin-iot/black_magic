
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
