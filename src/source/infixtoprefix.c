#include "infixtoprefix.h"

#include <stdlib.h>

#include "../tests/dbg.h"
#include "functions.h"
#include "libstructures.h"
#include "misc.h"
#include "str.h"

char *List_to_string(List *self) {
  char *ret = List_get_str(self, 0);
  for (int i = 1; i < List_len(self); i++) {
    ret = s21_strcat(ret, " ");
    ret = s21_strcat(ret, List_get(self, i));
  }
  return ret;
}

void StackOp(Stack *stack, char *slice, List *ret) {
  if (stack->top) {
    char *tmp = Stack_pop_str(stack);
    while (IsFunc(tmp) || BinOrder(slice, tmp)) {
      List_add_str(ret, tmp);
      tmp = 0;
      if (!stack->top) {
        break;
      }
      tmp = Stack_pop_str(stack);
    }
    if (tmp) {
      Stack_push_str(stack, tmp);
    }
  }
  Stack_push_str(stack, slice);
}

char *ConvertInfToPost(char *str) {
  int le = s21_strlen(str);
  char *ret_s = 0;
  if (le == 1) {
    ret_s = (char *)calloc(1, sizeof(char));
    s21_strcpy(ret_s, str);
  } else {
    int start = 0, end = s21_strtok(str, ' ', start);
    Stack *stack = Stack_new();
    List *ret = List_new();
    while (start != le + 1) {
      char *slice = s21_strslice(str, start, end);
      if (IsDigit(slice)) {
        List_add_str(ret, slice);
      } else if (IsFunc(slice)) {
        Stack_push_str(stack, slice);
      } else if (s21_strcmp(slice, "(")) {
        Stack_push_str(stack, slice);
      } else if (s21_strcmp(slice, ")")) {
        slice = Stack_pop_str(stack);
        while (!s21_strcmp(slice, "(")) {
          List_add_str(ret, slice);
          slice = Stack_pop_str(stack);
        }
      } else {
        StackOp(stack, slice, ret);
      }
      start = end + 1;
      end = s21_strtok(str, ' ', start);
    }
    while (stack->top) {
      List_add_str(ret, Stack_pop_str(stack));
    }
    ret_s = List_to_string(ret);
    List_free(ret);
    Stack_free(stack);
  }
  return ret_s;
}