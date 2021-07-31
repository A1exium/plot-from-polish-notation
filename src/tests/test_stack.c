#include <stdio.h>

#include "libstructures.h"
#include "misc.h"

Stack *GetStack() {
  Stack *tmp = Stack_new();
  Stack_push_str(tmp, "one");
  Stack_push_str(tmp, "two");
  Stack_push_str(tmp, "three");
  Stack_push_str(tmp, "four");
  Stack_push_str(tmp, "five");
  Stack_push_str(tmp, "six");
  Stack_push_str(tmp, "seven");
  return tmp;
}

void PrintStack(Stack *l) {
  printf("{");
  struct Node *tmp = l->top;
  while (tmp) {
    printf("%s, ", (char *)tmp->data);
    tmp = tmp->next;
  }
  printf("}\n");
}

void TestInit() {
  printf("Testing Stack Initialising:\n");
  Stack *tmp = Stack_new();
  Stack_free(tmp);
}

void TestAdd() {
  printf("Testing adding to Stack:\n");
  Stack *tmp = Stack_new();
  Stack_push_str(tmp, "1");
  Stack_push_str(tmp, "2");
  Stack_push_str(tmp, "3");
  Stack_push_str(tmp, "4");
  printf("out: ");
  PrintStack(tmp);
  Stack_free(tmp);
}

void TestPop() {
  printf("Testing removing from list:\n");
  Stack *tmp = GetStack();
  Stack_pop(tmp);
  Stack_pop(tmp);
  printf("out: ");
  PrintStack(tmp);
  Stack_free(tmp);
}

int main(void) {
  TestInit();
  TestAdd();
  TestPop();
}