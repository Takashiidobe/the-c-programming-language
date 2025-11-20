#include "../test_utils.h"
#include "chapter-1.h"

int main(void) {
  const char *expected = "alert (0x07) - added in C89: '\a'\n"
                         "backspace (0x08): ' \b'\n"
                         "horizontal tab (0x09): '\t'\n"
                         "newline (0x0A): '\n'\n"
                         "vertical tab (0x0B):'\v'\n"
                         "formfeed (0x0C): '\f'\n"
                         "carriage return (0x0D): '\r'\n"
                         "double quote: (0x22)'\"'\n"
                         "single quote (0x27): '''\n"
                         "question mark (0x3F): '?'\n"
                         "backslash (0x5C): '\\'\n"
                         "octal number (nnn): 'A'\n"
                         "hexdecimal number (xhh): 'A'\n"
                         "escape character (0x1B): '\x1b'\n"
                         "using format string as escape sequence: 65\n";

  assert_stdin_stdout(chapter_1_2, NULL, expected);
  return 0;
}
