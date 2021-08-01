#ifndef SRC_INCLUDE_INPUT_H_
#define SRC_INCLUDE_INPUT_H_
#include <stdio.h>
#include <stdlib.h>

#define OPERAND_CODE 1
#define OPERATOR_CODE 2
#define FUNCTION_CODE 3
#define BRACKET_CODE 4
#define SPACE_CODE 5
#define ARG_CODE 6
#define INVALID_SYMBOL 7
#define START_CODE 8

char* Input();
int IsValidInput(char* str);
int GetLen(char* str);
int IsValidOperand(char* str, int start_index, int prev_lexem);
int GetOperandLen(char* str, int start_index);
int GetNumberLastCharIndex(char* str, int start_index);
int IsValidOperator(char* str, int start_index, int str_len, int prev_lexem);
int IsValidFunction(char* str, int start_index, int prev_lexem);
int DefineLexem(char* str, int index);
int IsFunctionArgument(int prev_lexem);
int IsKnownFunction(char* str, int start_index);
int StrCmp(char* str1, char* str2, int len1, int len2);
int GetLexemLen(char* str, int start_index);
int IsValidBracket(char* str, int start_index, int* open_brackets,
                   int prev_lexem);
char GetCharAfterSpaces(char* str, int start_index, int* new_char_index);
char* FormatSring(char* str);
char* ProcessMinuses(char* str);
void Red();
void ResetColor();
void PrintErrorMessage(char* str);
#endif  // SRC_INCLUDE_INPUT_H_
