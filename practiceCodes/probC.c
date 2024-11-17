#include <stdio.h>

int main()
{
    int n, sum = 0;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    int sumAve = sum/n;

    for(int i = 0; i<n; i++)
    {
        if(a[i]<sumAve)
            printf("%d ", a[i]);
    }

}
