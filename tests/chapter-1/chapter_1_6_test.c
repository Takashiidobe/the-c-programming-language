#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *expected = "Press a key.\n"
                         "The expression getchar() != EOF evaluates to 1\n";

  assert_stdin_stdout(chapter_1_6, "x", expected);
  return 0;
}
