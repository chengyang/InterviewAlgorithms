#include<iostream>
#define MAX 5

int solution[MAX];
int solution_count;

void search(int n){
    if(n == MAX){
        for (int i =0; i<MAX-1; ++i) {
            printf("%d, ", solution[i]);
        }
        printf("%d\n",solution[MAX-1]);
        solution_count++;
        return;
    }
    for (int i =0; i<MAX; i++) {
        solution[n] = i;
        bool ok = true;
        for(int j = 0; j<n; j++){
            int diff = std::abs(solution[n]-solution[j]);
            if(diff ==0|| diff == n-j){
                ok = false;
                break;
            }
        }
        if(ok) search(n+1);
    }
}

int main(){
    solution_count = 0;
    search(0);
    return 0;
}