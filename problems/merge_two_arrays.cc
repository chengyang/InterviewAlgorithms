#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> C;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) {
                C.push_back(A[i++]);
            } else {
                C.push_back(B[j++]);
            }
        }
        while (i < A.size()) {
            C.push_back(A[i++]);
        }
        while (j < B.size()) {
            C.push_back(B[j++]);
        }
        A = C;
}

int main() {
  int a[] = {100, 30, 20, -90, 32};
  int b[] = {57, 88, 96};
  std::vector<int> A(a, a + sizeof(a) / sizeof(a[0]));
  std::vector<int> B(b, b + sizeof(b) / sizeof(b[0]));
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  mergeSortedArray(A, B);
  for (std::vector<int>::iterator it = A.begin() ; it != A.end(); ++it){
      std::cout << ' ' << *it;
    }
  std::cout << std::endl;
  return 0;
}