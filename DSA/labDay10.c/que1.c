#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define max 100
struct queue_198
{
    int arr[max];
    int front_198;
    int rear_198;
};

bool isFull_198(struct queue_198 *q)
{
    if (q->front_198 == 0 && q->rear_198 == max - 1 || q->rear_198 + 1 == q->front_198)
        return true;
    else
        return false;
}

void enque_198(struct queue_198 *q, int ele)
{
    if (isFull_198(q))
        return;
    else if (q->front_198 == -1 && q->rear_198 == -1)
    {
        q->front_198 = 0;
        q->rear_198 = 0;
        q->arr[q->rear_198] = ele;
    }
    else if (q->rear_198 == max - 1)
    {
        q->rear_198 = 0;
        q->arr[q->rear_198] = ele;
    }
    else
    {
        q->rear_198++;
        q->arr[q->rear_198] = ele;
    }
}

bool isEmpty_198(struct queue_198 *q)
{
    if (q->rear_198 == -1 && q->front_198 == -1)
        return true;
    else
        return false;
}

int dequeue_198(struct queue_198 *q)
{
    int delete;
    if (isEmpty_198(q))
    {
        printf("Underflow\n");
        return -1;
    }
    else if (q->front_198 == max - 1)
    {
        delete = q->arr[q->front_198];
        q->front_198 = 0;
        return delete;
    }
    else if (q->front_198 == q->rear_198)
    {
        delete = q->arr[q->front_198];
        q->front_198 = -1;
        q->rear_198 = -1;
        return delete;
    }
    else
    {
        delete = q->arr[q->front_198];
        q->front_198++;
        return delete;
    }
}

int findMax_198(struct queue_198 *q)
{
    struct queue_198 q1;
    q1.front_198 = -1;
    q1.rear_198 = -1;
    int delete1_198;
    int delete2_198;

    int ans_198 = INT_MIN;
    while (!isEmpty_198(q))
    {
        if (q->arr[q->front_198] > ans_198)
        {
            ans_198 = q->arr[q->front_198];
        }
        else
        {
            delete1_198 = dequeue_198(q);
            enque_198(&q1, delete1_198);
        }
    }
    while (!isEmpty_198(&q1))
    {
        delete2_198 = dequeue_198(&q1);
        enque_198(q, delete2_198);
    }
    return ans_198;
}

void display_198(struct queue_198 *q)
{
    int maxNum_198 = findMax_198(q);
    int i = q->front_198;
    do
    {
        printf("%d ", q->arr[i]);
        i = (i) % maxNum_198;
        i++;
    } while (i != q->rear_198 + 1);
}
int main()
{
    struct queue_198 q;
    q.front_198 = -1;
    q.rear_198 = -1;

    printf("1) Insert an element in queue\n");
    printf("2) Delete an element from queue\n");
    printf("3) Display elements of queue\n");

    int choice_198;
    int x = 1;
    int ele_198;
    int delete;

    while (x)
    {
        printf("Enter a choice from 1-3\n");
        scanf("%d", &choice_198);

        switch (choice_198)
        {
        case 1:
            printf("Enter element you want to insert in queue\n");
            scanf("%d", &ele_198);
            enque_198(&q, ele_198);
            printf("%d is inserted successfully.\n", ele_198);
            break;

        case 2:
            delete = dequeue_198(&q);
            if (delete == -1)
                break;
            printf("The delete element is %d \n", delete);
            break;

        case 3:
            printf("The current queue is\n");
            display_198(&q);
            printf("\n");
            break;

        default:
            break;
        }
        printf("Do you want to continue ? 1/0  ");
        scanf("%d", &x);
        if (x == 0)
            break;
    }
    printf("The program is terminated successfully !!!\n");

    return 0;
}