#include <iostream>
using namespace std;
int target;

void Search(int a[], int value, int low, int high) {
  int mid = (high + low) / 2;
  if (a[mid] == value) {
    target = mid;
  } else if (value < a[mid]) {
    Search(a, value, low, mid - 1);
  } else {
    Search(a, value, mid + 1, high);
  }
}

int Search2(int a[], int value, int low, int high) {
  while (low <= high) {
    int mid = (high + low) / 2;
    if (a[mid] == value) {
      return mid;
    } else if (value < a[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int SearchRotate(int a[], int size, int value) {
  int middle = -1;
  for (int i = 0; i < size - 2; i++) {
    if (a[i] > a[i + 1]) {
      middle = i;
    }
  }
  if (middle != -1) {
    if (value == a[0]) {
      return 0;
    } else if (value > a[0]) {
      return Search2(a, value, 0, middle);
    } else {
      return Search2(a, value, middle, size - 1);
    }
  }
  return -1;
}

int main() {
  target = -1;
  int a[] = {6, 7, 8, 9, 10, 11, 12, 14, 14, 1, 2, 2, 4, 5};
  int size = sizeof(a) / sizeof(int);

  cout << SearchRotate(a, size, 2) << endl;
  return 0;
}