#include <stdio.h>

int checkCeleb(int arr[4][4], int ind);
int main()
{
    int arr[4][4] = {{1, 0, 0, 0},  {1, 0, 1, 0}, {1, 0, 1, 0}, {0, 0, 0, 0}};
    int checkCtr;

    for(int i = 0; i<4; i++)
    {
        checkCtr = 0;
        for(int j = 0; j<4; j++)
        {
            if(arr[i][j] == 0)
                checkCtr++;
        }
        if(checkCtr == 4)
        {
            if(checkCeleb(arr, i))
            {
                printf("CELEBRITY AT %d", i);
                return 0;
            }
        }
    }
    printf("THERE IS NO CELEBRITY");
    return 0;
}
int checkCeleb(int arr[4][4], int ind)
{
    int checkCtr;
    for(int i = 0; i < 4; i++)
    {
        checkCtr = 0;
        for(int j = 0; j<4; j++)
        {
            if(j != ind && arr[j][i] == 1)
                checkCtr++;
        }
        if(checkCtr == 3)
            return 1;
    }
    return 0;
}
