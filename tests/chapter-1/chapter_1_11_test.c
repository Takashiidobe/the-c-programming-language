#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "one two\nthree\n\n";
  const char *expected = "3 3 15\n";

  assert_stdin_stdout(chapter_1_11, input, expected);
  return 0;
}
