#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_CAT_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_CAT_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief conCATenates tokens
 * @date 2022-05-04
 */
#define ___SNT_PP_CAT(X, ...) \
        ___SNT_PP_CAT_IMPL(X, __VA_ARGS__)
#define ___SNT_PP_CAT_IMPL(X, ...) X ## __VA_ARGS__
#define ___SNT_PP_CAT_2(X, Y, ...) \
        ___SNT_PP_CAT_2_IMPL(X, Y, __VA_ARGS__)
#define ___SNT_PP_CAT_2_IMPL(X, Y, ...) X ## Y ## __VA_ARGS__
#define ___SNT_PP_CAT_3(X, Y, Z, ...) \
        ___SNT_PP_CAT_3_IMPL(X, Y, Z, __VA_ARGS__)
#define ___SNT_PP_CAT_3_IMPL(X, Y, Z, ...) X ## Y ## Z ## __VA_ARGS__
#define ___SNT_PP_CAT_4(X, Y, Z, A, ...) \
        ___SNT_PP_CAT_4_IMPL(X, Y, Z, A, __VA_ARGS__)
#define ___SNT_PP_CAT_4_IMPL(X, Y, Z, A, ...) X ## Y ## Z ## A ## __VA_ARGS__

#ifdef __cplusplus
}
#endif

#endif