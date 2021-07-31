#include <stdio.h>
#include <stdlib.h>

#define OPERAND_CODE 1
#define OPERATOR_CODE 2
#define FUNCTION_CODE 3
#define INVALID_SYMBOL 4

char* Input();
int IsValidInput(char* str);
int GetLen(char* str);
int IsValidOperand(char* str, int start_index);
int GetOperandLen(char* str, int start_index);
int GetOperandLastCharIndex(char* str, int start_index);
int IsValidOperator();
int IsValidFunction();
int DefineLexem(char* str, int index);
int IsFunctionArgument(char* str, int index);

int main() {
  char c[10];
  scanf("%s", c);
  printf("%d", DefineLexem(c, 0));
  return 0;
}

char* Input() {
  int scan_val = 0, size = 10, counter;
  char* str = calloc(size, sizeof(char));
  char c;
  for (counter = 0; (scan_val = scanf("%c", &c)) > 0; counter++) {
    str[counter] = c;
    if (counter == size - 1) {
      size *= 2;
      realloc(str, sizeof(char) * size);
    }
  }
  if (scan_val < 0) {
    str[0] = 'z';  // to catch signals
  }
}

int IsValidInput(char* str) {
  int len = GetLen(str);
  int valid_input = 1;
  // for (int i = 0; i < len && valid_input; i++) {
  // if () }
}

int GetLen(char* str) {
  int counter;
  for (counter = 0; str[counter] != '\0'; counter++) {
  }
  return counter;
}

int IsValidOperand(char* str, int start_index) {
  int is_valid = 1;
  if (GetOperandLen(str, start_index) > 10) {
    is_valid = 0;
  }
  return is_valid;
}

int GetOperandLen(char* str, int start_index) {
  int last_char_ind = GetOperandLastCharIndex(str, start_index);
  int len = (last_char_ind + 1) - start_index;
  return len;
}

int GetOperandLastCharIndex(char* str, int start_index) {
  int cur_pos = start_index;
  for (cur_pos = 0;; cur_pos++) {
    if (str[cur_pos] == '\0' || !(str[cur_pos] >= '0' && str[cur_pos] <= '9')) {
      return cur_pos - 1;
    }
  }
}

int IsValidOperator() {}

int IsValidFunction() {}

int DefineLexem(char* str, int index) {
  char symb = str[index];
  int return_code = INVALID_SYMBOL;
  switch (symb) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
    case ')':
      return_code = OPERATOR_CODE;
      break;
    case 's':
    case 'c':
    case 't':
    case 'l':
      return_code = FUNCTION_CODE;
      break;
    default:
      return_code = INVALID_SYMBOL;
      break;
  }
  if (symb == 'x') {
    return_code = IsFunctionArgument(str, index);
  }
  if (return_code == INVALID_SYMBOL) {
    if (symb >= '0' && symb <= '9') {
      return_code = OPERAND_CODE;
    }
  }
  return return_code;
}

int IsFunctionArgument(char* str, int index) {
  int is_arg = FUNCTION_CODE, len = index + GetLen(str);

  if (index == 0) {
    is_arg = INVALID_SYMBOL;
  }
  if (index == len - 1) {
    is_arg = INVALID_SYMBOL;
  }

  if (is_arg) {
    if (!(str[index - 1] == '(' &&
          str[index + 1] == ')')) {  // one edge case is missing
      is_arg = INVALID_SYMBOL;
    }
  }
  return is_arg;
}