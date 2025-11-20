#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  const char *input = "Hello, world!\n";
  const char *expected = "Hello, world!\n";
  assert_stdin_stdout(chapter_2_2, input, expected);
  return 0;
}
