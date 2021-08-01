#include "functions.h"

double u_sum(double *args) { return args[0] + args[1]; }

double u_diff(double *args) { return args[0] - args[1]; }

double u_mul(double *args) { return args[0] * args[1]; }

double u_div(double *args) { return args[0] / args[1]; }

double u_sin(double *args) { return sin(args[0]); }

double u_cos(double *args) { return cos(args[0]); }

double u_tg(double *args) { return tan(args[0]); }

double u_ctg(double *args) { return 1 / tan(args[0]); }

double u_sqrt(double *args) { return sqrt(args[0]); }

double u_ln(double *args) { return log(args[0]); }

double u_pow(double *args) { return pow(args[0], args[1]); }
