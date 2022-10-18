#include <stdio.h>

//program to find whether two matrix are identical or not

void identical_195(int row1_195, int column1_195, int row2_195, int column2_195, int arr1_195[row1_195][column1_195], int arr2_195[row2_195][column2_195])
{
    int flag = 0;

    if (row1_195 == row2_195 && column1_195 == column2_195) //exception handled
    {
        for (int i = 0; i < row1_195; i++)
        {
            for (int j = 0; j < column1_195; j++)
            {
                if (arr1_195[i][j] == arr2_195[i][j])
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }

        if (flag == 0)
        {
            printf("Matrices are identical \n");
        }
        else
        {
            printf("Matrices are not identical \n");
        }
    }
    else
    {
        printf("Matrices are not identical \n");
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

    identical_195(row1_195, column1_195, row2_195, column2_195, arr1_195, arr2_195);
    return 0;
}