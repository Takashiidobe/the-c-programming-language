#include "chapter-2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *squeeze(char *s1, char *s2, size_t s1_len, size_t s2_len) {
  int map[256] = {};
  char *res = malloc(sizeof(char) * s1_len);

  for (int i = 0; i < s2_len; i++) {
    map[(unsigned char)s2[i]]++;
  }

  int j = 0;
  for (int i = 0; i < s1_len; i++) {
    if (!map[(unsigned char)s1[i]]) {
      res[j] = s1[i];
      j++;
    }
  }
  res[j] = '\0';

  return res;
}

int chapter_2_4(void) {
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
      char *squeezed = squeeze(buf, vowels, strlen(buf), 5);
      printf("%s with vowels removed: [%s]\n", buf, squeezed);
      memset(buf, 0, sizeof(buf));
      free(squeezed);
      i = 0;
    }
  }
  if (i > 0) {
    buf[i] = '\0';
    char *squeezed = squeeze(buf, vowels, strlen(buf), 5);
    printf("%s with vowels removed: [%s]\n", buf, squeezed);
    free(squeezed);
  }
  return 0;
}
