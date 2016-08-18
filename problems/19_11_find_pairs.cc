#include <algorithm>
#include <iostream>
using namespace std;
void FindPairs(int a[], int n, int sum) {
  if (a == NULL || n < 2) return;
  sort(a, a + n);
  int low = 0;
  int high = n - 1;
  while (low < high) {
    if (a[low] + a[high] > sum) {
      high--;
    } else if (a[low] + a[high] == sum) {
      cout << "[" << a[low] << ", " << a[high] << "]\n";
      low++;
      high--;
    } else {
      low++;
    }
  }
}

int main() {
  int a[] = {2, -8, 3, -2, 8, -10};
  FindPairs(a, 6, 0);
  return 0;
}