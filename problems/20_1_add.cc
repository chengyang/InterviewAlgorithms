#include <iostream>
// a 是不考虑进位的和，b是进位表示
long add(long a, long b) {
  //当进位为0，也就是所加的和已经是最后答案，则返回
  if (b == 0) return a;
  long sum = a ^ b;
  long carry = (a & b) << 1;
  return add(sum, carry);
}

long add2(int a, int b) {
  long i = a;
  long j = b;
  while (j != 0) {
    long sum = i ^ j;
    long carry = (i & j) << 1;
    i = sum;
    j = carry;
  }
  return i;
}

int main() {
  int a = ~(1 << 31);
  int b = ~(1 << 31);
  std::cout << add2(a, b) << std::endl;
  return 0;
}