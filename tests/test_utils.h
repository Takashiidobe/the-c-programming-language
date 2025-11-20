#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef int (*capture_fn)(void);

/*
 * assert_fd_outputs redirects fd to a temp file, runs fn, and asserts that the
 * function succeeds and emits exactly expected_str. It aborts the test on any
 * mismatch or system error.
 */
static inline void assert_fd_outputs(
    int fd,
    capture_fn fn,
    const char *expected_str) {
  assert(fn != NULL);
  assert(expected_str != NULL);

  size_t expected_len = strlen(expected_str);
  char *buffer = malloc(expected_len + 1);
  assert(buffer != NULL);

  FILE *tmp = tmpfile();
  assert(tmp != NULL);

  int tmp_fd = fileno(tmp);
  assert(tmp_fd != -1);

  int saved_fd = dup(fd);
  assert(saved_fd != -1);

  assert(fflush(NULL) != EOF);
  assert(dup2(tmp_fd, fd) != -1);

  int result = fn();

  assert(fflush(NULL) != EOF);
  assert(dup2(saved_fd, fd) != -1);
  close(saved_fd);

  assert(fseek(tmp, 0, SEEK_SET) != -1);
  size_t bytes_read = fread(buffer, 1, expected_len, tmp);
  assert(ferror(tmp) == 0);
  buffer[bytes_read] = '\0';
  fclose(tmp);

  assert(result == 0);
  assert(bytes_read == expected_len);
  assert(strcmp(buffer, expected_str) == 0);

  free(buffer);
}

#endif
