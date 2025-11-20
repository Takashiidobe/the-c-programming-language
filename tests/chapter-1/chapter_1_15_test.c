#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *expected =
      "  0 F =  -17.8 C\n"
      " 20 F =   -6.7 C\n"
      " 40 F =    4.4 C\n"
      " 60 F =   15.6 C\n"
      " 80 F =   26.7 C\n"
      "100 F =   37.8 C\n"
      "120 F =   48.9 C\n"
      "140 F =   60.0 C\n"
      "160 F =   71.1 C\n"
      "180 F =   82.2 C\n"
      "200 F =   93.3 C\n"
      "220 F =  104.4 C\n"
      "240 F =  115.6 C\n"
      "260 F =  126.7 C\n"
      "280 F =  137.8 C\n"
      "300 F =  148.9 C\n";

  assert_fd_outputs(STDOUT_FILENO, chapter_1_15, expected);
  return 0;
}
