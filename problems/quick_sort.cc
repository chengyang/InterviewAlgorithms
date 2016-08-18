#include <iostream>
#include <vector>
using namespace std;

void quickSort(std::vector<int> &nums, int left, int right) {
    int i = left, j = right;
    std::cout<<left<<"   "<<right<<std::endl;
    int pivot = nums[(left+right)/2];
    while (i <= j) {
        while (i <= j && nums[i] < pivot) i++;
        while (i <= j && nums[j] >= pivot) j--;
        if (i <= j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    cout<<i<<endl;
    // if(left<i-1){
    //   quickSort(nums, left, i-1);
    // }
    if(i<right){
      quickSort(nums, i, right);
    }
}

int main() {
  int a[] = {6,5,4,3,2,1,0};
  std::vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
  quickSort(v, 0, v.size()-1);

  for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it){
      std::cout << ' ' << *it;
    }
  std::cout << std::endl;
  return 0;
}