#include "input.h"

char* Input() {
  int scan_val = 0, size = 10, counter;
  char* str = calloc(size, sizeof(char));
  char c;
  for (counter = 0; (scan_val = scanf("%c", &c)) > 0 && c != '\n' && c != EOF;
       counter++) {
    str[counter] = c;
    if (counter == size - 1) {
      size *= 2;
      char* tmp = realloc(str, sizeof(char) * size);
      if (tmp) {
        str = tmp;
      } else {
        free(str);
        str = 0;
      }
    }
  }
  if (scan_val < 0) {
    str[0] = 'z';  // to catch signals
  }
  str[counter] = '\0';
  return str;
}

int IsValidInput(char* str) {
  int len = GetLen(str);
  int valid_input = 1;
  int open_brackets = 0;
  int prev_lexem = START_CODE;

  for (int cur_pos = 0, cur_lexem; cur_pos < len && valid_input;
       cur_pos = cur_pos + GetLexemLen(str, cur_pos)) {
    cur_lexem = DefineLexem(str, cur_pos);
    switch (cur_lexem) {
      case OPERAND_CODE:
        valid_input = IsValidOperand(str, cur_pos, prev_lexem);
        prev_lexem = OPERAND_CODE;
        break;
      case OPERATOR_CODE:
        valid_input = IsValidOperator(str, cur_pos, len, prev_lexem);
        prev_lexem = OPERATOR_CODE;
        break;
      case FUNCTION_CODE:
        valid_input = IsValidFunction(str, cur_pos, prev_lexem);
        prev_lexem = FUNCTION_CODE;
        break;
      case ARG_CODE:
        valid_input = IsFunctionArgument(prev_lexem);
        prev_lexem = ARG_CODE;
        break;
      case SPACE_CODE:
        continue;
      case BRACKET_CODE:
        valid_input = IsValidBracket(str, cur_pos, &open_brackets, prev_lexem);
        prev_lexem = BRACKET_CODE;
        break;
      default:
        valid_input = 0;
        break;
    }
  }
  if (open_brackets != 0) {
    valid_input = 0;
  }
  return valid_input;
}
int GetLen(char* str) {
  int counter;
  for (counter = 0; str[counter] != '\0'; counter++) {
  }
  return counter;
}

int IsValidOperand(char* str, int start_index, int prev_lexem) {
  int is_valid = 1;
  if (GetOperandLen(str, start_index) > 10 || prev_lexem == OPERAND_CODE) {
    is_valid = 0;
  }
  return is_valid;
}

int IsValidBracket(char* str, int start_index, int* open_brackets,
                   int prev_lexem) {
  int is_valid = 1;
  char symb = str[start_index];
  if (*open_brackets <= 0 && symb == ')') {
    is_valid = 0;
  } else if (symb == '(') {
    (*open_brackets)++;
  } else if (symb == ')') {
    (*open_brackets)--;
  }
  if ((prev_lexem == OPERAND_CODE || prev_lexem == ARG_CODE) && symb == '(') {
    is_valid = 0;
  }
  return is_valid;
}

int GetOperandLen(char* str, int start_index) {
  int last_char_ind = GetNumberLastCharIndex(str, start_index);
  int len = (last_char_ind + 1) - start_index;
  return len;
}

int GetNumberLastCharIndex(char* str, int start_index) {
  int cur_pos;
  for (cur_pos = start_index;; cur_pos++) {
    if (str[cur_pos] == '\0' || str[cur_pos] == EOF ||
        !(str[cur_pos] >= '0' && str[cur_pos] <= '9')) {
      return cur_pos - 1;
    }
  }
}

int IsValidOperator(char* str, int start_index, int str_len, int prev_lexem) {
  int is_valid = 1;
  if (prev_lexem == OPERATOR_CODE) {
    is_valid = 0;
  }
  if (prev_lexem == START_CODE) {
    int operator= str[start_index];
    if (operator!= '-') {
      is_valid = 0;
    }
  }
  if (str_len - 1 == start_index) {
    is_valid = 0;
  }
  return is_valid;
}

int IsValidFunction(char* str, int start_index, int prev_lexem) {
  int is_valid = 0;
  int new_char_pos;
  if (prev_lexem == BRACKET_CODE && prev_lexem == OPERATOR_CODE &&
      prev_lexem == START_CODE) {
    is_valid = 1;
  }
  if (is_valid) {
    is_valid = IsKnownFunction(str, start_index);
  }
  if (!is_valid) {
    is_valid = 0;
    char new_symb = GetCharAfterSpaces(
        str, start_index + GetLexemLen(str, start_index), &new_char_pos);
    if (new_symb != '\0') {
      if (new_symb == '(') {
        new_symb = GetCharAfterSpaces(
            str, new_char_pos + GetLexemLen(str, new_char_pos), &new_char_pos);
        if (new_symb != '\0' && DefineLexem(&new_symb, 0) != INVALID_SYMBOL &&
            new_symb != ')') {
          is_valid = 1;
        }
      }
    }
  }
  return is_valid;
}

char GetCharAfterSpaces(char* str, int start_index, int* new_char_index) {
  int str_len = GetLen(str);
  int cur_pos;
  char res;
  for (cur_pos = start_index; cur_pos < str_len && str[cur_pos] == ' ';
       cur_pos++) {
  }
  if (cur_pos >= str_len) {
    res = '\0';
    *new_char_index = start_index;
  } else {
    res = str[cur_pos];
    *new_char_index = cur_pos;
  }
  return res;
}

int DefineLexem(char* str, int index) {
  char symb = str[index];
  int return_code = INVALID_SYMBOL;
  switch (symb) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return_code = OPERATOR_CODE;
      break;
    case '(':
    case ')':
      return_code = BRACKET_CODE;
      break;
    case 's':
    case 'c':
    case 't':
    case 'l':
      return_code = FUNCTION_CODE;
      break;
    case ' ':
      return_code = SPACE_CODE;
      break;
    default:
      return_code = INVALID_SYMBOL;
      break;
  }
  if (symb == 'x') {
    return_code = ARG_CODE;
  }
  if (return_code == INVALID_SYMBOL) {
    if (symb >= '0' && symb <= '9') {
      return_code = OPERAND_CODE;
    }
  }
  return return_code;
}

int IsFunctionArgument(int prev_lexem) {
  int is_arg = 1;
  if (prev_lexem != OPERATOR_CODE && prev_lexem != BRACKET_CODE &&
      prev_lexem != START_CODE) {
    is_arg = 0;
  }
  return is_arg;
}

int IsKnownFunction(char* str, int start_index) {
  int is_known = 0;
  is_known = StrCmp(&str[start_index], "sin", GetLexemLen(str, start_index), 3);
  if (!is_known) {
    is_known =
        StrCmp(&str[start_index], "cos", GetLexemLen(str, start_index), 3);
  }
  if (!is_known) {
    is_known =
        StrCmp(&str[start_index], "tg", GetLexemLen(str, start_index), 2);
  }
  if (!is_known) {
    is_known =
        StrCmp(&str[start_index], "ctg", GetLexemLen(str, start_index), 3);
  }
  if (!is_known) {
    is_known =
        StrCmp(&str[start_index], "sqrt", GetLexemLen(str, start_index), 4);
  }
  if (!is_known) {
    is_known =
        StrCmp(&str[start_index], "ln", GetLexemLen(str, start_index), 2);
  }
  return is_known;
}

int GetLexemLen(char* str, int start_index) {
  int str_len = GetLen(str);
  int lexem_len = 0;
  int lexem_type = DefineLexem(str, start_index);
  char cur_symb = str[start_index];
  if (lexem_type == BRACKET_CODE || lexem_type == ARG_CODE ||
      lexem_type == OPERATOR_CODE || lexem_type == SPACE_CODE) {
    lexem_len = 1;
  }
  if (lexem_type == OPERAND_CODE) {
    lexem_len = GetOperandLen(str, start_index);
  }
  if (lexem_type == FUNCTION_CODE) {
    if (cur_symb == 't' || cur_symb == 'l') {
      if (start_index + 2 <= str_len) {
        lexem_len = 2;
      }
    } else if (cur_symb == 's' || cur_symb == 'c') {
      cur_symb = str[start_index + 1];
      if (cur_symb == 'i' || cur_symb == 'o' || cur_symb == 't') {
        if (start_index + 3 <= str_len) {
          lexem_len = 3;
        }
      } else if (cur_symb == 'q') {
        if (start_index + 4 <= str_len) {
          lexem_len = 4;
        }
      }
    }
  }
  return lexem_len;
}

int StrCmp(char* str1, char* str2, int len1, int len2) {
  int is_equal = 1;
  if (len1 != len2) {
    is_equal = 0;
  }
  for (int i = 0; i < len1 && is_equal; i++) {
    if (str1[i] != str2[i]) {
      is_equal = 0;
    }
  }
  return is_equal;
}

char* ProcessMinuses(char* str) {
  int str_len = GetLen(str);
  int new_str_pos = 0;
  int prev_lexem = START_CODE, cur_lexem = START_CODE;
  char* new_str = calloc(str_len, sizeof(char));
  char fst_symb;
  for (int cur_pos = 0; cur_pos < str_len;) {
    if (str[cur_pos] == ' ') {
      cur_pos++;
      continue;
    }
    int lex_len = GetLexemLen(str, cur_pos);
    cur_lexem = DefineLexem(str, cur_pos);
    fst_symb = str[cur_pos];
    for (int i = 0; i < lex_len; i++, new_str_pos++, cur_pos++) {
      new_str[new_str_pos] = str[cur_pos];
    }
    if (cur_pos < str_len && !(fst_symb == '-' && (prev_lexem == BRACKET_CODE ||
                                                   prev_lexem == START_CODE))) {
      new_str[new_str_pos] = ' ';

      new_str_pos++;
    }
    prev_lexem = cur_lexem;
  }
  new_str[new_str_pos] = '\0';
  return new_str;
}

void Red() { printf("\033[0;31m"); }
void ResetColor() { printf("\033[0m"); }
void PrintErrorMessage(char* str) {
  Red();
  printf("%s\n", str);
  ResetColor();
}
