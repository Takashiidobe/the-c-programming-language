#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  const char *input = "party\nrhythm\n";
  const char *expected =
      "1\n"
      "-1\n";
  assert_stdin_stdout(chapter_2_5, input, expected);
  return 0;
}
