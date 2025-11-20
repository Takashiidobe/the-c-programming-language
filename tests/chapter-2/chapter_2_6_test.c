#include "../test_utils.h"
#include "chapter-2.h"

int main(void) {
  ASSERT_INT_EQ(0xBA, setbits(0xAA, 5, 3, 0x07));
  ASSERT_INT_EQ(0x34, setbits(0x3C, 4, 2, 0x02));
  ASSERT_INT_EQ(0x0F, setbits(0x00, 3, 4, 0xFF));
  ASSERT_INT_EQ(0xFC, setbits(0xF0, 3, 2, 0xFF));
  ASSERT_INT_EQ(0xAA, setbits(0xAA, 5, 0, 0xFF));
  return 0;
}
