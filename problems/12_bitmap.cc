#include <iostream>

using namespace std;

int main() {
  int int_size = sizeof(int) * 8;
  int bits_size = 32000 / int_size;
  int* bits = new int[bits_size];
  memset(bits, 0, bits_size);

  int a[] = {1, 2, 3, 4, 5, 32000, 4, 7, 8, 10, 12, 44, 32000};
  int count = sizeof(a) / sizeof(int);
  for (int i = 0; i < count; ++i) {
    int temp = a[i] - 1;
    int bit = temp % int_size;
    int value = 1 << bit;
    temp = temp / int_size;
    if ((bits[temp] & value) != 0) {
      cout << a[i] << " ";
    } else {
      bits[temp] = bits[temp] | value;
    }
  }
  delete bits;
  return 0;
}