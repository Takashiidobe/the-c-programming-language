#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *expected = "C     F\n"
                         "\n"
                         "  0   32.0\n"
                         " 20   68.0\n"
                         " 40  104.0\n"
                         " 60  140.0\n"
                         " 80  176.0\n"
                         "100  212.0\n"
                         "120  248.0\n"
                         "140  284.0\n"
                         "160  320.0\n"
                         "180  356.0\n"
                         "200  392.0\n"
                         "220  428.0\n"
                         "240  464.0\n"
                         "260  500.0\n"
                         "280  536.0\n"
                         "300  572.0\n";

  assert_fd_outputs(STDOUT_FILENO, chapter_1_4, expected);
  return 0;
}
