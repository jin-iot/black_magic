#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_IS_EQ_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_IS_EQ_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is in parenthesis
 * @date 2022-05-06
 */
#define ___SNT_PP_DETECT_PAREN(...) ,
#define ___SNT_PP_IS_IN_PAREN(...) \
        ___SNT_PP_IS_IN_PAREN_IMPL(__VA_ARGS__)
#define ___SNT_PP_IS_IN_PAREN_IMPL(...)                                 \
        ___SNT_PP_HAS_COMMA(                                            \
            ___SNT_PP_CAT_3(                                            \
                ___SNT_PP_IS_IN_PAREN_,                                 \
                ___SNT_PP_HAS_COMMA(__VA_ARGS__),                       \
                ___SNT_PP_HAS_COMMA(___SNT_PP_DETECT_PAREN __VA_ARGS__) \
            )                                                           \
        )
#define ___SNT_PP_IS_IN_PAREN_01 ,

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief check if the arg is parenthesis
 * @date 2022-05-06
 */
#define ___SNT_PP_CHECK(...) \
        ___SNT_PP_GET_1(__VA_ARGS__, 0, )

#define ___SNT_PP_IS_PAREN(x) \
        ___SNT_PP_CHECK(___SNT_PP_IS_PAREN_PROBE x)
#define ___SNT_PP_IS_PAREN_PROBE(...) \
        ___SNT_PP_PROBE()

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief compares each arg
 * @date 2022-05-07
 */
#define ___SNT_PP_IS_EQ(X, Y) \
        ___SNT_PP_IS_EQ_IMPL(X, Y)
#define ___SNT_PP_IS_EQ_IMPL(X, Y)                                      \
        ___SNT_PP_NOT(                                                  \
            ___SNT_PP_IS_PAREN(                                         \
                ___SNT_PP_COMPARE_ ## X (___SNT_PP_COMPARE_ ## Y ) (()) \
            )                                                           \
        )
/**
 * macro numeric, keyword constants ( 0 ~ N, keywords... ) to compare
 */
#include <sentient/core/internal/pp_compare_n.h>
#define ___SNT_PP_COMPARE_(...) 
#define ___SNT_PP_COMPARE_STRUCTURE(X) X
#define ___SNT_PP_COMPARE_PRIMITIVE(X) X
#define ___SNT_PP_COMPARE_SNT_BIT_FIELD(X) X
#define ___SNT_PP_COMPARE_SNT_ARRAY(X) X
#define ___SNT_PP_COMPARE_SNT_NO_ATTR(X) X

#ifdef __cplusplus
}
#endif

#endif