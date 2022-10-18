#include <stdio.h>
#include <conio.h>
#define max 30
void main()
{
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max];
    float awt = 0, atat = 0;
    printf("Enter the no of process\n");
    scanf("%d", &n);
    printf("Enter the burst time of the process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter the arrival time of the process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    temp[0] = 0;
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("process: %d burst time %d arrival time %d waiting time %d turn around time %d \n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("average waiting time = %f\n", awt);
    printf("average turn around time = %f\n", atat);
}