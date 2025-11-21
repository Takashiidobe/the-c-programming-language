#include <ctype.h>
#include <stdio.h>

#include "chapter-5.h"

int getint(int *pn) {
  int c, sign = 1, sign_char = 0;

  if (pn == NULL)
    return 0;

  while (isspace(c = getch()))
    ;

  if (c == EOF)
    return EOF;

  if (!isdigit(c) && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  if (c == '+' || c == '-') {
    sign_char = c;
    sign = (c == '-') ? -1 : 1;
    c = getch();
    if (!isdigit(c)) {
      int push_chars[] = {sign_char, (c != EOF) ? c : 0};
      push_back_chars(push_chars, 2);
      return 0;
    }
  }

  int val = 0;
  while (isdigit(c)) {
    val = 10 * val + (c - '0');
    c = getch();
  }

  *pn = sign * val;
  if (c != EOF)
    ungetch(c);
  return c;
}
