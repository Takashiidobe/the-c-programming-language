#include <stdio.h>

#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  char expected[64];
  snprintf(expected, sizeof(expected), "The value of EOF is: [%d]\n", EOF);
  assert_fd_outputs(STDOUT_FILENO, chapter_1_7, expected);
  return 0;
}
