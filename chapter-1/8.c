#include <stdio.h>
#include <ctype.h>

int main() {
  // count blanks, tabs and newlines
  char c;
  size_t count = 0;
  while ((c = getchar())) {
    if (c == EOF) {
      goto done;
    }
    if (isspace(c)) {
      count++;
    }
  }
  done:
    printf("the count of blanks, tabs and newlines is: %zu\n", count);
}
