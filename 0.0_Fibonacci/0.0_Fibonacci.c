#include <stdio.h>
#include <stdlib.h>

int Fibonacci1(int n);
int Fibonacci2(int n);

void main(){
    printf("%d",Fibonacci2(10));
}

//T(n) >= 2^(n/2)
int Fibonacci1(int n) {
    if (n<=1) return n;
    else return Fibonacci1(n-1)+Fibonacci1(n-2);
}

//O(n)
int Fibonacci2(int n) {
    int* temp = malloc(sizeof(int)*n);
    temp[0] = 0; temp[1] = 1;
    if (n>0) for(int i=2; i<=n; i++) temp[i]=temp[i-1]+temp[i-2];
    return temp[n];
}

//1 need calculate every number;
//2 stores calculate consequent;