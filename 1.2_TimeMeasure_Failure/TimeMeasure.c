#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SelectionSort.h"
#define MAX_SIZE 1001

//Calculate Selectionsort spend how many time 
void main(void)
{
    int i, step = 10;
    int* a = (int* )malloc(MAX_SIZE*sizeof(int));
    double duration;
    clock_t start;
    printf(" n time\n");
    for (int n = 0; n <= 1000; n += step)
    {
        for (i = 0; i < n; i++) a[i] = n - i;
        start = clock();    
        SelectionSort(a, n);
        duration = ((double) (clock() - start))/CLOCKS_PER_SEC;
        printf("%6d %f\n", n, duration);
        if (n == 100) step = 100;
    }
}

//Because time maybe <<<<1
//so it will print 0s
//more accurate
// void main(void)
// { 
//     int i, n, step = 10;
//     int a[MAX_SIZE];
//     double duration;
//     clock_t start;
//     printf(" n repetition time\n");
//     for (n = 0; n <= 1000; n += step)
//     { 
//         long repetitions = 0;
//         start = clock();
//         do
//         { 
//             repetitions++;
//             for (i=0; i<n ; i++) a[i] = n - i;
//             SelectionSort(a, n);
//         }while(clock() - start < 1000);
//         duration = ((double) (clock() - start))/CLOCKS_PER_SEC;
//         duration /= repetitions;
//         printf("%6d %9d %f\n", n, repetitions, duration);
//         if (n == 100) step = 100;
//     }
// }
