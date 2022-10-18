#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int deque_arr[MAX];
int front = -1;
int rear = -1;

int isComplete()
{
        if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
                return 1;
        else
                return 0;
}

int isEmpty()
{
        if (front == -1)
                return 1;
        else
                return 0;
}

void insertInFront(int deleted)
{
        if (isComplete())
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if (front == -1)
        {
                front = 0;
                rear = 0;
        }
        else if (front == 0)
                front = MAX - 1;
        else
                front = front - 1;
        deque_arr[front] = deleted;
}
void insertAtEnd(int deleted)
{
        if (isComplete())
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if (front == -1)
        {
                front = 0;
                rear = 0;
        }
        else if (rear == MAX - 1)
                rear = 0;
        else
                rear = rear + 1;
        deque_arr[rear] = deleted;
}

int deleteFromEnd()
{
        int deleted;
        if (isEmpty())
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        deleted = deque_arr[front];
        if (front == rear)
        {
                front = -1;
                rear = -1;
        }
        else if (front == MAX - 1)
                front = 0;
        else
                front = front + 1;
        return deleted;
}

int deleteFromRear()
{
        int deleted;
        if (isEmpty())
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        deleted = deque_arr[rear];

        if (front == rear)
        {
                front = -1;
                rear = -1;
        }
        else if (rear == 0)
                rear = MAX - 1;
        else
                rear = rear - 1;
        return deleted;
}

void display()
{
        int i;
        if (isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue elements :\n");
        i = front;
        if (front <= rear)
        {
                while (i <= rear)
                        printf("%d ", deque_arr[i++]);
        }
        else
        {
                while (i <= MAX - 1)
                        printf("%d ", deque_arr[i++]);
                i = 0;
                while (i <= rear)
                        printf("%d ", deque_arr[i++]);
        }
        printf("\n");
}

int main()
{
        int choice, deleted;
        while (1)
        {
                printf("\n\n1.Insert at the front end\n");
                printf("2.Insert at the rear end\n");
                printf("3.Delete from front end\n");
                printf("4.Delete from rear end\n");
                printf("5.Display\n");
                printf("6.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        printf("\nInput the element you want to add in queue : ");
                        scanf("%d", &deleted);
                        insertInFront(deleted);
                        break;
                case 2:
                        printf("\nInput the element you want to add in queue : ");
                        scanf("%d", &deleted);
                        insertAtEnd(deleted);
                        break;
                case 3:
                        printf("\nElement deleted from front end is : %d\n", deleteFromEnd());
                        break;
                case 4:
                        printf("\nElement deleted from rear end is : %d\n", deleteFromRear());
                        break;
                case 5:
                        display();
                        break;
                case 6:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
                printf("\nfront = %d, rear =%d\n", front, rear);
                display();
        }
        return 0;
}
