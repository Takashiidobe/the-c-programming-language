#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  assert_fd_outputs(STDOUT_FILENO, chapter_1_1, "Hello world\n");
  return 0;
}
