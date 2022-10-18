#include <stdio.h>
#include <stdlib.h>

void arrange_198(int arr_198[], int n_198)
{
    for (int i = 0; i < n_198; i++)
    {
        for (int j = i + 1; j < n_198; j++)
        {
            if (arr_198[j] > arr_198[i])
            {
                arr_198[i] = arr_198[j];
                break;
            }
        }
    }
}

int main()
{

    int n_198;
    printf("Enter the size of the array \n");
    scanf("%d", &n_198);

    int *arr_198 = (int *)malloc(n_198 * sizeof(int));
    printf("Enter the elements of the array \n");
    for (int i = 0; i < n_198; i++)
    {
        scanf("%d", &arr_198[i]);
    }

    arrange_198(arr_198, n_198);
    for (int i = 0; i < n_198; i++)
    {
        printf("%d ", arr_198[i]);
    }

    return 0;
}