#include <stdio.h>
#include <stdlib.h>

int main()
{

    double weights[10];
    double ave;
    for(int i = 0; i<10; i++)
    {
        weights[i] = rand()%10+1;
        printf("%.2lf ", weights[i]);
        ave += weights[i];
    }
    ave /= 10;
    printf("\n");
    printf("%.2lf\n", ave);
    for(int i = 0; i<10; i++)
    {
        if(weights[i]>ave)
        {
            printf("%.2lf ", weights[i]);
        }
    }
}
