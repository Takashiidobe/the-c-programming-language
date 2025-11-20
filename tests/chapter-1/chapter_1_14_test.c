#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "aAbB09!?";
  const char *expected = "0: 1\n9: 1\nA: 1\nB: 1\na: 1\nb: 1\n";
  assert_stdin_stdout(chapter_1_14, input, expected);
  return 0;
}
