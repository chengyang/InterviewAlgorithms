#include <iostream>

int MaxSum(int a[], int n) {
  if (n <= 0 || a == NULL) return 0;
  if (n == 1) return a[0];
  int sum = 0;
  int maxsum = 1 << (sizeof(int) * 8 - 1);
  for (int i = 0; i < n; ++i) {
    if (sum + a[i] <= 0) {
      sum = 0;
    } else {
      sum += a[i];
    }
    if (sum > maxsum) maxsum = sum;
  }
  return maxsum;
}

int main() {
  int a[] = {2, -8, 3, -2, 4, -10};

  std::cout << MaxSum(a, 6) << std::endl;
  return 0;
}