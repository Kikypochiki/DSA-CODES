#include <stdio.h>

int main()
{
    int x, y, sum = 0, countZERO;
    scanf("%d %d", &x, &y);

    int matrix[x][y];

    for(int i = 0; i<x; i++)
    {
        for(int j = 0; j<y; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i<x; i++)
    {
        for(int j = 0; j<y; j++)
        {
            if(matrix[i][j]!=0)
            {
                int checkTRUE = 0;
                for(int k = 0; k<i; k++)
                {
                    if(matrix[k][j] == 0)
                        checkTRUE = 1;
                }
                if(checkTRUE == 0)
                {
                    sum += matrix[i][j];
                }
            }
        }
    }

    printf("%d", sum);
}
