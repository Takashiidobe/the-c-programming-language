#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  ASSERT_INT_EQ(0xE3, invert(0xFF, 4, 3));
  ASSERT_INT_EQ(0x0F, invert(0x00, 3, 4));
  ASSERT_INT_EQ(0x55, invert(0xAA, 7, 8));
  ASSERT_INT_EQ(0x1234, invert(0x1234, 5, 0));
  ASSERT_INT_EQ(0x1234A978, invert(0x12345678, 15, 8));
  return 0;
}
