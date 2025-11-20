#include "chapter-2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int any(char *s1, char *s2, size_t s1_len, size_t s2_len) {
  int map[256] = {0};

  for (int i = 0; i < s2_len; i++) {
    map[(unsigned char)s2[i]]++;
  }

  for (int i = 0; i < s1_len; i++) {
    if (map[(unsigned char)s1[i]]) {
      return i;
    }
  }

  return -1;
}

int chapter_2_5(void) {
  char buf[1024];
  char *vowels = "aeiou";
  size_t i = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      if (i < sizeof(buf) - 1) {
        buf[i++] = (char)c;
      }
    } else {
      buf[i] = '\0';
      printf("%d\n", any(buf, vowels, i, strlen(vowels)));
      memset(buf, 0, sizeof(buf));
      i = 0;
    }
  }
  if (i > 0) {
    buf[i] = '\0';
    printf("%d\n", any(buf, vowels, i, strlen(vowels)));
  }
  return 0;
}
