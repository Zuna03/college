#include <stdio.h>
#include <stdlib.h>

// Sorts rows in Ascending order.
void ascendRow_198(int n_198, int m_198, int **a_198)
{
    for (int i = 0; i < n_198; i++)
    {
        for (int j = 0; j < m_198 - 1; j++)
        {
            for (int k = j + 1; k < m_198; k++)
            {
                if (a_198[i][j] > a_198[i][k])
                {
                    int temp_198 = a_198[i][j];
                    a_198[i][j] = a_198[i][k];
                    a_198[i][k] = temp_198;
                }
            }
        }
    }
}
// Sorts columns in descending order.
void descendColumn_198(int n_198, int m_198, int **a_198)
{
    for (int i = 0; i < m_198; i++)
    {
        for (int j = 0; j < n_198 - 1; j++)
        {
            for (int k = j + 1; k < n_198; k++)
            {
                if (a_198[j][i] < a_198[k][i])
                {
                    int temp_198 = a_198[j][i];
                    a_198[j][i] = a_198[k][i];
                    a_198[k][i] = temp_198;
                }
            }
        }
    }
}
// Main Function.
int main()
{
    printf("Enter number of rows and columns :- \n");
    int n_198, m_198, **a_198;
    scanf("%d%d", &n_198, &m_198);

    a_198 = (int **)malloc(n_198 * sizeof(int *));
    for (int i = 0; i < n_198; i++)
    {
        a_198[i] = (int *)malloc(m_198 * sizeof(int));
    }                                                                                                     

    printf("Enter elements of array :- \n");
    for (int i = 0; i < n_198; i++)
    { 
        for (int j = 0; j < m_198; j++)
            scanf("%d", &a_198[i][j]);
    }

    ascendRow_198(n_198, m_198, a_198);
    descendColumn_198(n_198, m_198, a_198);

    printf("The desired matrix is :- \n");
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