#include "dbg.h"
#include "parsing.h"
#include "str.h"

void TestEval_1() {
  printf("Testing Eval: test 1\n");
  char example[] = "1 2 + 4 * 3 +";
  printf("in: {%s}\n", example);
  double ans = Eval(example, 1);
  printf("out: {%lf}\n", ans);
  Assert(ans, 15);
}

int main(void) { TestEval_1(); }