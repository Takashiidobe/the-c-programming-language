#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  const char *input = "HeLLo\nWORLD";
  const char *expected = "hello\nworld\n";
  assert_stdin_stdout(chapter_2_10, input, expected);
  return 0;
}
