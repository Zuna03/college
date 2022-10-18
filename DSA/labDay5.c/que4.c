#include <stdio.h>

// COMPARING

char compare_198(int x, int y)
{
    if (x < y)
        return '<';

    else if (x > y)
        return '>';

    else
        return '=';
}

// ADDING OF TWO SPARSH MATRICES

void add_198(int A_198[][3], int B_198[][3], int C_198[][3])
{
    int i = 1, j = 1, k = 1;
    int t1_198, t2_198;

    if (A_198[0][0] != B_198[0][0] && A_198[0][1] != B_198[0][1])
    {
        printf("\nADDition not possible.");
        return;
        ;
    }

    C_198[0][0] = A_198[0][0];
    C_198[0][1] = A_198[0][1];

    t1_198 = A_198[0][2];
    t2_198 = B_198[0][2];

    while (i <= t1_198 && j <= t2_198)
    {
        switch (compare_198(A_198[i][0], B_198[j][0]))
        {
        case '=':

            switch (compare_198(A_198[i][1], B_198[j][1]))
            {
            case '=':

                C_198[k][0] = A_198[i][0];
                C_198[k][1] = A_198[i][1];
                C_198[k][2] = A_198[i][2] + B_198[j][2];

                k++;
                i++;
                j++;
                break;

            case '<':

                C_198[k][0] = A_198[i][0];
                C_198[k][1] = A_198[i][1];
                C_198[k][2] = A_198[i][2];

                k++;
                i++;
                break;

            case '>':

                C_198[k][0] = B_198[j][0];
                C_198[k][1] = B_198[j][1];
                C_198[k][2] = B_198[j][2];

                k++;
                j++;
                break;
            }
            break;

        case '<':

            C_198[k][0] = A_198[i][0];
            C_198[k][1] = A_198[i][1];
            C_198[k][2] = A_198[i][2];

            k++;
            i++;
            break;

        case '>':

            C_198[k][0] = B_198[j][0];
            C_198[k][1] = B_198[j][1];
            C_198[k][2] = B_198[j][2];

            k++;
            j++;
            break;
        }
    }

    while (i <= t1_198)
    {
        C_198[k][0] = A_198[i][0];
        C_198[k][1] = A_198[i][1];
        C_198[k][2] = A_198[i][2];
        k++;
        i++;
    }

    while (j <= t2_198)
    {
        C_198[k][0] = B_198[j][0];
        C_198[k][1] = B_198[j][1];
        C_198[k][2] = B_198[j][2];
        k++;
        j++;
    }

    C_198[0][2] = k - 2;

    printf("\nValue of k = %d", k);

    printf("\n\nPrint the sum of two Three - Tuppled matrices:\n");

    for (i = 0; i <= k - 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", C_198[i][j]);
        }

        printf("\n");
    }

    return;
}

// MAIN

int main()
{
    int i, j, k, m, n;

    printf("\nEnter the value of m and n: ");
    scanf("%d%d", &m, &n);

    // MATRIX - 1

    int a[m][n];

    printf("\nEnter the elements in matrix a: \n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nPrint matrix a:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }

    // CONVERTING INTO THREE TUPLE FORMAT

    int A_198[10][3];

    A_198[0][0] = m;
    A_198[0][1] = n;

    k = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                k++;

                A_198[k][0] = i;
                A_198[k][1] = j;
                A_198[k][2] = a[i][j];
            }
        }

        A_198[0][2] = k;
    }

    // PRINTING THREE TUPLED MATRIX

    printf("\n\nPrint Tupled matrix:\n");

    for (i = 0; i < k + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", A_198[i][j]);
        }
        printf("\n");
    }

    // MATRIX - 2

    int b[m][n];

    printf("\n\n\nEnter the elements in matrix b:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nPrint matrix a:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d ", b[i][j]);
        }
        printf("\n");
    }

    // CONVERTING INTO THREE TUPLE FORMAT

    int B_198[10][3];

    int l;

    B_198[0][0] = m;
    B_198[0][1] = n;

    l = 0;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][j] != 0)
            {
                l++;

                B_198[l][0] = i;
                B_198[l][1] = j;
                B_198[l][2] = b[i][j];
            }
        }

        B_198[0][2] = l;
    }

    printf("\n\nPrint Tupled matrix:\n");

    for (i = 0; i < l + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %d ", B_198[i][j]);
        }

        printf("\n");
    }

    // NOW WE WILL FIND SUM OF TWO THREE-TUPPLED MATRICES

    int C_198[15][3];

    add_198(A_198, B_198, C_198);

    return 0;
}