#include <stdlib.h>
#include <string.h>

#include "chapter-5.h"

char *_strcat(char *s, const char *t) {
  size_t s_len = strlen(s);
  size_t t_len = strlen(t);
  for (int i = s_len; i < s_len + t_len; i++) {
    s[i] = t[i - s_len];
  }
  s[s_len + t_len] = '\0';

  return s;
}
