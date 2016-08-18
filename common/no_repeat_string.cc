#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, char> P;

struct Comparator{
    bool operator()(P const&a, P const& b) const {
        return a.first < b.first;
    }
};

string noRepeatString(const string& str){
    int N = str.length();
    string result;
    priority_queue<P> heap;
    int count[256] = {0};
    //build the character frequency histogram
    for(int i = 0; i < N; ++i){
        count[str[i]]++;
        //if a character repeats more than n/2 then we can't rearrange
        if(count[str[i]] > (N+1)/2){
            return str;
        }
    }
    //build the max heap of histogram
    for(int i = 0; i < 256; i++){
        if(count[i] > 0)
            heap.push(make_pair(count[i], (char)i));
    }
    
    //rearrange - pop top 2 most frequent items and arrange them in adjacent positions
    //decrease the histogram frequency of the selected chars
    while(!heap.empty()){
        //extract top one and decrease the hstogram by one
        P temp1 = heap.top();
        heap.pop();
        result+=temp1.second;
        temp1.first--;
        
        P temp2;
        //extract second top and decrease the histogram by one
        if(!heap.empty()){
            temp2 = heap.top();
            heap.pop();
            result+=temp2.second;
            temp2.first--;
        }
        
        //add back the updated histograms
        if(temp1.first > 0){
            heap.push(temp1);
        }
        if(temp2.first > 0){
            heap.push(temp2);
        }
    }
    return result;
}

int main(){
    //priority_queue<P, vector<P>, Comparator> max_heap;
    cout<<noRepeatString("aaabbcc")<<endl;
    return 0;
}