#ifndef SRC_INCLUDE_FUNCTIONS_H_
#define SRC_INCLUDE_FUNCTIONS_H_
#include <math.h>

#define FUNCS_CNT 11
#define FUNCS_STR                                                    \
  (char *[FUNCS_CNT]) {                                              \
    "+", "-", "*", "/", "sin", "cos", "tg", "ctg", "sqrt", "ln", "^" \
  }
#define FUNCS_ARG \
  (int[FUNCS_CNT]) { 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2 }
#define FUNCS_STR_PREFIX "sincostgctgsqrtln"
#define FUNCS_BIN_ORDER "+- */ ^"
typedef double (*func)(double *);

extern double u_sum(double *args);

extern double u_diff(double *args);

extern double u_mul(double *args);

extern double u_div(double *args);

extern double u_sin(double *args);

extern double u_cos(double *args);

extern double u_tg(double *args);

extern double u_ctg(double *args);

extern double u_sqrt(double *args);
extern double u_ln(double *args);

extern double u_pow(double *args);

#define FUNCS_FUN                                                         \
  (func[FUNCS_CNT]) {                                                     \
    u_sum, u_diff, u_mul, u_div, u_sin, u_cos, u_tg, u_ctg, u_sqrt, u_ln, \
        u_pow                                                             \
  }
#endif  // SRC_INCLUDE_FUNCTIONS_H_
