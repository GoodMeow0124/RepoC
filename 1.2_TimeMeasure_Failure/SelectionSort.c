#include "SelectionSort.h"
#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#define MAX_SIZE 1001 
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 

//some error happened
void SelectionSort(int list[], int n) { 
    int i, j, min, temp; 
    for(i = 0; i < n ; i++) { 
        min = i; 
        for(j = i+1 ; j < n ; j++) if(list[j] < list[min]) min = j; 
        SWAP(list[i],list[min],temp); 
    } 
}