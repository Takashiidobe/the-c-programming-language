#include "chapter-2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long bitcount(unsigned long long value) {
  unsigned long long count = 0;
  while (value > 0) {     // until all bits are zero
    if ((value & 1) == 1) // check lower bit
      count++;
    value >>= 1; // shift bits, removing lower bit
  }
  return count;
}

int chapter_2_9(void) {
  char buf[1024];
  size_t i = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      if (i < sizeof(buf) - 1) {
        buf[i++] = (char)c;
      }
    } else {
      buf[i] = '\0';
      unsigned long long num = strtoull(buf, NULL, 10);
      size_t popcount = bitcount(num);
      printf("The bitcount of %s is: %zu\n", buf, popcount);
      memset(buf, 0, sizeof(buf));
      i = 0;
    }
  }
  if (i > 0) {
    buf[i] = '\0';
    unsigned long long num = strtoull(buf, NULL, 10);
    size_t popcount = bitcount(num);
    printf("The bitcount of %s is: %zu\n", buf, popcount);
  }
  return 0;
}
