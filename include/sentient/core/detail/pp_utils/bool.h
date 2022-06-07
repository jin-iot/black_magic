#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_BOOL_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_BOOL_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin
 * @brief preprocessor not operator
 * 
 * > ___SNT_PP_not(123)
 * > ___SNT_PP_is_probe(___SNT_PP_not_123)
 * > ___SNT_PP_second(___SNT_PP_not_123, 0)
 * > 0
 * 
 * > ___SNT_PP_not(0)
 * > ___SNT_PP_is_probe(___SNT_PP_not_0)
 * > ___SNT_PP_second(~, 1, 0)
 * > 1
 * 
 */
#define ___SNT_PP_NOT(X) \
        ___SNT_PP_IS_PROBE(___SNT_PP_CAT(___SNT_PP_NOT_, X))
#define ___SNT_PP_IS_PROBE(...) \
        ___SNT_PP_SECOND(__VA_ARGS__, 0)
#define ___SNT_PP_PROBE() \
        ~, 1
#define ___SNT_PP_NOT_0 \
        ___SNT_PP_PROBE()

#define ___SNT_PP_BOOL(X) \
        ___SNT_PP_NOT(___SNT_PP_NOT(X))

#ifdef __cplusplus
}
#endif

#endif