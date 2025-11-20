#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input = "word1 word2\tword3\n\nword4";
  const char *expected = "word1\nword2\nword3\nword4\n";

  assert_stdin_stdout(chapter_1_12, input, expected);
  return 0;
}
