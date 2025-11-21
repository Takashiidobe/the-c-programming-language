#include "chapter-4.h"
#include <ctype.h>

static double pow10_int(int exponent) {
  double result = 1.0;
  double factor = exponent < 0 ? 0.1 : 10.0;
  int e = exponent < 0 ? -exponent : exponent;

  while (e-- > 0) {
    result *= factor;
  }
  return result;
}

double atof_sci(const char *s) {
  int i = 0;
  while (isspace((unsigned char)s[i])) {
    i++;
  }

  int sign = 1;
  if (s[i] == '+' || s[i] == '-') {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }

  double val = 0.0;
  while (isdigit((unsigned char)s[i])) {
    val = 10.0 * val + (double)(s[i] - '0');
    i++;
  }

  double power = 1.0;
  if (s[i] == '.') {
    i++;
    while (isdigit((unsigned char)s[i])) {
      val = 10.0 * val + (double)(s[i] - '0');
      power *= 10.0;
      i++;
    }
  }

  double result = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    int exp_sign = 1;
    if (s[i] == '+' || s[i] == '-') {
      exp_sign = (s[i] == '-') ? -1 : 1;
      i++;
    }

    int exponent = 0;
    while (isdigit((unsigned char)s[i])) {
      exponent = exponent * 10 + (s[i] - '0');
      i++;
    }
    exponent *= exp_sign;

    result *= pow10_int(exponent);
  }

  return result;
}
