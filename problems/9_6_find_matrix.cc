#include <vector>
#define N 5
using namespace std;

typedef vector<vector<int> > Matrix;

int FindMatrix(const Matrix& matrix, int target, int n, int m) {
  int row = 0, col = m - 1;
  while (row < n && col >= 0) {
    if (matrix[row][col] == target) {
      return row * m + col;
    } else if (matrix[row][col] < target) {
      row++;
    } else {
      col--;
    }
  }
  return -1;
}

void PrintMatrix(const Matrix& matrix) {
  size_t n = matrix.size();
  size_t m = (matrix[0]).size();
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  Matrix matrix;
  int aa[] = {1, 2, 3, 4, 5};
  vector<int> a(aa, aa + N);
  matrix.push_back(a);
  int ba[] = {2, 7, 8, 13, 16};
  vector<int> b(ba, ba + N);
  matrix.push_back(b);
  int ca[] = {3, 9, 11, 14, 20};
  vector<int> c(ca, ca + N);
  matrix.push_back(c);
  int da[] = {6, 12, 13, 19, 25};
  vector<int> d(da, da + N);
  matrix.push_back(d);

  PrintMatrix(matrix);

  int n = static_cast<int>(matrix.size());
  int m = static_cast<int>((matrix[0]).size());
  int result = FindMatrix(matrix, 19, n, m);
  printf("Target is at [%d, %d]\n", (result / m) + 1, (result % m) + 1);

  return 0;
}