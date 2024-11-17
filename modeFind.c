#include <stdio.h>
#include <string.h>

int main()
{
    int num[20];
    int ctr[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int maxVal = 0;
    int tempVal;

    for(int i = 0; i<20; i++)
        scanf("%d", &num[i]);

    for(int i = 0; i<20; i++)
    {
        for(int j = 0; j<20 - i - 1; j++)
        {
            if(num[j]>num[j+1])
            {
                tempVal = num[j];
                num[j] = num[j+1];
                num[j+1] =  tempVal;
            }
        }
    }

    for(int i = 0; i<20; i++)
    {
        for(int j = i+1; j<20; j++)
        {
            if(num[i]==num[j])
                ctr[i]++;
            if(ctr[i]>maxVal)
                maxVal = ctr[i];
        }
    }

    for(int i = 0; i<20; i++)
    {
        if(ctr[i] ==  maxVal)
            printf("%d ", num[i]);
    }

    return 0;
}
