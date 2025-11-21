#include "../test_utils.h"
#include "chapter-4.h"

int main(void) {
  ASSERT_DOUBLE_NEAR(123.45, atof_sci("123.45"), 1e-12);
  ASSERT_DOUBLE_NEAR(0.12345, atof_sci("123.45e-3"), 1e-12);
  ASSERT_DOUBLE_NEAR(123450000.0, atof_sci("123.45E+6"), 1e-6);
  ASSERT_DOUBLE_NEAR(-0.00012345, atof_sci("  -123.45e-6"), 1e-18);
  ASSERT_DOUBLE_NEAR(1.0, atof_sci("+1e0"), 1e-12);
  ASSERT_DOUBLE_NEAR(0.0, atof_sci("0e-10"), 1e-20);
  ASSERT_DOUBLE_NEAR(42.0, atof_sci("42e"), 1e-12);
  return 0;
}
