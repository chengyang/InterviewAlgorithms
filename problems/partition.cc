#include <iostream>
#include <vector>
using namespace std;

int partitionArray(std::vector<int> &nums, int k) {
                  int i = 0, j = nums.size() - 1;
    while (i <= j) {
        while (i <= j && nums[i] < k) i++;
        while (i <= j && nums[j] >= k) j--;
        if (i <= j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    for (std::vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it){
      std::cout << ' ' << *it;
    }
  std::cout << std::endl;
    return i;
}

int main() {
  int a[] = {100, 30, 20, -90, 32, 31,  56,  11,  57, 88, 96, 43,
             2,   5,  6,  33,  29, 156, 535, 678, 42, 7,  -9, -43};
  std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
  std::cout << partitionArray(v, 100) << std::endl;
  return 0;
}