#include "include/input.h"

int main() {
  char* input = Input();  // TODO(prozella) FREE IT!
  if (IsValidInput(input)) {
    char* test = ProcessMinuses(input);
    printf("%s", test);
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
