#include "graph.h"
#include "infixtoprefix.h"
#include "input.h"
#define MAX_ROWS 25
#define MAX_COLUMNS 80

int main() {
  char* input = Input();
  if (s21_strlen(input) > 0 && IsValidInput(input)) {
    char* ready_str = ProcessMinuses(input);
    char* polish = ConvertInfToPost(ready_str);
    MakeGraph(polish, MAX_ROWS, MAX_COLUMNS);
    free(ready_str);
    free(polish);
  } else {
    PrintErrorMessage("Incorrect input!");
  }
  free(input);
  return 0;
}
