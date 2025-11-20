#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *input =
      "int a; /* comment */ int b;\n"
      "/* whole line */\n"
      "return a/b; /* trailing */\n";
  const char *expected =
      "int a;  int b;\n"
      "\n"
      "return a/b; \n";

  assert_stdin_stdout(chapter_1_23, input, expected);
  return 0;
}
