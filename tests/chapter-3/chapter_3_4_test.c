#include <limits.h>

#include "../test_utils.h"
#include "chapter-3.h"

int main(void) {
  char buffer[64];

  itoa(buffer, 0);
  ASSERT_STR_EQ("0", buffer);

  itoa(buffer, 12345);
  ASSERT_STR_EQ("12345", buffer);

  itoa(buffer, -9876);
  ASSERT_STR_EQ("-9876", buffer);

  itoa(buffer, (long)LONG_MIN);
  ASSERT_STR_EQ("-9223372036854775808", buffer);

  return 0;
}
