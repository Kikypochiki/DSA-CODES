#include <stdio.h>
#include <ctype.h>

int charToInt(char c);
int main()
{
    char arr1[9];
    char arr2[9];
    char newVal[9];
    char temp[10];
    for(int i = 0; i<9; i++)
    {
        scanf(" %c", &arr1[i]);
    }

    printf("\n");

    for(int i = 0; i<9; i++)
    {
        scanf(" %c", &arr2[i]);
    }
    int rem = 0;
    for(int i = 8; i>-1; i--)
    {
        newVal[i] = (charToInt(arr1[i])+charToInt(arr2[i])+rem)%16;
        if(newVal[i]<10)
        {
            newVal[i] = ((newVal[i])+'0');
        }
        else
        {
            newVal[i] = ((newVal[i])+'A')-10;
        }

        rem = (charToInt(arr1[i])+charToInt(arr2[i])+rem)/16;
         temp[i+1] = newVal[i];
         temp[0] = rem+'0';
        //printf("%c ", newVal[i]);
    }
    for(int i = 0; i<10; i++)
        printf("%c ", temp[i]);
}
int charToInt(char c)
{
    if(isdigit(c))
    {
        return c - '0';
    }
    else
    {
        return (c-'A')+10;
    }
}
