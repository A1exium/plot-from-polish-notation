#include "str.h"
#include "infixtoprefix.h"
#include "dbg.h"

char* ConvertInfToPost(char* str) {
  int start = 0, end = s21_strtok(str, ' ', start);
  Stack *stack = Stack_new();

}