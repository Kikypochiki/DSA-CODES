#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **jaggedArr = (int**)malloc(5*sizeof(int));
    int *arrSize = (int *)malloc(5*sizeof(int));

    int *temp;
    int tempSize;

    for(int i = 0; i<5; i++)
    {
        jaggedArr[i] = (int*)malloc((i+1)*sizeof(int));
        arrSize[i] = i+1;
    }

    for(int i = 0; i<5; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j<=i; j++)
        {
            jaggedArr[i][j] = j;
            printf("%d ", jaggedArr[i][j]);
        }
        printf("\n");
    }

    temp = jaggedArr[1];
    jaggedArr[1] = jaggedArr[4];
    jaggedArr[4] = temp;

    tempSize = arrSize[1];
    arrSize[1] = arrSize[4];
    arrSize[4] = tempSize;

    printf("\n");

    for(int i = 0; i<5; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j<arrSize[i]; j++)
        {
            printf("%d ", jaggedArr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        free(jaggedArr[i]);
    }
    free(jaggedArr);
    free(arrSize);

    return 0;
}
