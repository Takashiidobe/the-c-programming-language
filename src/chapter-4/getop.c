#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "chapter-4.h"

#define MAXLINE 1000

static char line_buf[MAXLINE];
static char string_buf[MAXLINE];
static size_t string_len = 0;
static size_t string_pos = 0;
static int has_push_char = 0;
static int push_char = 0;

static int refill_line(void);

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int c;
  int i = 0;
  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == EOF)
    return EOF;
  s[0] = c;
  s[1] = '\0';
  if (c == '\n')
    return c;
  if (isalpha(c)) {
    while (i < MAXOP - 1 && isalpha(c)) {
      s[i++] = c;
      c = getch();
    }
    s[i] = '\0';
    if (c != EOF)
      ungetch(c);
    if (i == 1) {
      if (isupper((unsigned char)s[0]))
        return VARIABLE;
      return s[0];
    }
    return NAME;
  }
  if (!isdigit(c) && c != '.' && c != '-')
    return c;
  if (c == '-') {
    int next = getch();
    if (!isdigit(next) && next != '.') {
      ungetch(next);
      return '-';
    }
    s[i++] = '-';
    c = next;
  }
  if (isdigit(c)) {
    do {
      s[i++] = c;
      c = getch();
    } while (isdigit(c) && i < MAXOP - 1);
  }
  if (c == '.' && i < MAXOP - 1) {
    s[i++] = c;
    while ((c = getch()) != EOF && isdigit(c) && i < MAXOP - 1)
      s[i++] = c;
  }
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

void ungets(const char *s) {
  if (!s)
    return;
  size_t len = strlen(s);
  size_t remaining = string_len > string_pos ? string_len - string_pos : 0;
  if (len + remaining >= MAXLINE) {
    len = (MAXLINE - 1 > remaining) ? (MAXLINE - 1 - remaining) : 0;
  }
  if (remaining > 0)
    memmove(string_buf + len, string_buf + string_pos, remaining);
  if (len > 0)
    memcpy(string_buf, s, len);
  string_len = len + remaining;
  string_pos = 0;
}

int getch(void) {
  if (has_push_char) {
    has_push_char = 0;
    return push_char;
  }
  if (string_pos < string_len) {
    int c = (unsigned char)string_buf[string_pos++];
    if (string_pos >= string_len) {
      string_pos = 0;
      string_len = 0;
    }
    return c;
  }
  if (refill_line() == EOF)
    return EOF;
  return getch();
}

void ungetch(int c) {
  if (has_push_char) {
    printf("error: too many characters to ungetch\n");
    return;
  }
  has_push_char = 1;
  push_char = c;
}

static int refill_line(void) {
  if (!fgets(line_buf, sizeof(line_buf), stdin))
    return EOF;
  ungets(line_buf);
  return 0;
}
