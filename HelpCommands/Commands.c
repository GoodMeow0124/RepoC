#include <stdio.h>
#include <stdlib.h>
#include "Commands.h"



void main(){
    int n,solution;
    //address space
        int* pi1 = (int*)malloc(n*sizeof(int)); //create n*int address to pi
        int* pi2 = (int*)calloc(n , sizeof(int)); //create n*int address to pi initalize with 0
        int* pi3 = (int*)realloc(pi1, n*sizeof(int)); //change existed address space size of pi1 to pi3
        free(pi1); //free address space
        switch(solution){ //deal with no available memory
            case 1:
                    if(!pi1)    
                    {
                        fprintf(stderr, "Insufficient memory"); //print standard error, insufficient memory
                        exit(EXIT_FAILURE);\
                    }
            
            case 2: // Not support VSCode
            // Insert the define at fisrt;
            //         #define MALLOC(p,s)\
            //         if(!(p) = malloc(s)) {\
            //         fprintf(stderr, "Insufficient memory"); \
            //         exit(EXIT_FAILURE);\
            //         }
            //         //create address and detect failure
            //         MALLOC(pi1,sizeof(int));
            
            default:break;       
        }
    
    //

}