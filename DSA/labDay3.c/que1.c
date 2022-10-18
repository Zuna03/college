#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int Min_198(int a_198, int b_198)
{
    if (a_198 > b_198)
        return b_198;
    else
        return a_198;
}

int minDis_198(int arr_198[], int n_198, int x_198, int y_198)
{
    int posX_198 = -1;
    int posY_198 = -1;
    int dis_198 = INT_MAX;

    for (int i = 0; i < n_198; i++)
    {
        if (arr_198[i] == x_198)
        {
            posX_198 = i;
        }
        if (arr_198[i] == y_198)
        {

            posY_198 = i;
        }
        if (posX_198 != -1 && posY_198 != -1)
        {
            dis_198 = Min_198(dis_198, abs(posX_198 - posY_198));
        }
    }
    return dis_198;
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

    int x_198;
    int y_198;
    printf("Enter the two numbers \n");
    scanf("%d %d", &x_198, &y_198);

    printf("Min distance between two num is  %d\n", minDis_198(arr_198, n_198, x_198, y_198));

    return 0;
}