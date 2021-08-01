#include "dbg.h"
#include "infixtoprefix.h"

int main(void) {
  printf("%s\n", ConvertInfToPost("5 + 1"));
  printf("%s\n", ConvertInfToPost("5 + 1 * 2"));
  printf("%s\n", ConvertInfToPost("5 + 2 + 1 * 2"));
  printf("%s\n", ConvertInfToPost("5 + 2 ^ 3 + 1 * 2"));
  printf("%s\n", ConvertInfToPost("5 * ( 2 + 3 )"));
  printf("%s\n", ConvertInfToPost("5 * sin ( 2 + 3 )"));
  printf("%s\n", ConvertInfToPost("5 * ( 2 + 3 )"));
  printf("%s\n", ConvertInfToPost("5 * ( 2 + -3 )"));
  printf("%s\n", ConvertInfToPost("ln ( sin ( x ) + 1 )"));
}