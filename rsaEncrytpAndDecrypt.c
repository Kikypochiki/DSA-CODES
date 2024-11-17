#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* toDecimal(int pow);
void toIntFromChar(char c[], int lenChar, int *numArr);
int toBlockNum(int n);

int main()
{
    //int n = 45;
    //int len = ceil(log(n+1)/log(2));
    int p, q, e, lenCharArr;
    printf("ENTER p, q, e AND THE LENGTH OF THE WORD\n");
    scanf("%d %d %d %d", &p, &q, &e, &lenCharArr);

    char charArr[lenCharArr];
    int *numArr = (int*)malloc(sizeof(int)*lenCharArr);

    for (int i = 0; i < lenCharArr; i++)
    {
        scanf(" %c", &charArr[i]);
    }

    toIntFromChar(charArr, lenCharArr, numArr);
}
void toIntFromChar(char c[], int lenChar, int *numArr)
{7
    for(int i = 0; i<lenChar; i++)
        *(numArr+i) = c[i]-'A';
}
