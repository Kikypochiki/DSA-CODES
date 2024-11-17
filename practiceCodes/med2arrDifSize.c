#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* concat2Arr(int arr1[], int arr2[], int m, int n);
void sortArr(int *arrNotSort);
void findMid(int *arrNotSort);
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int arr1[m];
    printf("Scan for arr1[%d]: ", m);
    for(int i = 0; i<m; i++)
        scanf("%d", &arr1[i]);

    int arr2[n];
    printf("Scan for arr2[%d]: ", n);
    for(int i = 0; i<n; i++)
        scanf("%d", &arr2[i]);

    int *arrNotSort = concat2Arr(arr1, arr2, m, n);

    for(int i = 1; i<=arrNotSort[0]; i++)
        printf("%d, ", arrNotSort[i]);
    printf("\n");

    sortArr(arrNotSort);

    for(int i = 1; i<=arrNotSort[0]; i++)
        printf("%d, ", arrNotSort[i]);
    printf("\n");
    findMid(arrNotSort);
}
int* concat2Arr(int arr1[], int arr2[], int m, int n)
{
    int mXn = m + n, ind = 1;
    int *newArr = (int*)malloc(sizeof(int) * (mXn+1));

    newArr[0] = mXn;

    for(int i = 0; i<m; i++)
    {
        newArr[ind] = arr1[i];
        ind++;
    }

    for(int i = 0; i<n; i++)
    {
        newArr[ind] = arr2[i];
        ind++;
    }

    return newArr;
}
void sortArr(int *arrNotSort)
{
    int temp;
    for(int i = 1; i<=arrNotSort[0]; i++)
    {
        for(int j = 1; j<=arrNotSort[0]-i; j++)
        {
            if(arrNotSort[j]>arrNotSort[j+1])
            {
                temp = arrNotSort[j];
                arrNotSort[j] = arrNotSort[j+1];
                arrNotSort[j+1] = temp;
            }
        }
    }
}
void findMid(int *arrNotSort)
{
    if((arrNotSort[0])%2 == 0)
    {
        int mid1 = arrNotSort[0] / 2;
        int mid2 = mid1 + 1;
        float valMid = (arrNotSort[mid1] + arrNotSort[mid2]) / 2.0;
        printf("MEDIAN: %.2f", valMid);
    }
    else
    {
        int mid1 = (arrNotSort[0]+1)/2;
        printf("MEDIAN: %d", arrNotSort[mid1]);
    }
}

