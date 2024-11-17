#include <stdio.h>
#include <stdlib.h>

int* findEven(int arrInt[], int size, int ctr);
int main()
{
    int size = 10, ctr = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i<size; i++)
    {
        if(arr[i]%2==0)
        {
            ctr++;
        }
    }
    int *evenArr = findEven(arr, size, ctr);
    for(int i = 0; i<ctr; i++)
    {
        printf("%d ", evenArr[i]);
    }
}
int* findEven(int arrInt[], int size, int ctr)
{
    int* arrEven = (int*)malloc(ctr*sizeof(int));
    int ind = 0;
    for(int i = 0; i<size; i++)
    {
        if(arrInt[i]%2==0)
        {
            arrEven[ind] = arrInt[i];
            ind++;
        }
    }
    return arrEven;
}
