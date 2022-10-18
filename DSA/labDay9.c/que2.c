#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct qnode_198
{
    int data_198;
    struct qnode_198 *next_198;
};
struct queue_198
{
    struct qnode_198 *f;
    struct qnode_198 *r;
};

struct qnode_198 *createNode_198(int n)
{
    struct qnode_198 *new_198 = (struct qnode_198 *)malloc(sizeof(struct qnode_198));
    new_198->data_198 = n;
    new_198->next_198 = NULL;

    return new_198;
}

struct queue_198 *createQueue_198()
{
    struct queue_198 *new_198 = (struct queue_198 *)malloc(sizeof(struct queue_198));
    new_198->f = NULL;
    new_198->r = NULL;
}

bool isEmpty_198(struct queue_198 *q)
{
    if (q->f == NULL && q->r == NULL)
        return true;
    else
        return false;
}

void insert_198(struct queue_198 *q, int n)
{
    struct qnode_198 *temp = createNode_198(n);

    if (isEmpty_198(q))
    {
        q->f = temp;
        q->r = temp;
        return;
    }
    else
    {
        q->r->next_198 = temp;
        q->r = temp;
        return;
    }
}

int delete_198(struct queue_198 *q)
{
    if (isEmpty_198(q))
        return -1;

    struct qnode_198 *todelete_198 = q->f;
    q->f = q->f->next_198;

    if (q->f == NULL)
        q->r = NULL;

    int delete_198d = todelete_198->data_198;
    free(todelete_198);

    return delete_198d;
}

void display_198(struct queue_198 *q1)
{
    struct queue_198 *q2 = createQueue_198();
    int t1, t2;
    while (!isEmpty_198(q1))
    {
        t1 = delete_198(q1);
        printf("%d ", t1);
        insert_198(q2, t1);
    }
    printf("\n");
    while (!isEmpty_198(q2))
    {
        t2 = delete_198(q2);
        insert_198(q1, t2);
    }
    printf("\n");
}

int main()
{
    struct queue_198 *q = createQueue_198();

    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the queue\n");

    int x_198;
    int choice_198;
    int ele;
    int deleted_198;
    do
    {
        printf("Enter a choice from 1-3\n");
        scanf("%d", &choice_198);

        switch (choice_198)
        {
        case 1:
            printf("Enter the element you want to insert_198 in queue_198 : \n");
            scanf("%d", &ele);
            insert_198(q, ele);
            printf("%d is inserted successfully\n", ele);
            break;

        case 2:
            deleted_198 = delete_198(q);
            printf("%d is deleted successfully\n", deleted_198);
            break;

        case 3:
            printf("The current queue is\n");
            display_198(q);
            break;

        default:
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &x_198);

        if (x_198 == 0)
        {
            break;
        }
    } while (x_198);
    printf("The program is terminated successfully.\n");

    return 0;
}