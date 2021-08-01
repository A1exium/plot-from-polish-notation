#include "str.h"

#include <stdlib.h>
#include <stdio.h>

int s21_strlen(char *string) {
  const char *s;
  for (s = string; *s; ++s) {
  }
  return s - string;
}

int s21_strcmp(char *s1, char *s2) {
  int tmp = s21_strlen(s1), ret_v = 1;
  if (tmp == s21_strlen(s2)) {
    for (int i = 0; i < tmp; i++) {
      if (s1[i] != s2[i]) {
        ret_v = 0;
        break;
      }
    }
  } else {
    ret_v = 0;
  }
  return ret_v;
}

char *s21_strcpy(char *destptr, char *srcptr) {
  int tmp = s21_strlen(srcptr);
  for (int i = 0; i < tmp + 1; i++) {
    destptr[i] = srcptr[i];
  }
  return destptr;
}

char *s21_strcat(char *destptr, char *srcptr) {
  int l1 = s21_strlen(destptr);
  int l2 = s21_strlen(srcptr);
  char *tmp = calloc(l1 + l2, sizeof(char));
  s21_strcpy(tmp, destptr);
  for (int i = l1; i < l2 + l1; i++) {
    tmp[i] = srcptr[i - l1];
  }
  return tmp;
}

int s21_strchr(char *string, char symbol) {
  int ret = -1;
  for (int i = 0; i < s21_strlen(string); i++) {
    if (string[i] == symbol) {
      ret = i;
      break;
    }
  }
  return ret;
}

int s21_strstr(char *s1, char *s2) {
  int ret = -1, l1 = s21_strlen(s1), l2 = s21_strlen(s2);
  for (int i = 0; i < l1; i++) {
    int j = 0;
    for (j = 0; j < l1 && j < l2 && s1[i + j] == s2[j]; j++) {
    }
    if (j == l2) {
      ret = i;
      break;
    }
  }
  return ret;
}

int s21_strtok(char *string, char delim, int start) {
  int flag = s21_strlen(string);
  for (int i = start; i < flag; i++) {
    if (string[i] == delim) {
      flag = i;
      break;
    }
  }
  return flag;
}

char *s21_strslice(char *string, int start, int end) {
  char *tmp = malloc((end - start) * sizeof(char));
  for (int i = start; i < end; i++) {
    tmp[i - start] = string[i];
  }
  return tmp;
}