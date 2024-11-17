#include <stdio.h>

void mergeSort(int arr[], int len);
void mergeSortRec(int arr[], int l, int r);
void mergeSortArray(int arr[], int l, int m, int r);
int main()
{
    int arr[10] = {5, 6 ,8, 34 ,67, 34, 65, 76, 8, 1};
    int len = 10;

    mergeSort(arr, len);
    for(int i = 0; i<len; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}
void mergeSort(int arr[], int len)
{
    mergeSortRec(arr, 0, len-1);
}
void mergeSortRec(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = l + (r - l) / 2;

        mergeSortRec(arr, l, m);
        mergeSortRec(arr, m+1, r);

        mergeSortArray(arr, l, m, r);
    }
}
void mergeSortArray(int arr[], int l, int m, int r)
{
    int leftLen = m - l + 1;
    int rightLen = r - m;

    int tempLeft[leftLen];
    int tempRight[rightLen];

    int i, j, k;

    for(int i = 0; i < leftLen; i++)
        tempLeft[i] = arr[l + i];

    for(int i = 0; i < rightLen; i++)
        tempRight[i] = arr[m + 1 + i];

    for(i = 0, j = 0, k = l; k <= r; k++)
    {
        if((i<leftLen) && (j >= rightLen || tempLeft[i] <= tempRight[j]))
        {
            arr[k] = tempLeft[i];
            i++;
        }
        else
        {
            arr[k] = tempRight[j];
            j++;
        }
    }
}
