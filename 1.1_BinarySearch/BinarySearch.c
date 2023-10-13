#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
#define MAX_SIZE 101 
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 
int binarysearch (int list[], int searchnum, int left, int right);
void SelectionSort(int [], int );  
void main(void) { 
    int n; 
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: "); 
    scanf("%d", &n); 
    //n random nubmer to array
    if( n < 1 || n > MAX_SIZE){ 
        fprintf(stderr, "Improper value of n\n"); 
        //exit(EXIT_FAILURE); 
    } 
    for(int i = 0; i < n ; i++) { 
        list[i] = rand( ) % 1000; 
        printf("%d ",list[i]); 
    } 

    SelectionSort(list,n); 
    
    printf("\n Sorted array:\n "); 
    for(int i = 0; i < n ; i++) printf("%d ",list[i]);
    printf("%d",binarysearch(list, 41, 0, sizeof(list)/sizeof(int))); 
    printf("\n"); 
} 

int binarysearch (int list[], int searchnum, int left, int right) 
{ 
    int middle ; 
    while (left <= right) 
    { 
        middle = (left + right)/2; 
        if (list[middle] < searchnum) left=middle+1; 
        else if (list[middle] == searchnum) return middle; 
        else right=middle-1;
    } 
    return -1; 
} 

void SelectionSort(int list[], int n) { 
    int i, j, min, temp; 
    for(i = 0; i < n ; i++) { 
        min = i; 
        for(j = i+1 ; j < n ; j++) if(list[j] < list[min]) min = j; 
        SWAP(list[i],list[min],temp); 
    } 
}
