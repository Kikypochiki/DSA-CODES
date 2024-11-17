#include <stdio.h>

void toOctal(int n);
int main()
{
    int n;
    scanf("%d", &n);

    toOctal(n);
}

void toOctal(int n)
{
    int temp = n, ctr = 0, rem, q;
    if(temp==0)
        printf("0");
    while(temp!=0)
    {
        temp/=8;
        ctr++;
    }
    temp = n;

    int arr[ctr];
    int i = ctr-1;
    while(temp!=0)
    {
        rem = temp%8;
        temp/=8;
        arr[i]=rem;
        i--;
    }
    for(int i = 0; i<ctr; i++)
        printf("%d", arr[i]);
}
