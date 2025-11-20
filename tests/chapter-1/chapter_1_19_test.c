#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "hello\nworld";
  const char *expected = "olleh\ndlrow\n";
  assert_stdin_stdout(chapter_1_19, input, expected);
  return 0;
}
