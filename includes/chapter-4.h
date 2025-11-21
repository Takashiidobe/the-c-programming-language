#ifndef CHAPTER_4_H
#define CHAPTER_4_H

int strrindex(char *s, char *t);
double atof_sci(const char *s);
int chapter_4_1(void);
void recursive_itoa(int n, char *dest);
void recursive_reverse(char *s);

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n'   /* signal that a function name was found */
#define VARIABLE 'V'

#define swap(t, x, y)                                                         \
  do {                                                                        \
    t _swap_tmp = (x);                                                        \
    (x) = (y);                                                                \
    (y) = _swap_tmp;                                                          \
  } while (0)

int calc(void);
int getop(char s[]);

void push(double f);
double pop(void);
double peek(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);

void ungets(const char *s);
int getch(void);
void ungetch(int c);

#endif
