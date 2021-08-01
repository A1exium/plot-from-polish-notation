#ifndef SRC_INCLUDE_STR_H_
#define SRC_INCLUDE_STR_H_
#include <stdlib.h>
extern int s21_strlen(char *string);
extern int s21_strcmp(char *s1, char *s2);
extern char *s21_strcpy(char *destptr, char *srcptr);
extern char *s21_strcat(char *destptr, char *srcptr);
extern int s21_strchr(char *string, char symbol);
extern int s21_strstr(char *s1, char *s2);
extern int s21_strtok(char *string, char delim, int start);
char *s21_strslice(char *string, int start, int end);
#endif  // SRC_INCLUDE_STR_H_
