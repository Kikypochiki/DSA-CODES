#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *a, *b, *c;
    char *d;
    float *e;
    int *f;

    char arr1[6] = {'s', 'k', 'y', 'r', 'i', 'm'};
    float v1 = 2.71823;
    int arr2[3] = {45, 23, 7};

    a = &b;
    b = &d;
    d = arr1;
    for(int i = 0; i<sizeof(arr1)/sizeof(char); i++)
        printf("%c ", *(**(char***)a+i));

    b = &e;
    e = &v1;
    printf("\n%f\n", ***((float***)a));

    a = &c;
    c = &f;
    f = arr2;
    for(int i = 0; i<sizeof(arr2)/sizeof(int); i++)
        printf("%d ", *(**(int***)a+i));
}
