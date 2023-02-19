#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long bitcount(unsigned long long value) {
    unsigned long long count = 0;
    while (value > 0) {           // until all bits are zero
        if ((value & 1) == 1)     // check lower bit
            count++;
        value >>= 1;              // shift bits, removing lower bit
    }
    return count;
}

int main() {
  char buf[1024];
  char c;
  size_t i = 0;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      buf[i] = c;
      i++;
    } else {
      int num = atoi(buf);
      size_t popcount = bitcount(num);
      printf("The bitcount of %s is: %zu\n", buf, popcount);
      memset(buf, 0, 1024);
      i = 0;
    }
  }
}
