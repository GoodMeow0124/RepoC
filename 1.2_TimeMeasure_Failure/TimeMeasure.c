#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SelectionSort.h"
#define MAX_SIZE 1001

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