#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, n_char;
    char temp;
    printf("Enter number: ");
    scanf("%d", &n);

    char **arr = (char **)calloc(n, sizeof(char));

    for(int i = 0; i<n; i++)
    {
        printf("Enter row number for row %d: ", i);
        scanf("%d", &n_char);

        arr[i] = (char*)calloc(n_char, sizeof(char));

        scanf("%s", arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", i , arr[i]);
    }
}
