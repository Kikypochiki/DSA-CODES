#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, n_int, tempNum;
    printf("Enter number: ");
    scanf("%d", &n);

    int **arr = (int**)calloc(n, sizeof(int));
    int *arrSize = (int*)calloc(n, sizeof(int));

    for(int i = 0; i<n; i++)
    {
        printf("Enter Size row %d: ", i+1);
        scanf("%d", &n_int);

        arrSize[i] = n_int;
        arr[i] = (int*)calloc(n_int, sizeof(int));

        for(int j = 0; j<n_int; j++)
        {
            scanf("%d", &tempNum);
            arr[i][j] = tempNum;
        }
    }

    printf("\n");

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<arrSize[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
