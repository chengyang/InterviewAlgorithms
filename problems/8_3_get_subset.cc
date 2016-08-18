#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<set<int> > sets_t;
typedef set<int> set_t;

sets_t GetSubsets(int myset[], int n){
    sets_t subsets;
    int count = 1<<n;
    for (int i=0; i<count; ++i) {
        set_t subset;
        int index = 0;
        int j = i;
        while (j>0) {
            if(j&1){
                subset.insert(myset[index]);
            }
            j>>=1;
            ++index;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main () {
    int arr[] = {78, 4, 1, 3};
    //set_t myset (arr, arr + sizeof(arr)/sizeof(int));
    sets_t subsets = GetSubsets(arr, sizeof(arr)/sizeof(int));
    for(sets_t::iterator it = subsets.begin(); it != subsets.end(); ++it){
        printf("{");
        for(set_t::iterator it_ = it->begin(); it_ != it->end(); ++it_ ){
            printf("%d ", *it_);
        }
        printf("}\n");
    }
    return 0;
}