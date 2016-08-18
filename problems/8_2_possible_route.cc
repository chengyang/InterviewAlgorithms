#include <iostream>

int PossibleRoute(int m, int n){
    if(m==0 || n==0) return 0;
    if(m==1 || n==1) return 1;
    return PossibleRoute(m-1, n)+PossibleRoute(m, n-1);
}

int main() {
    printf("%d\n", PossibleRoute(5, 6));
}