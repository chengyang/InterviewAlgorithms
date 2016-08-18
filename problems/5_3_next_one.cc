#include <iostream>
#include <bitset>
#include <math.h>
#include "../common/util.h"
using namespace std;
int CountOne(int value) {
  int count = 0;
  for (int i = 0; i < 32; ++i) {
    if ((value & 1) != 0) {
      count++;
    }
    value >>= 1;
  }
  return count;
}

int Next(int value) {
  int count = CountOne(value);
  if (count == 0 || value == -1) return -1;
  while (value < MAX_INT) {
    if (CountOne(++value) == count) return value;
  }
  return -1;
}

int Previous(int value) {
  int count = CountOne(value);
  if (count == 0 || value == -1) return -1;
  while (value > MIN_INT) {
    if (CountOne(--value) == count) return value;
  }
  return -1;
}

int main() {
  int a = 234234;
  cout << bitset<32>(a) << endl;
  cout << bitset<32>(Next(a)) << endl;
  return 0;
}