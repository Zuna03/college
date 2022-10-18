#include <stdio.h>
#include <stdlib.h>
#define N 20 //defining the size of queue
int s[N], top_198 = -1;

int pop_198() //function to remove an element from stack
{
    return s[top_198--];
}
void push_198(int x) //function to insert an element into stack
{
    if (top_198 == N - 1)
        printf("Stack is Full");
    else
    {
        top_198++;
        s[top_198] = x;
    }
}
void enqueue_198(int x) //function to insert element in the queue using recursive stack call
{
    push_198(x);
}
void print_198() //function to print elements of a queue
{
    int i;
    for (i = 0; i <= top_198; i++)
        printf("%d  ", s[i]);
}

int dequeue_198() //function to dequeue element from a queue using recursive stack call
{
    int data, res;
    if (top_198 == -1)
        printf("Queue is Empty");
    else if (top_198 == 0)
        return pop_198();
    data = pop_198();
    res = dequeue_198();
    push_198(data);
    return res;
}
int main()
{
    int opt, data, t;

    printf("1) To Insert the Data in Queue\n");
    printf("2) To Delete the data from the Queue\n");
    printf("3) To show the Data in Queue \n");

    int x = 1;

    while (x)
    {
        printf("Enter Your Choice from 1-3:-\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter your data need to be inserted\n");
            scanf("%d", &data);
            push_198(data);
            break;
        case 2:
            t = dequeue_198();
            printf("dequeued element:%d\n", t);

            break;
        case 3:
            printf("The current queue is\n");
            print_198();
            printf("\n");
            break;

        default:
            printf("Incorrect Choice");
        }

        printf("Do you want to continue ? 1/0  ");
        scanf("%d", &x);
        if (x == 0)
            break;
    }
    printf("The program is terminated successfully !!!\n");
    return 0;
}