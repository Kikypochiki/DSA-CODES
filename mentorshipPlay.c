#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **jA = (int**)malloc(sizeof(int)*3);

    for(int i = 0; i<3; i++)
    {
        *(jA+i) = (int**)malloc(sizeof(int)*i+1);
    }
}
