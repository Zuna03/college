#include <stdio.h>

//program to fing frquency of even numbers in a given matrix

void frequency(int row_195, int column_195, int arr1_195[row_195][column_195])
{
    int count_195 = 0;

    for (int i = 0; i < row_195; i++)
    {
        for (int j = 0; j < column_195; j++)
        {
            if (arr1_195[i][j] % 2 == 0)
            {
                count_195++;
            }
        }
    }

    printf("Frequency of even numbers is :- %d", count_195);
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

    frequency(row_195, column_195, arr1_195);
    return 0;
}