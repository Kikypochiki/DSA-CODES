#include <stdio.h>
#include <math.h>

int main()
{
    int num = , revNum = 0;
    int len = ceil(log(num+1)/log(10));

    for(int i = 0; i<len; i++)
    {
        int d = num%10;
        revNum = (revNum*10)+d;
        num/=10;
    }
    for(int i = 0; i<len; i++)
    {
        int d = revNum%10;
        printf("%c", d+'A');
        revNum/=10;
    }
}
