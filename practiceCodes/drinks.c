#include <stdio.h>

int main()
{
    int n, p;
    double sum = 0.0;
    scanf("%d", &n);

    for(int i = 0; i<n; i++)
    {
        scanf("%d", &p);
        sum += p;
    }

   printf("%f", (sum/n));
}
