// SJF without AT

#include <stdio.h>
#define max 30

int main()
{
    int i, j, bt[max], tat[max], wt[max], n, t, p[max];
    float atat = 0, awt = 0;

    printf("Enter number of processes\n");
    scanf("%d", &n);

    printf("Enter process number\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter burst time for each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("process\t burst time\t waiting time\t turnaround time\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[i] > bt[i + 1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = 0;
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
        awt += wt[i];

        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("Average waiting time %f\n", awt);
    printf("Average trunaround time %f\n", atat);

    return 0;
}