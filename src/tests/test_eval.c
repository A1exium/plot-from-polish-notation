#include "dbg.h"
#include "parsing.h"
#include "str.h"

const double kZero = 1E-6;

void TestEval(int num, char *example, double x, double expect) {
  printf("Testing Eval: test %d\n", num);
  printf("in: {%s}\n", example);
  double ans = Eval(example, x);
  printf("out: {%lf}\n", ans);
  Assert(ans - expect <= kZero, 1);
}

int main(void) { 
  TestEval(1, "1 2 + 4 * 3 +", 1, 15);
  TestEval(2, "5 3 ^ 5 5 * / 10 +", 5, 15);
}