#include "../test_utils.h"
#include "chapter-5.h"
#include "helpers.h"

int main(void) {
  double value = 0.0;

  load_input("123.75,");
  ASSERT_INT_EQ(',', getfloat(&value));
  ASSERT_DOUBLE_NEAR(123.75, value, 1e-9);
  drain_input();

  load_input("   -0.5 ");
  ASSERT_INT_EQ(' ', getfloat(&value));
  ASSERT_DOUBLE_NEAR(-0.5, value, 1e-9);
  drain_input();

  load_input("+.875!");
  ASSERT_INT_EQ('!', getfloat(&value));
  ASSERT_DOUBLE_NEAR(0.875, value, 1e-9);
  drain_input();

  load_input("77.\n");
  ASSERT_INT_EQ('\n', getfloat(&value));
  ASSERT_DOUBLE_NEAR(77.0, value, 1e-9);
  drain_input();

  load_input("42foo");
  ASSERT_INT_EQ('f', getfloat(&value));
  ASSERT_DOUBLE_NEAR(42.0, value, 1e-9);
  ASSERT_INT_EQ('f', getch());
  drain_input();

  value = 1.25;
  load_input("+ abc");
  ASSERT_INT_EQ(0, getfloat(&value));
  ASSERT_DOUBLE_NEAR(1.25, value, 1e-9);
  ASSERT_INT_EQ('+', getch());
  ASSERT_INT_EQ(' ', getch());
  drain_input();

  value = 2.5;
  load_input(".xyz");
  ASSERT_INT_EQ(0, getfloat(&value));
  ASSERT_DOUBLE_NEAR(2.5, value, 1e-9);
  ASSERT_INT_EQ('.', getch());
  drain_input();

  return 0;
}
