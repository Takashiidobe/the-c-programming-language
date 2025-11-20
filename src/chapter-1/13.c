#include <stdio.h>

int chapter_1_13(void) {
  char c;
  static int word_lengths[1024];
  int curr_length = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      word_lengths[curr_length]++;
      curr_length = 0;
    } else {
      curr_length++;
    }
  }

  for (int i = 0; i < 1024; i++) {
    if (word_lengths[i]) {
      printf("%d: ", i);
      printf("%d\n", word_lengths[i]);
    }
  }
  return 0;
}
