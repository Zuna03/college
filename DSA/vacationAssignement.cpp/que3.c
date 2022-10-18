#include <conio.h>

#include <stdio.h>

#include <stdlib.h>

int cqueue3[2];
int cqueue[2];
int cqueue2[2];
int front2 = -1, rear2 = -1;
int front3 = -1, rear3 = -1;
int front = -1, rear = -1, n = 2;

void enqueue(int val)
{

    if ((front == 0 && rear == n - 1) || front == rear + 1)
    {

        printf("Queue1 Overflow \n");

        if ((front2 == 0 && rear2 == n - 1) || (front2 == rear2 + 1))
        {

            printf("Queue 2 overflow \n");

            if ((front3 == 0 && rear3 == n - 1) || (front3 == rear3 + 1))
            {

                printf("Queue 3 overflow \n");

                return;
            }

            if (front3 == -1 && rear3 == -1)
            {

                front3 = 0;

                rear3 = 0;
            }

            else
            {

                if (rear3 == n - 1)

                    rear3 = 0;

                else

                    rear3 = rear3 + 1;
            }

            cqueue3[rear3] = val;

            return;
        }

        if (front2 == -1 && rear2 == -1)
        {

            front2 = 0;

            rear2 = 0;
        }

        else
        {

            if (rear2 == n - 1)

                rear2 = 0;

            else

                rear2 = rear2 + 1;
        }

        cqueue2[rear2] = val;

        return;
    }

    if (front == -1 && rear == -1)
    {

        front = 0;

        rear = 0;
    }

    else
    {

        if (rear == n - 1)

            rear = 0;

        else

            rear = rear + 1;
    }

    cqueue[rear] = val;
}

void dequeue()
{

    if (front == -1 && rear == -1)
    {

        printf("Queue Underflow\n"); //this means all three queue are empty

        return;
    }

    printf("Element deleted from queue is : %d ", cqueue[front]);

    if (front == rear) //only one person is there in the first queue
    {

        front = -1;

        rear = -1;
    }

    else
    {

        if (front == n - 1)
        {
            if (front2 != -1 && rear2 != -1) //conditions to shift person from second queue to first
            {
                cqueue[++rear] = cqueue2[front2];
                if (front2 == n - 1 && front2 != rear2)
                    front2 = 0;
                else if (front2 == rear2)
                    front2 = rear2 = -1;
                else
                    front2++;
                if (front3 != -1 && rear3 != -1)
                {
                    if (front2 == -1 && rear2 == -1)
                    {

                        front2 = 0;

                        rear2 = 0;
                    }

                    else
                    {

                        if (rear2 == n - 1)

                            rear2 = 0;

                        else

                            rear2 = rear2 + 1;
                    }

                    cqueue2[rear2] = cqueue3[front3];
                    if (front3 == n - 1 && front3 != rear3)
                        front3 = 0;
                    else if (front3 == rear3)
                        front3 = rear3 = -1;
                    else
                        front3++;
                }
            }
            front = 0;
        }

        else if (front == 0 && rear == n - 1)
        {
            if (front2 != -1 && rear2 != -1)
            {
                rear = 0;
                cqueue[rear] = cqueue2[front2];
                if (front2 == n - 1 && front2 != rear2)
                    front2 = 0;
                else if (front2 == rear2)
                    front2 = rear2 = -1;
                else
                    front2++;
                if (front3 != -1 && rear3 != -1) //conditions to shift person from third queue to second
                {

                    if (front2 == -1 && rear2 == -1)
                    {

                        front2 = 0;

                        rear2 = 0;
                    }

                    else
                    {

                        if (rear2 == n - 1)

                            rear2 = 0;

                        else

                            rear2 = rear2 + 1;
                    }
                    cqueue2[rear2] = cqueue3[front3];
                    if (front3 == n - 1 && front3 != rear3)
                        front3 = 0;
                    else if (front3 == rear3)
                        front3 = rear3 = -1;
                    else
                        front3++;
                }
            }
            front++;
        }

        else
        {
            if (front2 != -1 && rear2 != -1)
            {
                cqueue[++rear] = cqueue2[front2];
                if (front2 == n - 1 && front2 != rear2)
                    front2 = 0;
                else if (front2 == rear2)
                    front2 = rear2 = -1;
                else
                    front2++;
                if (front3 != -1 && rear3 != -1) //conditions to shift person from third queue to second
                {

                    if (front2 == -1 && rear2 == -1)
                    {

                        front2 = 0;

                        rear2 = 0;
                    }

                    else
                    {

                        if (rear2 == n - 1)

                            rear2 = 0;

                        else

                            rear2 = rear2 + 1;
                    }
                    cqueue2[rear2] = cqueue3[front3];
                    if (front3 == n - 1 && front3 != rear3)
                        front3 = 0;
                    else if (front3 == rear3)
                        front3 = rear3 = -1;
                    else
                        front3++;
                }
            }
            front++;
        }
    }
}

void display()
{

    int f = front, r = rear, i;

    if (front == -1)
    {

        printf("Queue 1 is empty\n");
    }
    else
    {
        printf("\nQueue 1 elements are :\n");

        if (r >= f)
        {
            for (i = f; i <= r; i++)
                printf("%d\n", cqueue[i]);
        }
        else
        {
            for (i = f; i < n; i++)
                printf("%d\n", cqueue[i]);
            for (i = 0; i <= r; i++)
                printf("%d\n", cqueue[i]);
        }
    }

    f = front2, r = rear2;
    if (f == -1)
    {

        printf("Queue 2 is empty\n");
    }

    else
    {
        printf("\nQueue 2 elements are :\n");

        if (r >= f)
        {
            for (i = f; i <= r; i++)
                printf("%d\n", cqueue2[i]);
        }
        else
        {
            for (i = f; i < n; i++)
                printf("%d\n", cqueue2[i]);
            for (i = 0; i <= r; i++)
                printf("%d\n", cqueue2[i]);
        }
    }

    f = front3, r = rear3;

    if (f == -1)
    {

        printf("Queue 3 is empty\n");
    }

    else
    {
        printf("\nQueue 3 elements are :\n");

        if (r >= f)
        {
            for (i = f; i <= r; i++)
                printf("%d\n", cqueue3[i]);
        }
        else
        {
            for (i = f; i < n; i++)
                printf("%d\n", cqueue3[i]);
            for (i = 0; i <= r; i++)
                printf("%d\n", cqueue3[i]);
        }
    }
}

int menu()
{

    int choice;

    printf("\n 1.Add person to the queue");

    printf("\n 2. Move person to the vaccination center from queue");

    printf("\n 3. View queue");

    printf("\n 4. exit");

    printf("\n Please enter your choice: \t");

    scanf("%d", &choice);

    return (choice);
}
void main()
{
    int value;

    while (1)
    {

        switch (menu())
        {

        case 1:

            printf("Input for insertion: ");

            scanf("%d", &value);

            enqueue(value);

            break;

        case 2:

            dequeue();

            break;

        case 3:

            display();

            break;

        case 4:

            exit(0);

        default:

            printf("invalid choice");
        }
    }
}
