#include <stdio.h>
#include <stdlib.h>

int  main()
{
    void *x;

    void* arr1 = (void*)malloc(sizeof(void*)*4);
    *((int*)arr1) = 3;

    void* arr2 = (void*)malloc(sizeof(void*)*5);
    *((int*)arr2) = 4;

    void* arr3 = (void*)malloc(sizeof(void*)*2);
    *((int*)arr3) = 1;

    void* arr4 = (void*)malloc(sizeof(void*)*8);
    *((int*)arr4) = 7;

    void* arr5 = (void*)malloc(sizeof(void*)*6);
    *((int*)arr5) = 5;

    x = arr1;
    *((int*)arr1+1) = (int)arr3;
    *((int*)arr1+3) = (int)arr5;
    *((int*)arr2+1) = (int)arr1;
    *((int*)arr2+3) = (int)arr5;
    *((int*)arr2+4) = (int)arr4;
    *((int*)arr3+1) = (int)arr2;
    *((int*)arr5+4) = (int)arr4;
    *((int*)arr4+7) = (int)arr2;

    printf("%d\n", *((int*)x));
    printf("%d\n", *((int*)*((int*)x+1)));
    printf("%d\n", *((int*)*((int*)*((int*)x+1)+1)));
    printf("%d\n", *((int*)*((int*)*((int*)*((int*)x+1)+1)+4)));
    printf("%d\n", *((int*)*((int*)*((int*)*((int*)x+1)+1)+3)));

}

