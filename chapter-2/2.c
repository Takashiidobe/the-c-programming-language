#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* squeeze(char* s1, char* s2, size_t s1_len, size_t s2_len) {
  int map[128] = {};
  char* res = malloc(sizeof(char) * s1_len);

  for (int i = 0; i < s2_len; i++) {
    map[(int)s2[i]]++;
  }

  int j = 0;
  for (int i = 0; i < s1_len; i++) {
    if (!map[s1[i]]) {
      res[j] = s1[i];
      j++;
    }
  }
  res[j] = '\0';

  return res;
}

int main() {
  char buf[1024];
  char* vowels = "aeiou";
  char c;
  size_t i = 0;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      buf[i] = c;
      i++;
    } else {
      char* squeezed = squeeze(buf, vowels, strlen(buf), 5);
      printf("%s with vowels removed: [%s]\n", buf, squeezed);
      memset(buf, 0, 1024);
      free(squeezed);
      i = 0;
    }
  }
}
