#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Swaps Columns.
void swapColumn_198(int n_198, int m_198, int **a_198)
{
    int start_198 = 0, end_198 = m_198 - 1;
    while (start_198 < end_198)
    {
        for (int i = 0; i < n_198; i++)
        {
            int temp_198 = a_198[i][start_198];
            a_198[i][start_198] = a_198[i][end_198];
            a_198[i][end_198] = temp_198;
        }
        start_198++;
        end_198--;
    }
}
// Main Function.
int main()
{
    printf("Enter rows and columns of matrix ;- \n");
    int n_198, m_198, **a_198;
    scanf("%d%d", &n_198, &m_198);

    a_198 = (int **)malloc(n_198 * sizeof(int *));
    for (int i = 0; i < n_198; i++)
    {
        a_198[i] = (int *)malloc(m_198 * sizeof(int));
    }

    printf("Enter elements of the matrix \n");

    for (int i = 0; i < n_198; i++)
    {
        for (int j = 0; j < m_198; j++)
        {
            scanf("%d", &a_198[i][j]);
        }
    }
    printf("The output matrix is :- \n");
    
    swapColumn_198(n_198, m_198, a_198);
    for (int i = 0; i < n_198; i++)
    {
        for (int j = 0; j < m_198; j++)
        {
            printf("%d ", a_198[i][j]);
        }
        printf("\n");
    }
    return 0;
}