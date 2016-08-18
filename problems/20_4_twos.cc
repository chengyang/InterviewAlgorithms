#include <iostream>

int CountTwos(int n) {
  int sum = 0;
  int factor = 1;
  int m = n;

  while (m > 0) {
    int rest = m / 10;
    if (m % 10 > 2) {
      sum += (rest + 1) * factor;
    } else if (m % 10 == 2) {
      sum += (n % factor + 1) + rest * factor;
    } else {
      sum += rest * factor;
    }
    m = rest;
    factor *= 10;
  }
  return sum;
}

int Count2s(int n) {
  int count = 0;
  int factor = 1;
  int low = 0, cur = 0, high = 0;

  while (n / factor != 0) {
    low = n - (n / factor) * factor;  //低位数字
    cur = (n / factor) % 10;          //当前位数字
    high = n / (factor * 10);         //高位数字

    switch (cur) {
      case 0:
      case 1:
        count += high * factor;
        break;
      case 2:
        count += high * factor + low + 1;
        break;
      default:
        count += (high + 1) * factor;
        break;
    }

    factor *= 10;
  }

  return count;
}

int main() {
  std::cout << CountTwos(335) << "   " << Count2s(335) << std::endl;
  return 0;
}