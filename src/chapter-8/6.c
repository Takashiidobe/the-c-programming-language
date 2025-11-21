#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void *_calloc(size_t n, size_t size) {
  if (n != 0 && SIZE_MAX / n < size) {
    return NULL;
  }
  size_t total = n * size;
  void *buffer = malloc(total);
  if (!buffer) {
    return NULL;
  }
  memset(buffer, 0, total);
  return buffer;
}
