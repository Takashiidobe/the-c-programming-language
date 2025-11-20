#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  const char *input = "0x2a\n15\n";
  const char *expected =
      "0x2a as hexadecimal is: 42\n"
      "15 as hexadecimal is: 21\n";
  assert_stdin_stdout(chapter_2_3, input, expected);
  return 0;
}
