#include <iostream>
#include "../common/util.h"
#define MAX 20

// f(1) = f(2) = 1;
// f(n) = f(n-1) + f(n-2)

// Original way
int fib(int n) {
    int ret;
	if (n <= 0) {
		ret = 0;
	}else if (n == 1) {
		ret = 1;
    }else {
        ret = fib(n - 1) + fib(n - 2);
    }
    return ret;
}

int fibs[MAX];

//Cache
int fib2(int n){
    if(n<0) return 0;
    if(n==0 || n==1) {
        fibs[n] = 1;
        return 1;
    }
    if(fibs[n]!=0) return fibs[n];
    fibs[n] = fib2(n-1)+fib2(n-2);
    return fibs[n];
}

//Non recursive
long fib3(long n){
    if(n<=0) return 0;
    if(n==1) return 1;
    long a=1,b=1;
    for(long i=3;i<=n;++i){
        long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    fib2(MAX);
    for(int i = 0; i<MAX; i++) {
        printf("%d ",fibs[i]);
    }
    printf("\n");
    
    printf("%ld\n", fib3(MAX));
    
    printf("%d\n", pow(2,10));
	return 0;
}