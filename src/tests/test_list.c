#include "libstructures.h"
#include "misc.h"

#include <stdio.h>

List *GetList() {
  List *tmp = List_new();
  List_add(tmp, "one");
  List_add(tmp, "two");
  List_add(tmp, "three");
  List_add(tmp, "four");
  List_add(tmp, "five");
  List_add(tmp, "six");
  List_add(tmp, "seven");
  return tmp;
}

void PrintList(List *l) {
  printf("{");
  for (int i = 0; i < List_len(l); i++) {
    printf("%s, ", List_get_str(l, i));
  }
  printf("}\n");
}

void TestInit() {
  printf("Testing list Initialising:\n");
  List *tmp = List_new();
  Assert(List_len(tmp), 0);
  List_free(tmp);
}

void TestAdd() {
  printf("Testing adding to list:\n");
  List *tmp = List_new();
  List_add(tmp, "1");
  List_add(tmp, "2");
  List_add(tmp, "3");
  List_add(tmp, "4");
  printf("out: ");
  PrintList(tmp);
  Assert(List_len(tmp), 4);
  List_free(tmp);
}

void TestContain() {
  printf("Testing containing in list:\n");
  List *tmp = GetList();
  Assert(List_contains(tmp, "two"), 1);
  Assert(List_contains(tmp, "ten"), 0);
  List_free(tmp);
}

void TestRemove() {
  printf("Testing removing from list:\n");
  List *tmp = GetList();
  List_remove(tmp, 5);
  printf("out: ");
  PrintList(tmp);
  Assert(List_contains(tmp, "six"), 0);
  List_free(tmp);
}

void TestDelete() {
  printf("Testing removing from list:\n");
  List *tmp = GetList();
  List_delete(tmp, "six");
  printf("out: ");
  PrintList(tmp);
  Assert(List_contains(tmp, "six"), 0);
  List_free(tmp);
}



int main(void) {
  TestInit();
  TestAdd();
  TestContain();
  TestRemove();
  TestDelete();
}