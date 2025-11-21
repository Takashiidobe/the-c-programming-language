#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chapter-4.h"

static double vars[26];

static void to_lower_str(char *s) {
  while (*s) {
    *s = (char)tolower((unsigned char)*s);
    ++s;
  }
}

static void apply_function(const char *name) {
  double op1, op2;
  if (strcmp(name, "sin") == 0) {
    push(sin(pop()));
  } else if (strcmp(name, "exp") == 0) {
    push(exp(pop()));
  } else if (strcmp(name, "pow") == 0) {
    op2 = pop();
    op1 = pop();
    push(pow(op1, op2));
  } else {
    printf("error: unknown function %s\n", name);
  }
}

/* reverse Polish calculator */
int calc() {
  int type;
  double op1, op2;
  char s[MAXOP];
  double last_print = 0.0;
  int last_variable = -1;
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
      // 4.3: add %
    case '%':
      op2 = pop();
      if (op2 != 0.0) {
        op1 = pop();
        push(fmod(op1, op2));
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '?': {
      double top = peek();
      printf("\t%.8g\n", top);
      last_print = top;
    } break;
    case 'd':
      duplicate_top();
      break;
    case 's':
      swap_top_two();
      break;
    case 'c':
      clear_stack();
      break;
    case 'v':
      push(last_print);
      break;
    case NAME:
      to_lower_str(s);
      apply_function(s);
      break;
    case VARIABLE:
      last_variable = s[0] - 'A';
      if (last_variable >= 0 && last_variable < 26)
        push(vars[last_variable]);
      else
        printf("error: invalid variable %c\n", s[0]);
      break;
    case '=':
      if (last_variable < 0 || last_variable >= 26) {
        printf("error: no variable name for assignment\n");
        break;
      }
      op1 = pop(); /* value to store */
      pop();       /* discard previous variable value */
      vars[last_variable] = op1;
      push(op1);
      last_variable = -1;
      break;
    case '\n':
      op1 = pop();
      printf("\t%.8g\n", op1);
      last_print = op1;
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
