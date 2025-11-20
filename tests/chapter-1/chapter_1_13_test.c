#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "one two\nthree four five\nsix";
  const char *expected = "3: 3\n4: 2\n5: 1\n";
  assert_stdin_stdout(chapter_1_13, input, expected);
  return 0;
}
