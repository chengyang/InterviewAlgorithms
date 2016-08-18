#include <iostream>
using namespace std;
int main() {
  int n = 5;
  cout << ((n & (n - 1)) == 0) << endl;
  return 0;
}