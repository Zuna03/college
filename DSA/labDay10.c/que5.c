#include <stdio.h>
#define N 20
int Q[N], Pr[N];
int r = -1, f = -1;
void enqueue_198(int data, int p) //Enqueue function to insert data and its priority in queue
{
    int i;
    if ((f == 0) && (r == N - 1)) //Check if Queue is full
        printf("Queue is full");
    else
    {
        if (f == -1) //if Queue is empty
        {
            f = r = 0;
            Q[r] = data;
            Pr[r] = p;
        }
        else if (r == N - 1) //if there there is some elemets in Queue
        {
            for (i = f; i <= r; i++)
            {
                Q[i - f] = Q[i];
                Pr[i - f] = Pr[i];
                r = r - f;
                f = 0;
                for (i = r; i > f; i--)
                {
                    if (p > Pr[i])
                    {
                        Q[i + 1] = Q[i];
                        Pr[i + 1] = Pr[i];
                    }
                    else
                        break;
                    Q[i + 1] = data;
                    Pr[i + 1] = p;
                    r++;
                }
            }
        }
        else
        {
            for (i = r; i >= f; i--)
            {
                if (p > Pr[i])
                {
                    Q[i + 1] = Q[i];
                    Pr[i + 1] = Pr[i];
                }
                else
                    break;
            }
            Q[i + 1] = data;
            Pr[i + 1] = p;
            r++;
        }
    }
}
void print_198() //print the data of Queue
{
    int i;
    for (i = f; i <= r; i++)
    {
        printf("\nElement = %d\tPriority = %d", Q[i], Pr[i]);
    }
}
int dequeue_198() //remove the data from front
{
    if (f == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("deleted Element = %d\t Its Priority = %d", Q[f], Pr[f]);
        if (f == r)
            f = r = -1;
        else
            f++;
    }
}
int main()
{
    int opt_198, n, i, data_198, p;
    printf("Enter Your Choice:-");
    do
    {
        printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit");
        scanf("%d", &opt_198);
        switch (opt_198)
        {
        case 1:
            printf("\nEnter the number of data");
            scanf("%d", &n);
            printf("\nEnter your data and Priority of data");
            i = 0;
            while (i < n)
            {
                scanf("%d %d", &data_198, &p);
                enqueue_198(data_198, p);
                i++;
            }
            break;
        case 2:
            print_198();
            break;
        case 3:
            dequeue_198();
            break;
        case 0:
            break;
        default:
            printf("\nIncorrect Choice");
        }
    } while (opt_198 != 0);
    return 0;
}