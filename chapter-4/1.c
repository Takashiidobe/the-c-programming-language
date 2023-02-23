/*
 * Write the function strrindex(s,t) , which returns the position of the rightmost occurrence of t in s , or -1 if there is none.
*/

#include <stdio.h>
#include <string.h>

int strrindex(char* s, char* t) {
  // the rightmost occurrence of t in s
  int curr_index = -1;
  size_t s_len = strlen(s);
  size_t t_len = strlen(t);
  for (int i = 0; i < s_len; i++) {
    if (s[i] == t[0]) {
      int k = 0;
      for (int j = i; k < t_len && j < s_len; j++) {

      }
      return 1;
    }
  }
  return curr_index;
}

int main() {

}
