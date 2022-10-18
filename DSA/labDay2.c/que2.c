#include <stdio.h>

//program to find sum of two matrix
void sum_195(int row1_195, int column1_195, int row2_195, int column2_195, int arr1_195[row1_195][column1_195], int arr2_195[row2_195][column2_195])
{
    int arr3_195[row1_195][column1_195];

    for (int i = 0; i < row1_195; i++)
    {
        for (int j = 0; j < column1_195; j++)
        {
            arr3_195[i][j] = arr1_195[i][j] + arr2_195[i][j];
        }
    }

    printf("Sum of elements of two matrices is :-\n");

    for (int i = 0; i < row1_195; i++)
    {
        for (int j = 0; j < column1_195; j++)
        {
            printf("%d  ", arr3_195[i][j]);
        }
        printf("\n");
    }
}

//program to find difference of two matrix

void difference_195(int row1_195, int column1_195, int row2_195, int column2_195, int arr1_195[row1_195][column1_195], int arr2_195[row2_195][column2_195])
{
    int arr3_195[row1_195][column1_195];
    for (int i = 0; i < row1_195; i++)
    {
        for (int j = 0; j < column1_195; j++)
        {
            arr3_195[i][j] = arr1_195[i][j] - arr2_195[i][j];
        }
    }

    printf("\n");

    printf("Difference of elements of two matrices is :-\n");

    for (int i = 0; i < row1_195; i++)
    {
        for (int j = 0; j < column1_195; j++)
        {
            printf("%d  ", arr3_195[i][j]);
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

    if (row1_195 != row2_195 || column1_195 != column2_195)
    {
        printf("Sum can't be found \n"); //exception handled
    }

    sum_195(row1_195, column1_195, row2_195, column2_195, arr1_195, arr2_195);

    printf("\n");

    difference_195(row1_195, column1_195, row2_195, column2_195, arr1_195, arr2_195);

    return 0;
}