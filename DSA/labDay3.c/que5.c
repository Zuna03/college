#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Swaps two integers.
void swap_198(int *a_198, int *b_198)
{
    int temp_198 = *a_198;
    *a_198 = *b_198;
    *b_198 = temp_198;
}

// Returns the position of the desired element in sorted array.
int partition_198(int l_198, int r_198, int *a_198)
{
    int x_198 = a_198[r_198], i_198 = l_198;
    for (int j = l_198; j <= r_198 - 1; j++)
    {
        if (a_198[j] <= x_198)
        {
            swap_198(&a_198[i_198], &a_198[j]);
            i_198++;
        }
    }
    swap_198(&a_198[i_198], &a_198[r_198]);
    return i_198;
}
// Finds kth index element.
int kthElement_198(int l_198, int r_198, int k_198, int *a_198)
{
    if (k_198 > 0 && k_198 <= r_198 - l_198 + 1)
    {
        int pos_198 = partition_198(l_198, r_198, a_198);
        if (pos_198 - l_198 == k_198 - 1)
            return a_198[pos_198];
        if (pos_198 - l_198 > k_198 - 1)
            return kthElement_198(l_198, pos_198 - 1, k_198, a_198);
        return kthElement_198(pos_198 + 1, r_198, k_198 - pos_198 + l_198 - 1, a_198);
    }
    return INT_MAX;
}
// Main Function.
int main()
{
    printf("Enter size of the array ;- \n");

    int n_198, k_198, *a_198;
    scanf("%d", &n_198);

    printf("Enter value of k ;- \n");
    scanf("%d", &k_198);

    a_198 = (int *)malloc(n_198 * sizeof(int));

    printf("Enter elements of the array \n");
    for (int i = 0; i < n_198; i++)
    {
        scanf("%d", &a_198[i]);
    }

    printf("Kth element from start is : %d\n", kthElement_198(0, n_198 - 1, k_198, a_198));
    printf("Kth element from end is : %d\n", kthElement_198(0, n_198 - 1, n_198 - k_198 + 1, a_198));
    return 0;
}