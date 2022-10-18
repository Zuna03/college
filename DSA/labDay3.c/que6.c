#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Finds the largest number and it’s frequency.
void maxNumFreq_198(int *a_198, int *num_198, int *count_198, int n_198)
{
    *num_198 = INT_MIN;
    for (int i = 0; i < n_198; i++)
    {
        if (*num_198 < a_198[i])
        {
            *num_198 = a_198[i];
            *count_198 = 1;
        }
        else if (*num_198 == a_198[i])
        {
            *count_198 = *count_198 + 1;
        }
    }
}
// Main Function.
int main()
{
    printf("Enter size of the array ;- \n");
    int n_198, *a_198;
    scanf("%d", &n_198);

    a_198 = (int *)malloc(n_198 * sizeof(int));

    printf("Enter elements of the array \n");
    for (int i = 0; i < n_198; i++)
    {
        scanf("%d", &a_198[i]);
    }

    int max_num_198, count_198;
    maxNumFreq_198(a_198, &max_num_198, &count_198, n_198);
    printf("Max num is :- %d and it's frequency is:- %d", max_num_198, count_198);
    return 0;
}
