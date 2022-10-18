// PRIORITY SCHEDULING(NON-PREMPTIVE ie without AT) 

#include <stdio.h>
#define max 30

int main()
{
    int i, j, bt[max], tat[max], wt[max], n,pr[max],pos,t;
    float atat = 0, awt = 0;

    printf("Enter number of processes\n");
    scanf("%d", &n);

    printf("Enter burst time for each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter priority for each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

    printf("process\t burst time\t waiting time\t turnaround time\n");

    for ( i = 0; i < n; i++)
    {
        pos=i;
        for ( j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
               pos=j;
        }
        t=pr[i];
        pr[i]=pr[i+1];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[i+1];
        bt[pos]=t;

        
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

        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("Average waiting time %f\n", awt);
    printf("Average trunaround time %f\n", atat);

    return 0;
}