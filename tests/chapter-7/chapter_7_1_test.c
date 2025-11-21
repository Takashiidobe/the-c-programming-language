#include "../test_utils.h"
#include "chapter-7.h"

static int run_as_upper(void) {
  char *argv[] = {"upper", NULL};
  return chapter_7_1(1, argv);
}

static int run_as_lower(void) {
  char *argv[] = {"./bin/Lower", NULL};
  return chapter_7_1(1, argv);
}

int main(void) {
  const char *input = "AbCd\n";
  const char *expected_upper = "ABCD\n";
  const char *expected_lower = "abcd\n";

  assert_stdin_stdout(run_as_upper, input, expected_upper);
  assert_stdin_stdout(run_as_lower, input, expected_lower);
  return 0;
}
