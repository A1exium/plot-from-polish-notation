#include <stdio.h>

void Assert(int a, int b) {
  if (a == b) {
    printf("SUCCESS\n");
  } else {
    printf("FAIL\n");
  }
}