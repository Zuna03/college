#include <stdio.h>

//program to find sum of diagonal elements of a matrix

void trace_195(int row_195, int column_195, int arr1_195[row_195][column_195])
{
    int sum_major_195 = 0;
    int sum_minor_195 = 0;

    for (int i = 0; i < row_195; i++)
    {
        for (int j = 0; j < column_195; j++)
        {
            if (i == j)
            {
                sum_major_195 += arr1_195[i][j];
            }
            if (j == row_195 - 1 - i)
            {
                sum_minor_195 += arr1_195[i][j];
            }
        }
    }

    printf("The sum of major diagonal elements is :- %d \n", sum_major_195);
    printf("The sum of minor diagonal elements is :- %d \n", sum_minor_195);
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

    if (row_195 != column_195)
    {
        printf("Sum can not be found \n"); //exception handled
    }

    trace_195(row_195, column_195, arr1_195);

    return 0;
}