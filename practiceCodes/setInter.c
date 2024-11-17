#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};

    for(int i = 0; i<sizeof(arr)/sizeof(int); i++)
    {
        int check = 0, check2 = 0;
        for(int j = 0; j<sizeof(arr2)/sizeof(int); j++)
        {
            if(arr[i] == arr2[j])
                check = 1;

            if(arr2[i] == arr[j])
                check2 = 1;
        }

        if(check == 1)
            printf("%d, ", arr[i]);
        if(check != 1)
            printf("%d, ", arr[i]);
        if(check2 != 1)
            printf("%d, ", arr2[i]);
    }
}
