#include <stdio.h>

// program to arrange elements of a column in ascending order

void arranging_195(int row_195, int column_195, int arr1_195[row_195][column_195])
{
    for (int j = 0; j < column_195; j++)
    {
        for (int i = 0; i < row_195; i++)
        {
            for (int k = 0; k < row_195 - i; k++)
            {
                if (arr1_195[k][j] > arr1_195[k + 1][j])
                {
                    int temp = arr1_195[k][j];
                    arr1_195[k][j] = arr1_195[k + 1][j];
                    arr1_195[k + 1][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < row_195; i++)
    {
        for (int j = 0; j < column_195; j++)
        {
            printf("%d  ", arr1_195[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    //taking input

    printf("Enter row of  matrix \n");
    int row_195;
    scanf("%d", &row_195);
    printf("Enter column of  matrix \n");
    int column_195;
    scanf("%d", &column_195);

    int arr1_195[row_195][column_195];

    printf("Enter elements of  matrix \n");
    for (int i = 0; i < row_195; i++)
    {
        for (int j = 0; j < column_195; j++)
        {
            scanf("%d", &arr1_195[i][j]);
        }
    }

    arranging_195(row_195, column_195, arr1_195);

    return 0;
}