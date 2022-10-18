#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int key_198;
    struct node_198 *left_198, *right_198;
};

// func to make new node
struct node_198 *newnode_198(int item_198)
{
    struct node_198 *temp_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    temp_198->key_198 = item_198;
    temp_198->left_198 = temp_198->right_198 = NULL;
    return temp_198;
}

// func for inorder traversal of tree
void inorder_198(struct node_198 *root_198)
{
    if (root_198 != NULL)
    {
        inorder_198(root_198->left_198);
        printf("%d \n", root_198->key_198);
        inorder_198(root_198->right_198);
    }
}

// func to iunsert new element in tree
struct node_198 *insert_198(struct node_198 *root_198, int key_198)
{
    struct node_198 *new, *parent_198, *ptr_198;
    new = newnode_198(key_198);
    if (root_198 == NULL)
        root_198 = new;
    else
    {
        ptr_198 = root_198;
        parent_198 = NULL;
        while (ptr_198 != NULL)
        {
            parent_198 = ptr_198;
            if (key_198 < ptr_198->key_198)
                ptr_198 = ptr_198->left_198;
            else
                ptr_198 = ptr_198->right_198;
        }
    }
    if (key_198 < parent_198->key_198)
        parent_198->left_198 = new;
    else
        parent_198->right_198 = new;
    return root_198;
}

// func to calculate height of tree
int calcHeight_198(struct node_198 *root_198)
{
    if (root_198 == NULL)
        return -1;

    int lHeight_198 = calcHeight_198(root_198->left_198);
    int rHeight_198 = calcHeight_198(root_198->right_198);

    if (lHeight_198 > rHeight_198)
        return lHeight_198 + 1;
    else
        return rHeight_198 + 1;
}

// func to count nodes with degree 0
int count0Degree_198(struct node_198 *root_198)
{
    static int count_198 = 0;
    if (root_198 == NULL)
        return 0;

    if (root_198->left_198 == NULL && root_198->right_198 == NULL)
        count_198++;

    count0Degree_198(root_198->left_198);
    count0Degree_198(root_198->right_198);

    return count_198;
}

// func to count nodes with degree 1
int count1Degree_198(struct node_198 *root_198)
{
    static int count_198 = 0;
    if (root_198 == NULL)
        return 0;

    if (root_198->left_198 == NULL && root_198->right_198 != NULL || root_198->right_198 == NULL && root_198->left_198 != NULL)
        count_198++;

    count1Degree_198(root_198->left_198);
    count1Degree_198(root_198->right_198);

    return count_198;
}

// func to count nodes with degree 2
int count2Degree_198(struct node_198 *root_198)
{
    static int count_198 = 0;
    if (root_198 == NULL)
        return 0;

    if (root_198->left_198 != NULL && root_198->right_198 != NULL)
        count_198++;

    count2Degree_198(root_198->left_198);
    count2Degree_198(root_198->right_198);

    return count_198;
}

// func to create queue
struct node_198 **createQueue_198(int *front_198, int *rear_198)
{
    struct node_198 **queue = (struct node_198 **)malloc(sizeof(struct node_198 *));

    *front_198 = *rear_198 = 0;
    return queue;
}

// func to insert elements in queue
void enqueue_198(struct node_198 **queue, int *rear_198, struct node_198 *new_node)
{
    queue[*rear_198] = new_node;
    (*rear_198)++;
}

// func to pop elements from queue
struct node_198 *dequeue_198(struct node_198 **queue, int *front_198)
{
    (*front_198)++;
    return queue[*front_198 - 1];
}

// func to check if queue is empty
bool isQueueEmpty_198(int *front_198, int *rear_198)
{
    return (*rear_198 == *front_198);
}

// func to check whether tree is complete BT or not
bool isCompleteBT(struct node_198 *root)
{

    if (root == NULL)
        return true;

    int rear_198, front_198;
    struct node_198 **queue = createQueue_198(&front_198, &rear_198);

    bool flag_198 = false;

    // Do level order traversal using queue.
    enqueue_198(queue, &rear_198, root);
    while (!isQueueEmpty_198(&front_198, &rear_198))
    {
        struct node_198 *temp = dequeue_198(queue, &front_198);

        if (temp->left_198)
        {
            if (flag_198 == true)
                return false;

            enqueue_198(queue, &rear_198, temp->left_198);
        }
        else
            flag_198 = true;

        if (temp->right_198)
        {

            if (flag_198 == true)
                return false;

            enqueue_198(queue, &rear_198, temp->right_198); // enqueue_198 Right Child
        }
        else
            flag_198 = true;
    }

    return true;
}

int right_subtree(struct node_198 *pt)
{
    static int count2 = 0;
    //  static int count2 = 0;
    if (pt != NULL)
    {
        count2++;
        right_subtree(pt->left_198);
        right_subtree(pt->right_198);
    }

    return count2;
}

int left_subtree(struct node_198 *ptr)
{
    static int count1 = 0;
    //   static int count2 = 0;
    if (ptr != NULL)
    {
        count1++;
        left_subtree(ptr->left_198);
        left_subtree(ptr->right_198);
    }

    return count1;
}

void check(struct node_198 *root)
{
    int ltree_elements;
    int rtree_elements;

    if (root == NULL || root->left_198 == NULL || root->right_198 == NULL)
    {
        return;
    }
    else
    {
        ltree_elements = left_subtree(root->left_198);
        rtree_elements = right_subtree(root->right_198);
    }

    if (ltree_elements == rtree_elements)
    {
        printf("\n\nYes , it is a fully complete binary tree.");
    }
    else
    {
        printf("\n\nNo , not a fully complete binary tree.");
    }
}

int main()
{
    int val_198;
    printf("Enter the value of the root\n");
    scanf("%d", &val_198);
    struct node_198 *root_198 = newnode_198(val_198);

    printf("1. Insert a node in BST.\n");
    printf("2. Find height of tree.\n");
    printf("3. Check whether the tree is a fully complete binary tree or not.\n");
    printf("4. Count the number of nodes with degree 0, 1 and 2.\n");
    printf("5. Print Inorder of BST\n");

    int choice_198, height_198, deg0_198, deg1_198, deg2_198;
    int cont_198 = 1;

    while (cont_198)
    {
        printf("Enter a choice from 1-5\n");
        scanf("%d", &choice_198);

        switch (choice_198)
        {
        case 1:
            printf("Enter the value of the node.\n");
            scanf("%d", &val_198);
            insert_198(root_198, val_198);
            break;

        case 2:
            height_198 = calcHeight_198(root_198);
            printf("The height of the tree is : %d \n", height_198);
            break;

        case 3:
            if (isCompleteBT(root_198))
                printf("Yes the tree is Complete BT.\n");
            else
                printf("No the tree is not Complete BT.\n");
            break;

        case 4:
            deg0_198 = count0Degree_198(root_198);
            printf("The number of nodes with degree 0 : %d\n", deg0_198);
            deg1_198 = count1Degree_198(root_198);
            printf("The number of nodes with degree 1 : %d\n", deg1_198);
            deg2_198 = count2Degree_198(root_198);
            printf("The number of nodes with degree 2 : %d\n", deg2_198);
            break;

        case 5:
            printf("The inorder sequence of BST is :\n");
            inorder_198(root_198);
            break;

        default:
            break;
        }

        printf("Do you want to continue? 1/0\n");
        scanf("%d", &cont_198);

        if (cont_198 == 0)
            break;
    }

    printf("The program is terminated !\n");

    return 0;
}
