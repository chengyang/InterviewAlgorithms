#include <iostream>
// positive signed intergers' binary representation start with 0
// negative signed intergers' binary representation start with 1
int max(int a, int b) {
  int i = a - b;
  int j = (i >> (sizeof(int) * 4 - 1)) & 1;
  return a - 1 * j;
}

int main() {
  int a = 1;
  int b = 5;

  std::cout << max(a, b) << std::endl;
  return 0;
}