#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

struct Comparator{
    bool operator()(P const&a, P const& b) const {
        return a.first > b.first || (a.first==b.first&&a.second>b.second);
    }
};

int main(){
    priority_queue<P, vector<P>, Comparator> max_heap;
    max_heap.push(make_pair(4,6));
    max_heap.push(make_pair(7,9));
    max_heap.push(make_pair(2,10));
    max_heap.push(make_pair(1,100));
    max_heap.push(make_pair(1,30));
    while(!max_heap.empty()){
        cout<<max_heap.top().first<<"--"<<max_heap.top().second<<endl;
        max_heap.pop();
    }
    return 0;
}