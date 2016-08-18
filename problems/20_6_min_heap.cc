// Find nth biggest numbers in an array.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

#define N 10

void MinHeap(int a[], int size) {
  min_heap heap;
  for (int i = 0; i < N; ++i) {
    heap.push(a[i]);
  }
  for (int i = N; i < size; ++i) {
    if (a[i] > heap.top()) {
      heap.pop();
      heap.push(a[i]);
    }
  }

  while (!heap.empty()) {
    cout << heap.top() << " ";
    heap.pop();
  }
  cout << endl;
}

int main() {
  int a[] = {100, 30, 20, -90, 32, 31,  56,  11,  57, 88, 96, 43,
             2,   5,  6,  33,  29, 156, 535, 678, 42, 7,  -9, -43};
  int size = sizeof(a) / sizeof(int);

  MinHeap(a, size);

  return 0;
}