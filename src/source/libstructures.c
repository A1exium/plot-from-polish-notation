#include "libstructures.h"  // TODO(anyone): Use flag

#include <stdlib.h>

List *List_new() {
  List *tmp = malloc(sizeof(List));
  tmp->head = 0;
  return tmp;
}

struct Node *List_get_last(List *self) {
  struct Node *tmp = self->head;
  while (tmp->next) {
    tmp = tmp->next;
  }
  return tmp;
}

void List_add(List *self, char *lexem) {
  struct Node *tmp = malloc(sizeof(struct Node));
  tmp->data = (void *)lexem;
  tmp->next = 0;
  if (self->head) {
    List_get_last(self)->next = tmp;
  } else {
    self->head = tmp;
  }
}

void List_free(List *self) {
  struct Node *tmp = self->head;
  while (tmp) {
    if (tmp->next) {
      struct Node *next = tmp->next;
      free(tmp);
      tmp = next;
    } else {
      free(tmp);
    }
  }
  free(self);
}

void List_remove(List *self, int index) {
  if (index > 0) {
    struct Node *prev = self->head;
    struct Node *tmp = self->head->next;
    for (int i = 1; i < index; i++) {
      prev = tmp;
      tmp = tmp->next;
    }
    if (tmp->next) {
      prev->next = tmp->next;
    } else {
      prev->next = 0;
    }
    free(tmp);
  } else {
    if (self->head->next) {
      self->head = self->head->next;
    } else {
      self->head = 0;
    }
  }
}

void List_delete(List *self, char *elem) {
  struct Node *tmp = self->head;
  int i = 0;
  while (tmp->next) {
    if (tmp->data == elem) {  // TODO(any1): Add string matching
      List_remove(self, i);
      break;
    }
    tmp = tmp->next;
    i++;
  }
}

char *List_get(List *self, int index) {
  struct Node *tmp = self->head;
  void *ret_v = 0;
  for (int i = 0; i < index; i++) {
    if (!tmp->next) {
      ret_v = 0;
      break;
    }
    tmp = tmp->next;
    ret_v = tmp->data;
  }
  return (char *)ret_v;
}

int List_contains(List *self, char *elem) {
  struct Node *tmp = self->head;
  int i = 0, ret_v = 0;
  while (tmp->next) {
    if (tmp->data == elem) {  // TODO(any1): Add string matching
      ret_v = 1;
      break;
    }
    tmp = tmp->next;
    i++;
  }
  return ret_v;
}

Stack *Stack_new() {
  Stack *tmp = malloc(sizeof(Stack));
  tmp->top = 0;
  return tmp;
}

void Stack_push_str(Stack *self, char *lexem) {
  struct Node *tmp = malloc(sizeof(struct Node));
  tmp->data = (void *)lexem;
  if (self->top) {
    tmp->next = self->top;
  } else {
    tmp->next = 0;
  }
  self->top = tmp;
}

void *Stack_pop(Stack *self) {
  void *ret_v = 0;
  if (self->top) {
    struct Node *tmp = self->top;
    self->top = tmp->next;
    ret_v = tmp->data;
  }
  return ret_v;
}

void Stack_free(Stack *self) {
  while (self->top) {
    struct Node *tmp = Stack_pop(self);
    free(tmp);
  }
}