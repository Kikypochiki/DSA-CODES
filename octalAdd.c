#include <stdio.h>

int main()
{
    int arr1[3];
    int arr2[3];
    int newVal[4];
    int rem = 0;

    for(int i = 0; i<3; i++)
        scanf("%d", &arr1[i]);

    for(int i = 0; i<3; i++)
        scanf("%d", &arr2[i]);

    for(int i = 2; i>-1; i--)
    {
        newVal[i+1] = ((arr1[i]+arr2[i])+rem)%8;
        rem = ((arr1[i]+arr2[i])+rem)/8;
        newVal[0] = rem;
    }

    for(int i = 0; i<4; i++)
        printf("%d ", newVal[i]);
}
