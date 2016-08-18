#include <iostream>
#include <bitset>
#include "../common/util.h"
using namespace std;
int MergeBits(int a, int b, int i, int j) {
  int low = (1 << i) - 1;
  low = low & a;
  a = a >> (j + 1);
  a = a << (j + 1);
  a = a | low;
  a = a | (b << i);
  return a;
}

int main() {
  int a = 1 << 10;
  int b = 21;
  cout << bitset<32>(MergeBits(a, b, 2, 6)) << endl;
  return 0;
}