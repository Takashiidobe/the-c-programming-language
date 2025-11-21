#ifndef CHAPTER_5_TEST_HELPERS_H
#define CHAPTER_5_TEST_HELPERS_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "chapter-4.h"

static const char INPUT_SENTINEL = '\x1d';

static inline void load_input(const char *text) {
  assert(text != NULL);
  size_t len = strlen(text);
  char *buf = malloc(len + 2);
  assert(buf != NULL);
  memcpy(buf, text, len);
  buf[len] = INPUT_SENTINEL;
  buf[len + 1] = '\0';
  ungets(buf);
  free(buf);
}

static inline void drain_input(void) {
  int c;
  do {
    c = getch();
  } while (c != EOF && c != INPUT_SENTINEL);
}

#endif
