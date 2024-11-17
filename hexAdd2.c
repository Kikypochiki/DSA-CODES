#include <stdio.h>
#include <ctype.h>

int charToInt(char c);

int main()
{
    char arr1[9];
    char arr2[9];
    char newVal[10];

    \

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
