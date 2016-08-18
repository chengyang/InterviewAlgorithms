#include <iostream>
#include <string>
// 2 is other, 1 is me
using namespace std;

enum Check { ROW, COLUMN, DIAGONAL, REDIAGONAL, LOSE };

Check HasWon(int a[], int n) {
  int i = 0, j = 0;

  while (i < n && j < n) {
    if (a[i * n + j] != 1) {
      i++;
      j = 0;
    } else {
      j++;
      if (j == n) return ROW;
    }
  }

  i = 0;
  j = 0;
  while (i < n && j < n) {
    if (a[i * n + j] != 1) {
      j++;
      i = 0;
    } else {
      i++;
      if (i == n) return COLUMN;
    }
  }

  for (i = 0; i < n; ++i) {
    if (a[i * n + i] != 1) break;
  }
  if (i == n) return DIAGONAL;

  for (i = 0; i < n; ++i) {
    if (a[i * n + (n - i - 1)] != 1) break;
  }
  if (i == n) return REDIAGONAL;
  return LOSE;
}

int main() {
  int a[] = {0, 2, 1, 0, 1, 1, 0, 0, 1};
  string type[] = {"ROW", "COLUMN", "DIAGONAL", "REDIAGONAL", "LOSE"};
  cout << type[HasWon(a, 3)] << endl;

  return 0;
}