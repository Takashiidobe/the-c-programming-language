#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int any(char* s1, char* s2, size_t s1_len, size_t s2_len) {
  int map[128] = {0};

  for (int i = 0; i < s2_len; i++) {
    map[(int)s2[i]]++;
  }

  for (int i = 0; i < s1_len; i++) {
    if (map[(int)s1[i]]) {
      return i;
    }
  }

  return -1;
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
      printf("%d\n", any(buf, vowels, i, strlen(vowels)));
      memset(buf, 0, 1024);
      i = 0;
    }
  }
}
