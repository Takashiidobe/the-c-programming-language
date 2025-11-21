/*
 * Write the function strrindex(s,t) , which returns the position of the
 * rightmost occurrence of t in s , or -1 if there is none.
 */

#include "chapter-4.h"
#include <stdio.h>
#include <string.h>

int strrindex(char *s, char *t) {
  if (!s || !t) {
    return -1;
  }

  size_t s_len = strlen(s);
  size_t t_len = strlen(t);
  if (t_len == 0 || t_len > s_len) {
    return -1;
  }

  for (int i = (s_len - t_len); i >= 0; i--) {
    size_t j = 0;
    while (j < t_len && s[i + j] == t[j]) {
      j++;
    }
    if (j == t_len) {
      return i;
    }
  }
  return -1;
}
