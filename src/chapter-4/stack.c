#include <stdio.h>

#define MAXVAL 100         /* maximum depth of val stack */
static int sp = 0;         /* next free stack position */
static double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

double peek(void) {
  if (sp > 0)
    return val[sp - 1];
  printf("error: stack empty\n");
  return 0.0;
}

void duplicate_top(void) {
  if (sp > 0)
    push(peek());
  else
    printf("error: nothing to duplicate\n");
}

void swap_top_two(void) {
  if (sp < 2) {
    printf("error: not enough elements to swap\n");
    return;
  }
  double tmp = val[sp - 1];
  val[sp - 1] = val[sp - 2];
  val[sp - 2] = tmp;
}

void clear_stack(void) { sp = 0; }
