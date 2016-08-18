#include <iostream>
#define N 5;
struct Sqaure {
  int x;
  int y;
  int length;
};
Sqaure FindSquare(bool a[][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int n = min(N - i, N - j); n > 0; --n) {
        if (a[i][j]) }
    }
  }
}
int main() {
  bool a[N][N] = {{1, 0, 0, 1, 0},
                  {1, 0, 0, 1, 0},
                  {1, 0, 0, 1, 0},
                  {1, 0, 0, 1, 0},
                  {1, 0, 0, 1, 0}};

  return 0;
}