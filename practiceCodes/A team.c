#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][3];

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<3; ++)
            scanf("%d", &arr[i][j]);
    }

    int count1 = 0;

    for(int i = 0; i<n; i++)
    {
        int count2 = 0;
        for(int j = 0; j<3; j++)
        {
            if(arr[i][j] == 1)
                count2++;
        }
        if(count2 >= 2)
            count1++;
    }

    printf("%d", count1);
}
