#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    char b;
    double c;

    int* ptr1 = malloc(sizeof(int));
    ptr1 = &a;
    printf("%d\n", sizeof(*ptr1));

    char* ptr2 = malloc(sizeof(char));
    ptr2 = &b;
    printf("%d\n", sizeof(*ptr2));

    double* ptr3 = malloc(sizeof(double));
    ptr3 = &c;
    printf("%d\n", sizeof(*ptr3));
}
