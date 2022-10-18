#include <stdio.h>

//program to multiply two matrix

void multiply_195(int row1_195, int column1_195, int row2_195, int column2_195, int arr1_195[row1_195][column1_195], int arr2_195[row2_195][column2_195])
{
    int product_195[row1_195][column2_195];

    if (column1_195 != row2_195) //exception handled
    {
        printf("Multiplication not possible \n");
    }
    else
    {
        for (int i = 0; i < row1_195; i++)
        {
            for (int j = 0; j < column2_195; j++)
            {
                product_195[i][j] = 0;
                for (int y = 0; y < column1_195; y++)
                {
                    product_195[i][j] += arr1_195[i][y] * arr2_195[y][j];
                }
            }
        }
    }

    printf("The product of two matrix is :- \n");

    for (int i = 0; i < row1_195; i++)
    {
        for (int j = 0; j < column2_195; j++)
        {
            printf("%d ", product_195[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //taking input

    printf("Enter row of  first matrix \n");
    int row1_195;
    scanf("%d", &row1_195);
    printf("Enter column of  matrix \n");
    int column1_195;
    scanf("%d", &column1_195);

    int arr1_195[row1_195][column1_195];

    printf("Enter elements of first matrix \n");
    for (int i = 0; i < row1_195; i++)
    {
        for (int j = 0; j < column1_195; j++)
        {
            scanf("%d", &arr1_195[i][j]);
        }
    }

    printf("Enter row of  second matrix \n");
    int row2_195;
    scanf("%d", &row2_195);
    printf("Enter column of  second matrix \n");
    int column2_195;
    scanf("%d", &column2_195);

    int arr2_195[row2_195][column2_195];

    printf("Enter elements of second matrix \n");
    for (int i = 0; i < row2_195; i++)
    {
        for (int j = 0; j < column2_195; j++)
        {
            scanf("%d", &arr2_195[i][j]);
        }
    }

    multiply_195(row1_195, column1_195, row2_195, column2_195, arr1_195, arr2_195);
    return 0;
}