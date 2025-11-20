#include <stdio.h>
#include <stdlib.h>

// blanks, tabs, newlines
void count_spaces(const char *s, size_t buf[3]) {
  while (*s) {
    if (*s == ' ') {
      buf[0]++;
    } else if (*s == '\t') {
      buf[1]++;
    } else if (*s == '\n') {
      buf[2]++;
    }

    s++;
  }
}

const char *get_stdin_with_cap(size_t cap) {
  char *s = malloc(cap);
  if (!s) {
    perror("malloc");
    exit(1);
  }

  int i = 0;
  char c;
  while ((c = getchar()) != EOF) {
    if (i + 1 >= cap) {
      break;
    }
    s[i++] = c;
  }
  s[i] = '\0';
  return s;
}

int chapter_1_8(void) {
  size_t buf[3] = {};
  const char *s = get_stdin_with_cap(1024);
  count_spaces(s, buf);
  printf(
      "the count of blanks is: [%zu], tabs is: [%zu] and newlines is: [%zu]\n",
      buf[0], buf[1], buf[2]);
  return 0;
}
