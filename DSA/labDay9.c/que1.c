#include <stdio.h>
#include <stdbool.h>
#define max 100

struct queue_198
{
    int arr_198[max];
    int f, r;
};

//Function for checking if quque is empty(UNDERFLOW CONDITION)
bool isEmpty_198(struct queue_198 *q)
{
    if (q->f == -1 && q->r == -1)
        return true;
    else
        return false;
}

//Function for checking if quque is full(OVERFLOW CONDITION)
bool isFull_198(struct queue_198 *q)
{
    if (q->f == max - 1)
        return true;
    else
        return false;
}

//Function for inserting an element in queue
void insert_198(struct queue_198 *q, int n)
{
    if (isFull_198(q))
        return;

    else if (isEmpty_198(q))
    {
        q->f++;
        q->r++;
        q->arr_198[q->r] = n;
    }
    else
    {
        q->r++;
        q->arr_198[q->r] = n;
    }
}

//Function for deleting an element in queue
int delete_198(struct queue_198 *q)
{
    int t;
    if (isEmpty_198(q))
        return -1;
    else if (q->f == q->r)
    {
        t = q->arr_198[q->f];
        q->f = -1;
        q->r = -1;
    }
    else
    {
        t = q->arr_198[q->f];
        q->f++;
    }
    return t;
}

//Function for displaying queue
void display_198(struct queue_198 *q1)
{
    struct queue_198 q2;
    q2.f = -1;
    q2.r = -1;
    int t1, t2;
    while (!isEmpty_198(q1))
    {
        int t1 = delete_198(q1);
        printf("%d ", t1);
        insert_198(&q2, t1);
    }
    while (!isEmpty_198(&q2))
    {
        int t2 = delete_198(&q2);
        insert_198(q1, t2);
    }
    printf("\n");
}

//Function for reversing queue
void reverse_198(struct queue_198 *q)
{

    if (isEmpty_198(q))
        return;
    else
    {
        int t = delete_198(q);
        reverse_198(q);
        insert_198(q, t);
    }
}

//Function for copying queue
void copy_198(struct queue_198 *q1, struct queue_198 *q2)
{

    if (q1->r == -1)
        return;
    int b = delete_198(q1);
    insert_198(q2, b);
    copy_198(q1, q2);
    insert_198(q1, b);
}

//main function
int main()
{
    struct queue_198 q1;
    q1.f = -1;
    q1.r = -1;

    int t;
    display_198(&q1);

    struct queue_198 q2;
    q2.f = -1;
    q2.r = -1;

    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the queue\n");
    printf("4. Reverse the queue\n");
    printf("5. Copy the queue\n");

    int x = 1;
    int choice_198;
    int ele;
    int deleted_198;
    do
    {
        printf("Enter a choice from 1-5\n");
        scanf("%d", &choice_198);

        switch (choice_198)
        {
        case 1:
            printf("Enter the element you want to insert in queue : \n");
            scanf("%d", &ele);
            insert_198(&q1, ele);
            printf("%d is inserted successfully\n", ele);
            break;

        case 2:
            deleted_198 = delete_198(&q1);
            printf(" %d is deleted successfully\n", deleted_198);
            break;

        case 3:
            printf("The current queue is\n");
            display_198(&q1);
            break;

        case 4:
            reverse_198(&q1);
            printf("queue is reversed successfully\n");
            break;

        case 5:
            copy_198(&q1, &q2);
            printf("The copied queue is :\n");
            display_198(&q2);
            while (!isEmpty_198(&q2))
            {
                delete_198(&q2);
            }
            reverse_198(&q1);
            break;

        default:
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &choice_198);

        if (choice_198 == 0)
        {
            break;
        }
    } while (choice_198);
    printf("The program is terminated successfully.\n");

    return 0;
}