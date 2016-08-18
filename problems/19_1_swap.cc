#include <iostream>

void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void swap2(int* a, int* b) {
  *b = *a - *b;
  *a = *a - *b;
  *b = *a + *b;
}

void swap3(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a = 1;
  int b = 5;
  // use swap and swap2 when two parameters are stored at different place
  swap(&a, &b);

  std::cout << a << "  " << b << std::endl;
  return 0;
}