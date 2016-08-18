#include <iostream>
#include "../common/util.h"
using namespace std;

// If A > B
// int RandB() {
//  int x = MAX_INT;
//  while (x > b) {
//    x = RandA();
//  }
//  return x;
//}

// RandA^3 = A * (RandA - 1) + RandA

// A > B
// int RandB(){
//    int x = MAX_INT;
//    while(x > B*(A/B)) // B*(A/B)表示最接近A且小于A的b的倍数
//        x = RandA();
//    return x%B + 1;
//}

int Rand7() {
  int x = MAX_INT;
  while (x > 21) {
    x = 5 * (Rand5() - 1) + Rand5();  // Rand25()
  }
  return x % 7 + 1;
}
