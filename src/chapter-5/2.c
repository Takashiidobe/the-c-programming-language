#include <ctype.h>
#include <stdio.h>

#include "chapter-5.h"

int getfloat(double *pn) {
  int c, sign = 1, sign_char = 0;
  double val = 0.0;
  double power = 1.0;
  int saw_digit = 0;

  if (pn == NULL)
    return 0;

  while (isspace(c = getch()))
    ;

  if (c == EOF)
    return EOF;

  if (!isdigit(c) && c != '+' && c != '-' && c != '.') {
    ungetch(c);
    return 0;
  }

  if (c == '+' || c == '-') {
    sign_char = c;
    sign = (c == '-') ? -1 : 1;
    c = getch();
    if (!isdigit(c) && c != '.') {
      int push_chars[] = {sign_char, (c != EOF) ? c : 0};
      push_back_chars(push_chars, 2);
      return 0;
    }
  }

  while (isdigit(c)) {
    saw_digit = 1;
    val = 10.0 * val + (c - '0');
    c = getch();
  }

  if (c == '.') {
    int next = getch();
    if (!isdigit(next)) {
      if (!saw_digit) {
        int push_chars[] = {sign_char, '.', (next != EOF) ? next : 0};
        push_back_chars(push_chars, 3);
        return 0;
      }
      c = next;
    } else {
      do {
        saw_digit = 1;
        val = 10.0 * val + (next - '0');
        power *= 10.0;
        next = getch();
      } while (isdigit(next));
      c = next;
    }
  }

  if (!saw_digit) {
    int push_chars[] = {sign_char, (c != EOF) ? c : 0};
    push_back_chars(push_chars, 2);
    return 0;
  }

  *pn = sign * (val / power);
  if (c != EOF)
    ungetch(c);
  return c;
}
