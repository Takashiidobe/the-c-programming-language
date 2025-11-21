#include "../test_utils.h"
#include "chapter-4.h"
#include <limits.h>
#include <stdio.h>

static void assert_itoa_matches(int value) {
  char actual[64];
  char expected[64];
  recursive_itoa(value, actual);
  snprintf(expected, sizeof(expected), "%d", value);
  ASSERT_STR_EQ(expected, actual);
}

int main(void) {
  char buffer[64];

  recursive_itoa(0, buffer);
  ASSERT_STR_EQ("0", buffer);

  recursive_itoa(12345, buffer);
  ASSERT_STR_EQ("12345", buffer);

  recursive_itoa(-9876, buffer);
  ASSERT_STR_EQ("-9876", buffer);

  assert_itoa_matches(INT_MAX);
  assert_itoa_matches(INT_MIN);
  assert_itoa_matches(42);
  assert_itoa_matches(-1);

  return 0;
}
