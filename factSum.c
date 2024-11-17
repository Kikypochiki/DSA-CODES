#include <stdio.h>
#include <string.h>

#define MAX_NUM 158
int main()
{
    int number[MAX_NUM];
    memset(number, 0, sizeof(number));
    int sum = 0;

    number[0] = 1;

    for(int i = 1; i<=100; i++)
    {
        int carry = 0;
        for(int j = 0; j<MAX_NUM; j++)
        {
            int dig = number[j] * i + carry;
            number[j] = dig%10;
            carry = dig/10;
        }
    }

    for(int i = MAX_NUM-1; i>-1; i--)
        printf("%d ", number[i]);

    /*for(int i = 0; i<MAX_NUM; i++)
        sum+=number[i];

    printf("%d", sum);*/
}
