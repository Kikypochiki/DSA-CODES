#include <stdio.h>

int main()
{
    int n, x1, y1, x2, y2;
    scanf("%d", &n);

    int mat[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);

    int visited[n][n];
    visited[x1][x2] = 1;

    int offsetX[4] = {0, 0, 1, -1};
    int offsetY[4] = {1, -1, 0, 0};

    int ctr = 0;
    while(x1 != x2 && y1 != y2)
    {
        for(int i = 0; i<4; i++)
        {
            int nX = x1 + offsetX[i];
            int nY = y1 + offsetY[i];

            if(nX >= 0 && nX < 3 && nY >= 0 && nY < 3)
            {

            }
        }
    }
    printf("%d", ctr);
}
