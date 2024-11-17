#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* data1 = (int*)malloc(sizeof(int));
    int* data2 = (int*)malloc(sizeof(int));
    int* data3 = (int*)malloc(sizeof(int));

    *data1 = 3;
    *data2 = 5;
    *data3 = 10;

    double ave = (*data1+*data2+*data3)/3;
    printf("%.2lf", ave);

    free(data1);
    free(data2);
    free(data3);
    data1 = NULL;
    data2 = NULL;
    data3 = NULL;
}
