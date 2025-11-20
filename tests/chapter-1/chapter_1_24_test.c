#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input =
      "int main() {\n"
      "  int arr[3] = {1, 2, 3};\n"
      "  /* ignore braces { [ ( ) ] } */\n"
      "  if (arr[0]) {\n"
      "    return 0;\n"
      "  }\n"
      "}\n";

  assert_stdin_stdout(chapter_1_24, input, "");
  return 0;
}
