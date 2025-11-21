#include "../test_utils.h"
#include "chapter-4.h"

struct pair {
  int left;
  int right;
};

int main(void) {
  int a = 5;
  int b = -3;
  swap(int, a, b);
  ASSERT_INT_EQ(-3, a);
  ASSERT_INT_EQ(5, b);

  double x = 1.25;
  double y = -9.5;
  swap(double, x, y);
  ASSERT_DOUBLE_NEAR(-9.5, x, 1e-12);
  ASSERT_DOUBLE_NEAR(1.25, y, 1e-12);

  struct pair p1 = {1, 2};
  struct pair p2 = {3, 4};
  swap(struct pair, p1, p2);
  ASSERT_INT_EQ(3, p1.left);
  ASSERT_INT_EQ(4, p1.right);
  ASSERT_INT_EQ(1, p2.left);
  ASSERT_INT_EQ(2, p2.right);

  int arr[] = {1, 2, 3};
  swap(int, arr[0], arr[2]);
  ASSERT_INT_EQ(3, arr[0]);
  ASSERT_INT_EQ(2, arr[1]);
  ASSERT_INT_EQ(1, arr[2]);

  return 0;
}
