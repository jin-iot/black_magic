#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_IF_ELSE_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_IF_ELSE_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * @author Jin (jaehwanspin@gmail.com)
 * @brief preprocessor if else statement
 *
 * > const int val = ___SNT_PP_IF_ELSE(5) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_IF_ELSE_IMPL(___SNT_PP_bool(5)) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_IF_ELSE_IMPL(1) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_CAT(___SNT_PP_IF_ELSE_1) (0xdead)(0xbeef);
 * > const int val = ___SNT_PP_IF_ELSE_1 (0xdead)(0xbeef);
 * > const int val = (0xdead) ___SNT_PP_if_1_else (0xbeef);
 * > const int val = (0xdead);
 */
#define ___SNT_PP_IF_ELSE(COND) \
        ___SNT_PP_IF_ELSE_IMPL(___SNT_PP_BOOL(COND))
#define ___SNT_PP_IF_ELSE_IMPL(COND) \
        ___SNT_PP_CAT(___SNT_PP_IF_ELSE_, COND)
#define ___SNT_PP_IF_ELSE_1(...) \
        __VA_ARGS__ ___SNT_PP_IF_1_ELSE
#define ___SNT_PP_IF_ELSE_0(...) \
        ___SNT_PP_IF_0_ELSE
#define ___SNT_PP_IF_1_ELSE(...)
#define ___SNT_PP_IF_0_ELSE(...) \
        __VA_ARGS__


#ifdef __cplusplus
}
#endif

#endif