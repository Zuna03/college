#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node_198
{
    int data_198;
    struct node_198 *right_198;
    struct node_198 *left_198;
    bool isThreaded_198;
};

struct node_198 *newnode_198(int val)
{
    struct node_198 *nw = (struct node_198 *)malloc(sizeof(struct node_198));
    nw->data_198 = val;
    nw->left_198 = NULL;
    nw->right_198 = NULL;
    nw->isThreaded_198 = false;

    return nw;
}

struct node_198 *createTree_198(struct node_198 *root_198, int val)
{
    struct node_198 *nw = newnode_198(val);
    if (root_198 == NULL)
        root_198 = nw;
    else
    {
        if (val < root_198->data_198)
            root_198->left_198 = createTree_198(root_198->left_198, val);
        else
            root_198->right_198 = createTree_198(root_198->right_198, val);
    }
    return root_198;
}

struct node_198 **createQueue_198(int *front_198, int *rear_198)
{
    struct node_198 **queue = (struct node_198 **)malloc(sizeof(struct node_198 *));

    *front_198 = *rear_198 = 0;

    return queue;
}

// Adt function for queue to enqueue.
void enqueue_198(struct node_198 **queue, int *rear_198, struct node_198 *new_node_198)
{
    queue[*rear_198] = new_node_198;
    (*rear_198)++;
}

// Adt function for queue to dequeue.
struct node_198 *dequeue_198(struct node_198 **queue, int *front_198)
{
    (*front_198)++;
    return queue[*front_198 - 1];
}

struct node_198 *topQueue_198(struct node_198 **queue, int *front_198)
{
    return queue[*front_198];
}

void storeInQueue_198(struct node_198 *root_198, struct node_198 **queue, int *rear_198)
{
    if (root_198 == NULL)
        return;
    if (root_198->left_198)
        storeInQueue_198(root_198->left_198, queue, rear_198);
    enqueue_198(queue, rear_198, root_198);
    if (root_198->right_198)
        storeInQueue_198(root_198->right_198, queue, rear_198);
}

void createThread_198(struct node_198 *root_198, struct node_198 **queue, int *front_198, int *rear_198)
{
    if (root_198 == NULL)
        return;
    if (root_198->left_198)
        createThread_198(root_198->left_198, queue, front_198, rear_198);
    dequeue_198(queue, front_198);
    if (root_198->right_198)
        createThread_198(root_198->right_198, queue, front_198, rear_198);
    else
    {
        root_198->right_198 = topQueue_198(queue, front_198);
        root_198->isThreaded_198 = true;
    }
}

void creatwThreadedBT_198(struct node_198 *root_198)
{
    int front_198, rear_198;
    struct node_198 **queue = createQueue_198(&front_198, &rear_198);

    storeInQueue_198(root_198, queue, &rear_198);

    createThread_198(root_198, queue, &front_198, &rear_198);
}

struct node_198 *leftMost_198(struct node_198 *root_198)
{
    if (root_198 == NULL)
        return NULL;
    else
    {
        while (root_198->left_198 != NULL)
        {
            root_198 = root_198->left_198;
        }
    }
    return root_198;
}
void inorder_198(struct node_198 *root_198)
{
    struct node_198 *temp = leftMost_198(root_198);
    while (temp)
    {
        printf("%d ", temp->data_198);
        if (temp->isThreaded_198)
            temp = temp->right_198;
        else
            temp = leftMost_198(temp->right_198);
    }
}
int main()
{
    int val;
    printf("Enter the vale of the root node\n");
    scanf("%d", &val);
    struct node_198 *root_198 = newnode_198(val);

    printf("1) Add node in a binary tree\n");
    printf("2) Print inorder\n");

    int choice, value;
    int check = 1;
    while (check)
    {
        printf("Enter a choice 1/2 : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter the value you want to add : ");
            scanf("%d", &value);
            printf("\n");
            createTree_198(root_198, value);
            break;

        case 2:
            printf("The inorder_198 of the tree is : ");
            creatwThreadedBT_198(root_198);
            inorder_198(root_198);
            printf("\n");
            break;

        default:
            break;
        }

        printf("Do you want to continue 1/0 : ");
        scanf("%d", &check);
        printf("\n");

        if (check == 0)
            break;
    }
    printf("The program has been terminated successfully !\n");

    return 0;
}