#include "dbg.h"

void Assert(int a, int b) {
  if (a == b) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}

void List_print(List *l) {
  printf("{");
  for (int i = 0; i < List_len(l); i++) {
    printf("%s, ", List_get_str(l, i));
  }
  printf("}\n");
}

void Stack_print_str(Stack *l) {
  printf("{");
  struct Node *tmp = l->top;
  while (tmp) {
    printf("%s, ", (char *)tmp->data);
    tmp = tmp->next;
  }
  printf("}\n");
}

void Stack_print_double(Stack *l) {
  printf("{");
  struct Node *tmp = l->top;
  while (tmp) {
    printf("%lf, ", *(double *)tmp->data);
    tmp = tmp->next;
  }
  printf("}\n");
}