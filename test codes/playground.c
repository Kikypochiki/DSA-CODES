#ifndef PLAYGROUND
#define PLAYGROUND
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* data1 = (int*)malloc(sizeof(int));
    int* data2 = (int*)malloc(sizeof(int));

    *data1 = 3;
    *data2 = 5;

    *data1 = (*data1 + *data2)/2;

    printf("%d\n", *data1);
    free(data2);
    data2 = NULL;
}

#endif