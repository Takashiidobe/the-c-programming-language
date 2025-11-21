#include "../test_utils.h"
#include "chapter-3.h"

int main(void) {
  char buffer[64];

  ASSERT_STR_EQ("0", itob(buffer, 0, 2));
  ASSERT_STR_EQ("ff", itob(buffer, 255, 16));
  ASSERT_STR_EQ("-1010", itob(buffer, -10, 2));
  ASSERT_STR_EQ("-a3", itob(buffer, -123, 12));
  ASSERT_STR_EQ("", itob(buffer, 42, 1));

  return 0;
}
