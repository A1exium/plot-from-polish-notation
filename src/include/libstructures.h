typedef struct List_s {
  char *lexem;
  List *next;
} List;

typedef struct Stack_s {
  void *lexem;
  Stack *prev;
} Stack;

List *InitList();

void ListPush(char *lexem);
void ListFree(List *head);
void StackPush(char *lexem);
