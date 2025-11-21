// Exercise 7-1. Write a program that converts upper case to lower or lower case
// to upper, depending on the name it is invoked with, as found in argv[0].

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int chapter_7_1(int argc, char *argv[]) {
  // get the stem
  const char *prog = argv[0];
  if (prog == NULL) {
    prog = "";
  }
  const char *slash = strrchr(prog, '/');
  if (slash) {
    prog = slash + 1;
  }

  int to_upper = strcasecmp(prog, "upper") == 0;
  int to_lower = strcasecmp(prog, "lower") == 0;

  int c;
  while ((c = getchar()) != EOF) {
    if (to_upper) {
      putchar(toupper(c));
    } else if (to_lower) {
      putchar(tolower(c));
    } else {
      putchar(c);
    }
  }
  return 0;
}
