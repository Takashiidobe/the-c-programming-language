#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "Hi there\tbuddy\nLine two\n";
  const char *expected =
      "the count of blanks is: [2], tabs is: [1] and newlines is: [2]\n";

  assert_stdin_stdout(chapter_1_8, input, expected);
  return 0;
}
