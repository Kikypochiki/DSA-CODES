#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int arr[3][3] = {{5, 6 , -2},
                     {7, 8, 1},
                     {1, 2, 9}};

    int offsetX[] = {0, 0, 1, -1, -1, 1, -1, 1};
    int offsetY[] = {1, -1, 0, 0, -1, 1, 1, -1};

    for(int i = 0; i<8; i++)
    {
        int nx = x + offsetX[i];
        int ny = y + offsetY[i];

        if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            if(arr[nx][ny] > arr[x][y])
                printf("%d ", arr[nx][ny]);
    }
}
