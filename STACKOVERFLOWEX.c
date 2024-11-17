#include <stdio.h>

void stackOverFlowEx(int num);
int main()
{
    int d = 10;
    stackOverFlowEx(d);
    return 0;
}
void stackOverFlowEx(int num)
{
    if(num == 0)
    {
        return;
    }
    else
    {
        printf("\n%d", num);
        return stackOverFlowEx(num+1);
    }
}

