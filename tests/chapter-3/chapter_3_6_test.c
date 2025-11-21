#include "../test_utils.h"
#include "chapter-3.h"

int main(void) {
  char buffer[64];

  ASSERT_STR_EQ("42", itoa_min_width(buffer, 42, 0));
  ASSERT_STR_EQ("   42", itoa_min_width(buffer, 42, 5));
  ASSERT_STR_EQ("   -7", itoa_min_width(buffer, -7, 5));
  ASSERT_STR_EQ("-1234", itoa_min_width(buffer, -1234, 3));

  return 0;
}
