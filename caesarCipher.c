#include <stdio.h>

int main()
{
    char arr1[5];
    char arr2[5];

    for(int i = 0; i<5; i++)
        scanf(" %c", &arr1[i]);
    for(int i = 0; i<5; i++)
    {
        arr2[i] = ((arr1[i])-'a')+1;
        arr2[i] = ((arr2[i])+3)%26;
        arr2[i] = ((arr2[i])+'a'-1);
    }

    for(int i = 0; i<5; i++)
        printf("%c ", arr2[i]);
}

