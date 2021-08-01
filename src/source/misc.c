#include "misc.h"

#include "functions.h"
#include "str.h"

int IsDigit(char *c) { return c >= '0' && c <= '9'; }

int BinOrder(char *inp, char *cmp) {
  int ret_v = 0;
  int ind1 = s21_strstr(FUNCS_BIN_ORDER, inp);
  int ind2 = s21_strstr(FUNCS_BIN_ORDER, cmp);
  if (ind1 != -1 && ind2 != -1 && (ind2 >= ind1 || ind2 - ind1 == 1)) {
    ret_v = 1;
  }
  return ret_v;
}

int IsFunc(char *c) { return s21_strstr(FUNCS_STR_PREFIX, c) != -1; }