#include <stdio.h>
#include <math.h>
#include <ctype.h>

int toDecimal(char arr[], int nSize);
void toBinary(int n);
int main()
{
    int nSize;
    scanf("%d", &nSize);

    char arrHex[nSize];
    for(int i = 0; i<nSize; i++)
        scanf(" %c", &arrHex[i]);
    //toBinary(toDecimal(arrHex, nSize));
    printf("%d", toDecimal(arrHex, nSize));

}

int toDecimal(char arr[], int nSize)
{
    int intRepArr[nSize];
    int sumProd = 0, ind = nSize-1;
    for(int i = 0; i<nSize; i++)
    {
        if(isdigit(arr[i]))
        {
            intRepArr[i] = arr[i]-'0';
        }
        else
            intRepArr[i] = arr[i]-'A'+10;
    }

    for(int i = 0; i<nSize; i++)
    {
        sumProd += intRepArr[i]*pow(16, ind);
        ind--;
    }

    return sumProd;
}
void toBinary(int n)
{
    int temp = n, ctr = 0, rem;
    if(temp==0)
        printf("0");
    while(temp!=0)
    {
        temp/=2;
        ctr++;
    }
    temp = n;

    int arr[ctr];
    int i = ctr-1;
    while(temp!=0)
    {
        rem = temp%2;
        temp/=2;
        arr[i]=rem;
        i--;
    }
    for(int i = 0; i<ctr; i++)
        printf("%d", arr[i]);
}
