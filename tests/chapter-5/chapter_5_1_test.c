#include "../test_utils.h"
#include "chapter-5.h"
#include "helpers.h"

int main(void) {
  int value = -1;

  load_input("123 ");
  ASSERT_INT_EQ(' ', getint(&value));
  ASSERT_INT_EQ(123, value);
  drain_input();

  load_input("\t-42q");
  ASSERT_INT_EQ('q', getint(&value));
  ASSERT_INT_EQ(-42, value);
  drain_input();

  load_input("   +77\t");
  ASSERT_INT_EQ('\t', getint(&value));
  ASSERT_INT_EQ(77, value);
  drain_input();

  value = 555;
  load_input("+ abc");
  ASSERT_INT_EQ(0, getint(&value));
  ASSERT_INT_EQ(555, value);
  ASSERT_INT_EQ('+', getch());
  ASSERT_INT_EQ(' ', getch());
  drain_input();

  value = 777;
  load_input("-z9");
  ASSERT_INT_EQ(0, getint(&value));
  ASSERT_INT_EQ(777, value);
  ASSERT_INT_EQ('-', getch());
  ASSERT_INT_EQ('z', getch());
  drain_input();

  load_input("15abc");
  ASSERT_INT_EQ('a', getint(&value));
  ASSERT_INT_EQ(15, value);
  ASSERT_INT_EQ('a', getch());
  drain_input();

  return 0;
}
