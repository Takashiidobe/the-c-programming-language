#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  const char *input = "hello world\nsky\n";
  const char *expected =
      "hello world with vowels removed: [hll wrld]\n"
      "sky with vowels removed: [sky]\n";
  assert_stdin_stdout(chapter_2_4, input, expected);
  return 0;
}
