#include <bitset>
#include <iostream>
#include "util.h"

using namespace std;

int main() {
  int a = -3;
  cout << bitset<sizeof(int) * 8>(a) << endl;

  cout << GetBit(a, 4) << endl;

  cout << bitset<sizeof(int) * 8>(FlipBit(a, 5)) << endl;

  char b = '!';
  cout << bitset<sizeof(char) * 8>(b) << endl;

  bool c = true;
  cout << bitset<sizeof(bool) * 8>(c) << endl;

  float d = 13.5f;
  cout << bitset<sizeof(float) * 8>(d) << endl;

  float e = 13.5;
  cout << bitset<sizeof(double) * 8>(e) << endl;
  return 0;
}