#include <stdio.h>
#include <stdlib.h>

int main()
{
    void** arr = (void**)malloc(sizeof(void*)*5);
    int arrInt[4] = {4, 7, 9, 13};
    char arrChar[3] = {'a', 'b', 'c'};
    float arrFloat[3] = {12.1, 7.5, 9.88};

    arr[1] = (int*)arrInt;
    arr[2] = (char*)arrChar;
    arr[4] = (float*)arrFloat;

    printf("%d", *(*((int**)arr+1)+3));
}
