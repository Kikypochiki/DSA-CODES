#include <stdio.h>
#include <string.h>

#define MAX_NUM 302

int main() {
    int number[MAX_NUM];
    int sum = 0;
    memset(number, 0, sizeof(number));
    number[0] = 1;

    for(int i = 0; i<1000; i++)
    {
        int carry = 0;
        for(int j = 0; j<MAX_NUM; j++)
        {
            int dig = number[j] * 2 + carry;
            number[j] = dig%10;
            carry = dig/10;
        }
    }

    for(int i = 0; i<MAX_NUM; i++)
    {
        sum+=number[i];
    }
    printf("%d", sum);
    return 0;
}
