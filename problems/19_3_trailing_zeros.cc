#include <iostream>
#define N 100

int CalculateZeros(int n) {
  if (n <= 0) return -1;
  long factor = 5;
  int result = 0;
  while (factor <= n) {
    result += n / factor;
    factor *= 5;
  }
  return result;
}

int CalculateZeros2(int n) {
  if (n <= 0) return -1;
  int result = 0;
  while (n > 0) {
    n = n / 5;
    result += n;
  }
  return result;
}

int main() {
  std::cout << CalculateZeros(N) << "   " << CalculateZeros2(N) << std::endl;
  return 0;
}