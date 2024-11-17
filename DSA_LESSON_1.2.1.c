#include <stdio.h>

//void pointer
int main()
{
    int j = 10;
    void *i = &j;

    printf("%d", *(int*)i);
}
