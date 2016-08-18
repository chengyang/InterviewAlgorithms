#include <iostream>
using namespace std;

void MergeArray(int a[], int b[], int m, int n) {
  int k = n + m - 1;
  int i = m - 1, j = n - 1;
  while (i >= 0 && j >= 0) {
    if (a[i] > b[j]) {
      a[k] = a[i--];
    } else {
      a[k] = b[j--];
    }
    k--;
  }
  while (j >= 0) {
    a[k--] = b[j--];
  }
}

int main() {
  int a[15] = {1, 2, 3, 4, 5};
  int b[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
  MergeArray(a, b, 5, 10);
  for (int i = 0; i < 14; i++) {
    cout << a[i] << ",";
  }
  cout << a[14] << endl;
}