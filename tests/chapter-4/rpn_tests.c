#include "../test_utils.h"
#include "chapter-4.h"

static void run_calc_case(const char *input, const char *expected_output) {
  clear_stack();
  assert_stdin_stdout(calc, input, expected_output);
}

int main(void) {
  run_calc_case("10 3 %\n-3 2 *\n5 -2 +\n",
                "\t1\n\t-6\n\t3\n");

  run_calc_case("2 3 ? d +\nv 4 +\n5 9 s -\n8 1 2 + c 7 8 +\n",
                "\t3\n\t6\n\t10\n\t4\n\t15\n");

  run_calc_case("A 5 =\nA 2 *\n0 SIN\n1 exp\n2 3 PoW\n",
                "\t5\n\t10\n\t0\n\t2.7182818\n\t8\n");
  return 0;
}
