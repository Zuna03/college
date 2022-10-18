#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Segregates 0’s and 1’s.
void segregate_198(int n_198, int *a_198)
{
    int start_198 = 0, end_198 = n_198 - 1;

    while (start_198 < end_198)
    {
        if (a_198[start_198] == 1 && a_198[end_198] == 0)
        {
            int temp_198 = a_198[start_198];
            a_198[start_198] = a_198[end_198];
            a_198[end_198] = temp_198;
            start_198++;
            end_198--;
        }
        if (a_198[start_198] == 0 && start_198 < end_198)
        {
            start_198++;
        }

        if (a_198[end_198] == 1 && start_198 < end_198)
        {
            end_198--;
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

    segregate_198(n_198, a_198);
    for (int i = 0; i < n_198; i++)
        printf("%d ", a_198[i]);
    return 0;
}