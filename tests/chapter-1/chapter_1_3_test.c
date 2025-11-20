#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *expected = "F       C\n"
                         "0\t-17\n"
                         "20\t-6\n"
                         "40\t4\n"
                         "60\t15\n"
                         "80\t26\n"
                         "100\t37\n"
                         "120\t48\n"
                         "140\t60\n"
                         "160\t71\n"
                         "180\t82\n"
                         "200\t93\n"
                         "220\t104\n"
                         "240\t115\n"
                         "260\t126\n"
                         "280\t137\n"
                         "300\t148\n";

  assert_fd_outputs(STDOUT_FILENO, chapter_1_3, expected);
  return 0;
}
