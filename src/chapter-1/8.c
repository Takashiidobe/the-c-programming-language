#include <stdio.h>

int chapter_1_8(void) {
  char c;
  size_t blanks = 0, tabs = 0, newlines = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      newlines++;
    }
    if (c == '\t') {
      tabs++;
    }
    if (c == ' ') {
      blanks++;
    }
  }
  printf(
      "the count of blanks is: [%zu], tabs is: [%zu] and newlines is: [%zu]\n",
      blanks, tabs, newlines);
  return 0;
}
