#include "parse.h"

#include "functions.h"
#include "misc.h"
#include "str.h"

double Convert_str_to_double(char *str) {
  int point = 0, sign = 1;
  double ret_v = 0, power = 0;
  if (str[0] == '-') sign = -1;
  for (int i = 0; i < s21_strlen(str); i++) {
    if (str[i] == '.') {
      point = 1;
      power = 0;
    } else if (point) {
      ret_v += (str[i] - '0') * pow(10, power);
      power--;
    } else {
      ret_v *= pow(10, power);
      ret_v += str[i] - '0';
      power++;
    }
  }
  return ret_v * sign;
}

double Eval(char *str, double x) {
  int start = 0, end = s21_strtok(str, ' ', start);
  Stack *stack = Stack_new();
  double ret = 0;
  int l = s21_strlen(str);
  while (start != l + 1) {
    char *slice = s21_strslice(str, start, end);
    if (s21_strcmp(slice, "x") || s21_strcmp(slice, "-x")) {
      Stack_push_double(stack, slice[0] == '-' ? -x : x);
    } else if (IsDigit(slice)) {
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
    start = end + 1;
    end = s21_strtok(str, ' ', start);
  }
  ret = Stack_pop_double(stack);
  Stack_free(stack);
  return ret;
}
