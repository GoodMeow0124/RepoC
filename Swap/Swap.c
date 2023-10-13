#include <stdio.h>
#include <stdlib.h>
//Method1
void swap (int *tempa, int *tempb);

//Method2
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void main(){
    int tempa = 0;
    int tempb = 1;
    swap(&tempa,&tempb);
    printf("%d,%d",tempa,tempb);
}

void swap (int *tempa, int *tempb)
{
    int temp = *tempa;
    *tempa = *tempb;
    *tempb = temp;
}