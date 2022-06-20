#ifndef __SENTIENT_CORE_DETAIL_PP_UTILS_BASICS_H__
#define __SENTIENT_CORE_DETAIL_PP_UTILS_BASICS_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define ___SNT_PP_PASS(ARGS) ARGS
#define ___SNT_PP_IS_VA_ARG(...) ,
#define ___SNT_PP_COMMA()) ,
#define ___SNT_PP_LPAREN() (
#define ___SNT_PP_RPAREN() )
#define ___SNT_PP_LSQUARE() [
#define ___SNT_PP_RSQUARE() ]
#define ___SNT_PP_SEMICOLON() ;
#define ___SNT_PP_ARR(EXPR) [EXPR]
#define ___SNT_PP_BF(EXPR) : EXPR

/**
 * @author Jin (jaehwanspin@gmail.com)
 * @brief expands to nothing
 * @date 2022-05-04
 */
#define ___SNT_PP_EMPTY()

#define ___SNT_PP_WRAP(...) \
        ___SNT_PP_LPAREN() __VA_ARGS__  ___SNT_PP_RPAREN()
#define ___SNT_PP_UNWRAP(ARGS) \
        ___SNT_PP_IF_ELSE(___SNT_PP_IS_IN_PAREN(ARGS)) \
        (                                              \
            ___SNT_PP_PASS ARGS                        \
        )                                              \
        (                                              \
            ARGS                                       \
        )

#ifdef __cplusplus
}
#endif

#endif