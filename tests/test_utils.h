#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void print_str_diff_visual(const char *expected, const char *actual) {
  size_t i = 0;
  while (expected[i] && actual[i] && expected[i] == actual[i]) {
    i++;
  }

  fprintf(stderr, "  expected: \"%s\"\n", expected);
  fprintf(stderr, "  actual  : \"%s\"\n", actual);

  if (expected[i] == '\0' && actual[i] == '\0') {
    fprintf(stderr, "  (strings are equal)\n");
    return;
  }

  fprintf(stderr, "           ");
  for (size_t j = 0; j < i; ++j) {
    fprintf(stderr, " ");
  }
  fprintf(stderr, "^\n");

  fprintf(stderr, "  first difference at index %zu\n", i);
}

#define ASSERT_STR_EQ(expected, actual)                                        \
  do {                                                                         \
    const char *exp__ = (expected);                                            \
    const char *act__ = (actual);                                              \
    if (strcmp(exp__, act__) != 0) {                                           \
      fprintf(stderr, "ASSERT_STR_EQ failed at %s:%d\n", __FILE__, __LINE__);  \
      print_str_diff_visual(exp__, act__);                                     \
      abort();                                                                 \
    }                                                                          \
  } while (0)

#define ASSERT_INT_EQ(expected, actual)                                        \
  do {                                                                         \
    long long exp__ = (long long)(expected);                                   \
    long long act__ = (long long)(actual);                                     \
    if (exp__ != act__) {                                                      \
      fprintf(stderr,                                                          \
              "ASSERT_INT_EQ failed at %s:%d\n"                                \
              "  expected: %lld\n"                                             \
              "  actual  : %lld\n",                                            \
              __FILE__, __LINE__, exp__, act__);                               \
      abort();                                                                 \
    }                                                                          \
  } while (0)

#define ASSERT_DOUBLE_NEAR(expected, actual, tolerance)                        \
  do {                                                                         \
    double exp__ = (double)(expected);                                         \
    double act__ = (double)(actual);                                           \
    double tol__ = (double)(tolerance);                                        \
    double diff__ = fabs(exp__ - act__);                                       \
    if (diff__ > tol__) {                                                      \
      fprintf(stderr,                                                          \
              "ASSERT_DOUBLE_NEAR failed at %s:%d\n"                           \
              "  expected: %.15g\n"                                            \
              "  actual  : %.15g\n"                                            \
              "  diff    : %.15g > %.15g\n",                                   \
              __FILE__, __LINE__, exp__, act__, diff__, tol__);                \
      abort();                                                                 \
    }                                                                          \
  } while (0)

typedef int (*capture_fn)(void);

/*
 * assert_fd_outputs redirects fd to a temp file, runs fn, and asserts that the
 * function succeeds and emits exactly expected_str. It aborts the test on any
 * mismatch or system error.
 */
static inline void assert_fd_outputs(int fd, capture_fn fn,
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
  ASSERT_STR_EQ(expected_str, buffer);

  free(buffer);
}

// This will abort (assert) if anything fails or if output != expected_output.
void assert_stdin_stdout(int (*func)(void), const char *input,
                         const char *expected_output) {
  // 1. Create temporary files for mock stdin/stdout
  FILE *in = tmpfile();
  FILE *out = tmpfile();
  assert(in != NULL && out != NULL);

  // 2. Write input into the "stdin" file and rewind
  if (input == NULL) {
    input = "";
  }
  fputs(input, in);
  fflush(in);
  rewind(in);

  // 3. Save original stdin/stdout file descriptors
  int old_stdin_fd = dup(STDIN_FILENO);
  int old_stdout_fd = dup(STDOUT_FILENO);
  assert(old_stdin_fd != -1);
  assert(old_stdout_fd != -1);

  // Ensure anything buffered on the real stdout is flushed
  fflush(stdout);

  // 4. Redirect stdin/stdout to our temporary files
  assert(dup2(fileno(in), STDIN_FILENO) != -1);
  assert(dup2(fileno(out), STDOUT_FILENO) != -1);
  clearerr(stdin);
  clearerr(stdout);

  // 5. Call the function under test
  int rc = func();
  (void)rc; // Ignore return value; if you want, assert(rc == 0);

  // Make sure all output is flushed into our temp "stdout"
  fflush(stdout);

  // 6. Restore original stdin/stdout
  assert(dup2(old_stdin_fd, STDIN_FILENO) != -1);
  assert(dup2(old_stdout_fd, STDOUT_FILENO) != -1);
  close(old_stdin_fd);
  close(old_stdout_fd);

  // 7. Read the captured output from the temp stdout file
  rewind(out);

  size_t cap = 128;
  size_t len = 0;
  char *buf = malloc(cap);
  assert(buf != NULL);

  for (;;) {
    if (len + 1 >= cap) {
      cap *= 2;
      buf = realloc(buf, cap);
      assert(buf != NULL);
    }

    size_t n = fread(buf + len, 1, cap - 1 - len, out);
    len += n;

    if (n == 0) {
      break; // EOF or error; for tests we treat both as "done"
    }
  }
  buf[len] = '\0';

  // 8. Assert output matches expectation exactly
  ASSERT_STR_EQ(expected_output, buf);

  free(buf);
  fclose(in);
  fclose(out);
}

#endif
