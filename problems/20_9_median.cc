#include <iostream>
#include <queue>
using namespace std;

typedef priority_queue<int, vector<int>, less<int> > max_heap;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

float GetMedian(max_heap& left, min_heap& right) {
  if (left.empty() && right.empty()) return 1 << 31;

  if (left.size() == right.size()) {
    return static_cast<float>(left.top() + right.top()) * 0.5f;
  }
  if (left.size() > right.size()) {
    return left.top();
  }
  if (left.size() < right.size()) {
    return right.top();
  }
  return 1 << 31;
}

void Insert(max_heap& left, min_heap& right, int value) {
  if (left.empty() && right.empty()) {
    left.push(value);
  } else if ((!left.empty()) && right.empty()) {
    right.push(value);
  } else if (left.empty() && (!right.empty())) {
    left.push(value);
  } else {
    if (value > right.top()) {
      right.push(value);
    } else {
      left.push(value);
    }
  }

  while (left.size() > right.size() + 1) {
    int data = left.top();
    right.push(data);
    left.pop();
  }
  while (right.size() > left.size() + 1) {
    int data = right.top();
    left.push(data);
    right.pop();
  }
}
int main() {
  int a[] = {100, 30, 20, -90, 32, 31,  56,  11,  57, 88, 96, 43,
             2,   5,  6,  33,  29, 156, 535, 678, 42, 7,  -9, -43};
  int size = sizeof(a) / sizeof(int);
  max_heap left;
  min_heap right;
  for (int i = 0; i < size; ++i) {
    Insert(left, right, a[i]);
  }
  std::cout << GetMedian(left, right) << std::endl;
  return 0;
}