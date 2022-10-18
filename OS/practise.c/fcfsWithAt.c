// FCFS with AT

#include <stdio.h>
#define max 30

int main()
{
    int i, j, bt[max],at[max], tat[max], wt[max], n,temp[max];
    float atat = 0, awt = 0;

    printf("Enter number of processes\n");
    scanf("%d", &n);

    printf("Enter burst time for each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter arrival time for each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("process\t burst time\t arrival time\t waiting time\t turnaround time\n");

    temp[0]=0;
    for (i = 0; i < n; i++)
    {
        tat[i] = 0;
        wt[i] = 0;
        
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];

        tat[i] = wt[i] + bt[i];
        atat += tat[i];
        awt += wt[i];

        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i],at[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("Average waiting time %f\n", awt);
    printf("Average trunaround time %f\n", atat);

    return 0;
}