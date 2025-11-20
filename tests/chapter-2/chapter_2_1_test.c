#include <limits.h>

#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  char expected[512];
  snprintf(expected, sizeof(expected),
           "\nBits of type char: %d\n\n"
           "Maximum numeric value of type char: %d\n"
           "Minimum numeric value of type char: %d\n\n"
           "Maximum value of type signed char: %d\n"
           "Minimum value of type signed char: %d\n\n"
           "Minimum value of type unsigned char: %u\n"
           "Maximum value of type unsigned char: %u\n\n"
           "Maximum value of type short: %d\n"
           "Minimum value of type short: %d\n\n"
           "Minimum value of type unsigned short: %u\n"
           "Maximum value of type unsigned short: %u\n\n"
           "Maximum value of type int: %d\n"
           "Minimum value of type int: %d\n\n"
           "Maximum value of type unsigned int: %u\n\n"
           "Maximum value of type long: %ld\n"
           "Minimum value of type long: %ld\n\n"
           "Maximum value of type unsigned long: %lu\n\n",
           CHAR_BIT, CHAR_MAX, CHAR_MIN, SCHAR_MAX, SCHAR_MIN, 0u,
           (unsigned)UCHAR_MAX, SHRT_MAX, SHRT_MIN, 0u, (unsigned)USHRT_MAX,
           INT_MAX, INT_MIN, UINT_MAX, LONG_MAX, LONG_MIN, ULONG_MAX);

  assert_fd_outputs(STDOUT_FILENO, chapter_2_1, expected);
  return 0;
}
