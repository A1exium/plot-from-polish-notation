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

typedef double (*func)(double *);

double u_sum(double *args);

double u_diff(double *args);

double u_mul(double *args);

double u_div(double *args);

double u_sin(double *args);

double u_cos(double *args);

double u_tg(double *args);

double u_ctg(double *args);

double u_sqrt(double *args);
double u_ln(double *args);

double u_pow(double *args);

#define FUNCS_FUN                                                         \
  (func[FUNCS_CNT]) {                                                     \
    u_sum, u_diff, u_mul, u_div, u_sin, u_cos, u_tg, u_ctg, u_sqrt, u_ln, \
        u_pow                                                             \
  }
#endif  // SRC_INCLUDE_FUNCTIONS_H_
