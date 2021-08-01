#include "graph.h"
#include "infixtoprefix.h"
#include "input.h"
#define MAX_ROWS 25
#define MAX_COLUMNS 80

int main() {
  char* input = Input();  // TODO(prozella) FREE IT!
  if (IsValidInput(input)) {
    char* ready_str = ProcessMinuses(
        input);  // эту строку нужно перевести в обратную польскую
    printf("{%s}\n", ready_str);
    ready_str = ConvertInfToPost(ready_str);
    free(input);
    MakeGraph(ready_str, MAX_ROWS,
              MAX_COLUMNS);  // затем эту строку в польской сюда кинуть
    // TODO(ANY) ADD FREE FOR STACK STRING
  } else {
    PrintErrorMessage("Incorrect input!");
  }
  // int ncp;
  // char test[] = "cos(";
  // char new_symb = GetCharAfterSpaces(test, 0 + GetLexemLen(test, 0) - 1,
  // &ncp); printf("%c , %d, %d", new_symb, ncp, GetLen(test));
  // printf("%d", IsValidInput(test));
  // GetLexemLen("cos", 0);
  // int test;
  // scanf("%d", &test);
  // printf("\n%d", IsValidFunction("cossinln", test, OPERATOR_CODE));
  return 0;
}