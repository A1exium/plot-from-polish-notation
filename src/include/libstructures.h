struct Node {
  void *data;
  struct Node *next;
};

typedef struct List_s {
  struct Node *head;
} List;

extern List *List_new();
extern void List_add(List *self, char *lexem);
extern void List_free(List *self);
extern void List_remove(List *self, int index);
extern void List_delete(List *self, char *elem);
extern char *List_get(List *self, int index);
extern int List_contains(List *self, char *elem);
extern int List_len(List *self);
typedef struct Stack_s {
  struct Node *top;
} Stack;

extern Stack *Stack_new();
extern void Stack_push_str(Stack *self, char *lexem);
extern void *Stack_pop(Stack *self);
extern void Stack_free(Stack *self);
