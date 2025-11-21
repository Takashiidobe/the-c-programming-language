#include "chapter-3.h"

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (low < n && v[low] == x)
    return low;

  return -1;
}
