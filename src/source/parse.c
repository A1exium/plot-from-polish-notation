#include "functions.h"
#include "parsing.h"
#include "str.h"

double Convert_str_to_double(char *str) {
  int point = 0, sign = 1;
  double ret_v = 0, power = 0;
  for (int i = 0; i < s21_strlen(str); i++) {
    if (str[i] == '.') {
      point = 1;
      power = 0;
    } else if (point) {
      ret_v += (str[0] - '0') * pow(10, power);
      power--;
    } else {
      ret_v *= pow(10, power);
      ret_v += str[0] - '0';
      power++;
    }
  }
  return ret_v * sign;
}

double Eval(char *str, double x) {
  int start = 0, end = s21_strtok(str, " ", start);
  // char str_funcs[] = {"+", "-", "*", "/", "sin", "cos", "tg", "ctg", "sqrt",
  // "ln", "^"}; func func_funcs[] = {u_sum, u_diff, u_mul, u_div, u_sin, u_cos,
  // u_tg, u_ctg, u_sqrt, u_ln, u_pow}; int argc_funcs[] = {2, 2, 2, 2, 1, 1, 1,
  // 1, 1, 1, 1};
  Stack *stack = Stack_new();
  double ret = 0;
  while (end != s21_strlen(str)) {
    start = end;
    end = s21_strtok(str, " ", start);
    char *slice = s21_strslice(str, start, end);
    if (s21_strcmp(slice, "x")) {
      Stack_push_double(stack, x);
    } else if (slice[0] >= '0' && slice[0] <= '9') {
      Stack_push_double(stack, Convert_str_to_double(slice));
    } else {
      for (int i = 0; i < FUNCS_CNT; i++) {
        if (s21_strcmp(slice, FUNCS_STR[i])) {
          double args[2];
          for (int j = 0; j < FUNCS_ARG[i]; j++) {
            args[j] = Stack_pop_double(stack);
          }
          Stack_push_double(stack, FUNCS_FUN[i](args));
        }
      }
    }
  }
  ret = Stack_pop_double(stack);
  Stack_free(stack);
  return ret;
}