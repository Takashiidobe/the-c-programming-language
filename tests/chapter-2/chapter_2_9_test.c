#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  const char *input = "5\n10";
  const char *expected =
      "The bitcount of 5 is: 2\n"
      "The bitcount of 10 is: 2\n";
  assert_stdin_stdout(chapter_2_9, input, expected);
  return 0;
}
