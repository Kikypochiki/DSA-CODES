#include <stdio.h>

int main()
{
    int n, min, sum = 0;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    if(arr[0] < arr[n-1])
        min  = arr[0];
    else
        min = arr[n-1];

    for(int i = 0; i<n; i++)
    {
        if(min > arr[i])
        {
            sum += min-arr[i];
        }
    }

    printf("%d", sum);
}
