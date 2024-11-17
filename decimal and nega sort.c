#include <stdio.h>
#include <math.h>

int main()
{
    float arr[15];
    float temp;

    for(int i = 0; i<15; i++)
    {
        scanf("%f", &arr[i]);
    }

    for(int i = 0; i<15; i++)
    {
        for(int j = 0; j<15-i-1; j++)
        {
            if(fabs(arr[j])>fabs(arr[j+1]))
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i<15; i++)
    {
        printf("%.3f ", arr[i]);
    }
}
