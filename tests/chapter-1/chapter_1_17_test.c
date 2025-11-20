#include <stdio.h>
#include <string.h>

#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  char long_line1[86];
  memset(long_line1, 'a', 85);
  long_line1[85] = '\0';

  char long_line2[91];
  memset(long_line2, 'b', 90);
  long_line2[90] = '\0';

  char input[512];
  snprintf(input, sizeof(input), "tiny\n%s\nshorter\n%s", long_line1,
           long_line2);

  char expected[256];
  snprintf(expected, sizeof(expected), "%s\n%s\n", long_line1, long_line2);

  assert_stdin_stdout(chapter_1_17, input, expected);
  return 0;
}
