#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "hello    world   there\ntrim   spaces\n";
  const char *expected = "hello world there\ntrim spaces\n";

  assert_stdin_stdout(chapter_1_9, input, expected);
  return 0;
}
