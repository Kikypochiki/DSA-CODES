#include <stdio.h>
#include <stdlib.h>

void printBinary(int *arr);
int* decimalToBinary(int n);
int main()
{
    printBinary(decimalToBinary(100));
}
int* decimalToBinary(int n)
{
    int temp = n, ctr = 0, rem = 0;

    if(temp == 0)
        return 0;

    while(temp!=0)
    {
        temp=temp/2;
        ctr++;
    }

    temp = n;

    int *arr = (int*)malloc(sizeof(int)*ctr+1);
    int ind = ctr;
    arr[0] = ctr;

    while(temp!=0)
    {
        rem = temp%2;
        temp=temp/2;
        *(arr+ind) = rem;
        ind--;
    }

    return arr;
}
void printBinary(int *arr)
{
    for(int i = 1; i<=arr[0]; i++)
        printf("%d", arr[i]);
}
