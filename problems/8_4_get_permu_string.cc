// f(n) = f(n-1)*n
#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef vector<string> vs_t;

vs_t GetPermuStrings(const string& str){
    vs_t permu_strs;
    int length = static_cast<int>(str.length());
    if(length<=1) {
        permu_strs.push_back(str);
    }else{
        string c = string(1, str[length-1]);
        string temp(str.begin(), str.end()-1);
        permu_strs = GetPermuStrings(temp);
        int n = static_cast<int>(permu_strs.size());
        for(int i = 0; i< n; ++i){
            string permu_str = permu_strs[i];
            int m = static_cast<int>(permu_str.size());
            for (int j=0; j<=m; j++) {
                string temp = permu_str;
                temp.insert(j, c);
                permu_strs.push_back(temp);
            }
        }
        permu_strs.erase(permu_strs.begin(), permu_strs.begin()+n);
    }
    return permu_strs;
}

int main() {
    string str = "apl";
    vs_t result = GetPermuStrings(str);
    for (vs_t::iterator it = result.begin(); it!=result.end(); ++it) {
        printf("%s\n", (*it).c_str());
    }
    return 0;
}