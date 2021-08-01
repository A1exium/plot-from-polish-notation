struct Node {
  void *data;
  struct Node *next;
};

typedef struct List_s {
  struct Node *head;
} List;

extern List *List_new();

extern void List_add(List *self, void *value);
extern void List_add_str(List *self, char *lexem);

extern void List_free(List *self);
extern void List_remove(List *self, int index);

extern void List_delete(List *self, void *elem);
extern void List_delete_str(List *self, char *elem);

extern void *List_get(List *self, int index);
extern char *List_get_str(List *self, int index);
extern struct Node *List_get_Node(List *self, int index);

extern int List_contains(List *self, char *elem);
extern int List_len(List *self);

typedef struct Stack_s {
  struct Node *top;
} Stack;

extern Stack *Stack_new();

extern void Stack_push(Stack *self, void *value);
extern void Stack_push_str(Stack *self, char *lexem);
void Stack_push_double(Stack *self, double value);

extern void *Stack_pop(Stack *self);
extern char *Stack_pop_str(Stack *self);
extern struct Node *Stack_pop_node(Stack *self);
double Stack_pop_double(Stack *self);

extern void Stack_free(Stack *self);
