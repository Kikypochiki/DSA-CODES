#include <stdio.h>

int main()
{
    int n, count = 0;
    scanf("%d", &n);

    int bills[5] = {100, 20, 10, 5, 1};

    for(int i = 0; i<5; i++)
    {
        if(n >= bills[i])
        {
            count += n/bills[i];
            n = n%bills[i];
        }
    }

    printf("%d", count);
}
