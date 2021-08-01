#include "libstructures.h"  // TODO(anyone): Use flag

#include <stdio.h>
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

void List_add(List *self, void *value) {
  struct Node *tmp = malloc(sizeof(struct Node));
  tmp->data = value;
  tmp->next = 0;
  if (self->head) {
    List_get_last(self)->next = tmp;
  } else {
    self->head = tmp;
  }
}

void List_add_str(List *self, char *lexem) { List_add(self, (void *)lexem); }

void List_free(List *self) {
  struct Node *tmp = self->head;
  int i = 0;
  while (tmp) {
    if (tmp->next) {
      struct Node *next = tmp->next;
      free(tmp);
      tmp = next;
    } else {
      free(tmp);
      tmp = 0;
    }
    i++;
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

void List_delete(List *self, void *elem) {
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

void List_delete_str(List *self, char *elem) {
  List_delete(self, (void *)elem);
}

struct Node *List_get_Node(List *self, int index) {
  struct Node *tmp = self->head;
  for (int i = 0; i < index; i++) {
    if (!tmp->next) {
      break;
    }
    tmp = tmp->next;
  }
  return tmp;
}

void *List_get(List *self, int index) {
  return List_get_Node(self, index)->data;
}

char *List_get_str(List *self, int index) {
  return (char *)List_get(self, index);
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

int List_len(List *self) {
  struct Node *tmp = self->head;
  int l = 0;
  while (tmp) {
    tmp = tmp->next;
    l++;
  }
  return l;
}

Stack *Stack_new() {
  Stack *tmp = malloc(sizeof(Stack));
  tmp->top = 0;
  return tmp;
}

void Stack_push(Stack *self, void *lexem) {
  struct Node *tmp = malloc(sizeof(struct Node));
  tmp->data = lexem;
  if (self->top) {
    tmp->next = self->top;
  } else {
    tmp->next = 0;
  }
  self->top = tmp;
}

void Stack_push_str(Stack *self, char *lexem) {
  Stack_push(self, (void *)lexem);
}

struct Node *Stack_pop_node(Stack *self) {
  struct Node *tmp = self->top;
  if (tmp) {
    self->top = tmp->next;
  }
  return tmp;
}

void *Stack_pop(Stack *self) {
  void *ret_v = 0;
  struct Node *tmp = Stack_pop_node(self);
  if (tmp) {
    ret_v = tmp->data;
    free(tmp);
  }
  return ret_v;
}

char *Stack_pop_str(Stack *self) {
  return (char *)Stack_pop(self);
}

void Stack_free(Stack *self) {
  while (self->top) {
    Stack_pop(self);
  }
}
