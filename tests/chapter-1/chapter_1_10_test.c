#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char input[] = "A\tB\bC\\\n";
  const char *expected = "A\\tB\\bC\\\\\n";

  assert_stdin_stdout(chapter_1_10, input, expected);
  return 0;
}
