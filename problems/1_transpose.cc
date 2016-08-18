#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > Matrix;

void Swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void Transpose(Matrix& matrix) {
  size_t n = matrix.size();
  size_t m = matrix[0].size();

  if (n != m) {
    printf("Not a valid matrix!\n");
    return;
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      Swap(matrix[i][j], matrix[j][i]);
    }
  }
  for (size_t i = 0; i < n / 2; i++) {
    for (size_t j = 0; j < n; j++) {
      Swap(matrix[i][j], matrix[n - 1 - i][j]);
    }
  }
}

void PrintMatrix(Matrix& matrix) {
  size_t n = matrix.size();
  size_t m = matrix[0].size();
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);

  std::vector<int> b(4, 100);

  std::vector<int> c(a.begin(), a.end());

  int d_array[] = {16, 2, 77, 29};
  std::vector<int> d(d_array, d_array + sizeof(d_array) / sizeof(int));

  Matrix m;
  m.push_back(a);
  m.push_back(b);
  m.push_back(c);
  m.push_back(d);

  PrintMatrix(m);
  Transpose(m);
  PrintMatrix(m);

  return 0;
}