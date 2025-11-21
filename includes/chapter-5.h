#ifndef CHAPTER_5_H
#define CHAPTER_5_H

int getint(int *pn);
int getfloat(double *pn);
char *_strcat(char *s, const char *t);

#include <stddef.h>
#include <stdio.h>

#include "chapter-4.h"

static inline void push_back_chars(const int *chars, size_t count) {
  if (!chars || count == 0)
    return;

  char buf[8];
  size_t idx = 0;
  for (size_t i = 0; i < count && idx < sizeof(buf) - 1; ++i) {
    if (chars[i] == 0 || chars[i] == EOF)
      continue;
    buf[idx++] = (char)chars[i];
  }
  if (idx == 0)
    return;
  buf[idx] = '\0';
  ungets(buf);
}

#endif
