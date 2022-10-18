#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// Capacity of queue.
#define MaxQSize_198 500

// Structure for BST's node.
struct node_198
{
    int key_198;
    struct node_198 *left_198, *right_198;
};

// Util function for inseting a new node if the BST is empty.
struct node_198 *newNode_198(int value_198)
{
    struct node_198 *temp_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    temp_198->key_198 = value_198;
    temp_198->left_198 = temp_198->right_198 = NULL;
    return temp_198;
}

// Function to insert a new element in the BST.
struct node_198 *insert_198(struct node_198 *node_198, int value_198)
{
    if (node_198 == NULL)
        return newNode_198(value_198);

    if (value_198 < node_198->key_198)
        node_198->left_198 = insert_198(node_198->left_198, value_198);
    else if (value_198 > node_198->key_198)
        node_198->right_198 = insert_198(node_198->right_198, value_198);

    return node_198;
}

// Util function to check BST or not.
bool isBSTUtil_198(struct node_198 *node_198, int min_198, int max_198)
{
    if (node_198 == NULL)
        return true;
    if (node_198->key_198 < min_198 || node_198->key_198 > max_198)
        return false;

    return isBSTUtil_198(node_198->left_198, min_198, node_198->key_198 - 1) && isBSTUtil_198(node_198->right_198, node_198->key_198 + 1, max_198);
}

// Function to check whether the BT is BST or not.
bool isBST_198(struct node_198 *node_198)
{
    return isBSTUtil_198(node_198, INT_MIN, INT_MAX);
}

// Function to traverse BST in preorder.
void preorder_198(struct node_198 *node_198)
{
    if (node_198 == NULL)
        return;
    printf("%d ", node_198->key_198);
    preorder_198(node_198->left_198);
    preorder_198(node_198->right_198);
}

// Function to traverse BST in postorder.
void postorder_198(struct node_198 *node_198)
{
    if (node_198 == NULL)
        return;
    postorder_198(node_198->left_198);
    postorder_198(node_198->right_198);
    printf("%d ", node_198->key_198);
}

// Function to traverse BST in inorder.
void inorder_198(struct node_198 *node_198)
{
    if (node_198 == NULL)
        return;
    inorder_198(node_198->left_198);
    printf("%d ", node_198->key_198);
    inorder_198(node_198->right_198);
}

// Function to check whether a node is present or not.
bool search_198(struct node_198 *node_198, int val_198)
{
    if (node_198 == NULL)
        return false;
    struct node_198 *temp_198 = node_198;

    while (temp_198 && temp_198->key_198 != val_198)
    {
        if (temp_198->key_198 == val_198)
            temp_198 = temp_198->left_198;
        else
            temp_198 = temp_198->right_198;
    }
    if (!temp_198)
        return false;
    return true;
}

// Util function to for deleting node in BST.
struct node_198 *minValueNode_198(struct node_198 *node_198)
{
    struct node_198 *current_198 = node_198;

    while (current_198 && current_198->left_198 != NULL)
        current_198 = current_198->left_198;

    return current_198;
}

// Delete a node in the BST.
struct node_198 *deleteNode_198(struct node_198 *root_198, int key_198)
{
    if (root_198 == NULL)
        return root_198;

    if (key_198 < root_198->key_198)
        root_198->left_198 = deleteNode_198(root_198->left_198, key_198);

    else if (key_198 > root_198->key_198)
        root_198->right_198 = deleteNode_198(root_198->right_198, key_198);

    else
    {
        if (root_198->left_198 == NULL)
        {
            struct node_198 *temp_198 = root_198->right_198;
            free(root_198);
            return temp_198;
        }
        else if (root_198->right_198 == NULL)
        {
            struct node_198 *temp_198 = root_198->left_198;
            free(root_198);
            return temp_198;
        }

        struct node_198 *temp_198 = minValueNode_198(root_198->right_198);

        root_198->key_198 = temp_198->key_198;

        root_198->right_198 = deleteNode_198(root_198->right_198, temp_198->key_198);
    }
    return root_198;
}

// stack ADT.
struct stack_198
{
    struct node_198 *data_198;
    struct stack_198 *next_198;
};

// Adt function for stack to push.
void pushStack_198(struct stack_198 **st_198, struct node_198 *val_198)
{
    struct stack_198 *temp_198 = (struct stack_198 *)malloc(sizeof(struct stack_198));
    temp_198->data_198 = val_198;
    temp_198->next_198 = *st_198;
    *st_198 = temp_198;
}

// Adt function for stack to check whether stack is empty or not.
int isEmptyS_198(struct stack_198 *st_198)
{
    return !st_198;
}

// Adt function for stack to pop.
struct node_198 *popStack_198(struct stack_198 **st_198)
{
    if (isEmptyS_198(*st_198))
    {
        printf("Empty stack\n");
        return NULL;
    }
    struct stack_198 *temp_198 = *st_198;
    *st_198 = (*st_198)->next_198;
    struct node_198 *popped_198 = temp_198->data_198;
    free(temp_198);
    return popped_198;
}

// Function to print in preorder format with iteration.
void preorderItr_198(struct node_198 *root_198)

{
    if (!root_198)
        return;
    struct stack_198 *st_198 = NULL;
    pushStack_198(&st_198, root_198);

    while (!isEmptyS_198(st_198))
    {
        root_198 = popStack_198(&st_198);
        printf("%d ", root_198->key_198);
        if (root_198->right_198)
            pushStack_198(&st_198, root_198->right_198);
        if (root_198->left_198)
            pushStack_198(&st_198, root_198->left_198);
    }
}

// Adt function for queue to create a queue.
struct node_198 **createQueue_198(int *front_198, int *rear_198)
{
    struct node_198 **queue_198 = (struct node_198 **)malloc(sizeof(struct node_198 *) * MaxQSize_198);

    *front_198 = *rear_198 = 0;

    return queue_198;
}

// Adt function for queue to enqueue.
void enQueue_198(struct node_198 **queue_198, int *rear_198, struct node_198 *new_node)
{
    queue_198[*rear_198] = new_node;
    (*rear_198)++;
}

// Adt function for queue to dequeue.
struct node_198 *deQueue_198(struct node_198 **queue_198, int *front_198)
{
    (*front_198)++;
    return queue_198[*front_198 - 1];
}

// Function to traverse in level order.
void levelOrder_198(struct node_198 *root_198)
{
    int rear_198, front_198;
    struct node_198 **queue_198 = createQueue_198(&front_198, &rear_198);
    struct node_198 *temp_node = root_198;

    while (temp_node)
    {
        printf("%d ", temp_node->key_198);

        if (temp_node->left_198)
            enQueue_198(queue_198, &rear_198, temp_node->left_198);

        if (temp_node->right_198)
            enQueue_198(queue_198, &rear_198, temp_node->right_198);

        temp_node = deQueue_198(queue_198, &front_198);
    }
}

// Main Function.
int main()
{
    struct node_198 *root_198 = NULL;
    int item_198;

    printf("Enter the value_198 :- ");
    scanf("%d", &item_198);

    root_198 = insert_198(root_198, item_198);

    int check_198 = 1;

    while (check_198)
    {
        int z_198;
        printf("\n========================================================\n");
        printf("1) Insert a node.\n");
        printf("2) Check BST.\n");
        printf("3) Traverse preorder.\n");
        printf("4) Traverse preorder without recursion.\n");
        printf("5) Traverse postorder.\n");
        printf("6) Traverse inorder.\n");
        printf("7) Traverse in level order.\n");
        printf("8) Search for a node.\n");
        printf("9) Delete a node.\n");
        printf("10) QUIT!!.\n");
        printf("\n========================================================\n");

        printf("Enter your choice :- ");
        scanf("%d", &z_198);

        struct node_198 *temp_198 = root_198;

        switch (z_198)
        {
        case 1:
            printf("Enter the value :- ");
            scanf("%d", &item_198);
            insert_198(root_198, item_198);
            break;
        case 2:
            if (isBST_198(root_198))
                printf("It is a BST.\n");
            else
                printf("It is not a BST.\n");
            break;
        case 3:
            printf("The tree in preorder :- ");
            preorder_198(root_198);
            printf("\n");
            break;
        case 4:
            printf("The tree in preorder :- ");
            preorderItr_198(root_198);
            printf("\n");
            break;
        case 5:
            printf("The tree in postorder :- ");
            postorder_198(root_198);
            printf("\n");
            break;
        case 6:
            printf("The tree in inorder :- ");
            inorder_198(root_198);
            printf("\n");
            break;
        case 7:
            printf("The tree in level order :- ");
            levelOrder_198(root_198);
            printf("\n");
            break;
        case 8:
            printf("Enter the value :- ");
            scanf("%d", &item_198);
            if (search_198(root_198, item_198))
                printf("Element found!!\n");
            else
                printf("Element not found!!\n");
            break;
        case 9:
            printf("Enter the value :- ");
            scanf("%d", &item_198);
            root_198 = deleteNode_198(root_198, item_198);
            break;
        case 10:
            check_198 = 0;
            printf("Program terminated!!\n");
            break;
        default:
            printf("Invalid Choice !!\n");
            break;
        }
    }

    printf("\n========================================================\n");

    printf("Program exited successfully!!\n");

    return 0;
}