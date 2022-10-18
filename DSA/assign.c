
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// Capacity of queue.
#define MaxQSize 500

// Structure for BST's node.
struct node
{
    char *atm_name;
    char *bank_name;
    int atm_id;
    char *location;
    char *city;
    int cash;
    struct node *left, *right;
};

// Util function for inseting a new node if the BST is empty.
struct node *newNode(char *an, char *bn, int ai, char *loca, char *ci, int ca)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->atm_name, an);
    strcpy(temp->bank_name, bn);
    temp->atm_id = ai;
    strcpy(temp->location, loca);
    strcpy(temp->city, ci);
    temp->cash = ca;
    temp->left = temp->right = NULL;
    return temp;
}

bool isUnique(struct node *node, int ai)
{
    if (node == NULL)
        return true;
    if (ai == node->atm_id)
        return false;
    isUnique(node->left, ai);
    isUnique(node->right, ai);

    return true;
}
// Function to insert a new element in the BST.
struct node *insert(struct node *node, char *an, char *bn, int ai, char *loca, char *ci, int ca)
{
    if (isUnique(node, ai))
    {
        if (node == NULL)
            return newNode(an, bn, ai, loca, ci, ca);

        if (ai < node->atm_id)
            node->left = insert(node->left, an, bn, ai, loca, ci, ca);
        else if (ai > node->atm_id)
            node->right = insert(node->right, an, bn, ai, loca, ci, ca);

        return node;
    }
    else
        return NULL;
}

// Function to traverse BST in preorder.
void preorder(struct node *node, char *bankName)
{
    if (node == NULL)
        return;
    if (bankName == node->bank_name)
    {
        printf("ATM Machine Name : %c\d", node->atm_name);
        printf("Bank Name : %c\d", node->bank_name);
        printf("ATM Id : %d\d", node->atm_id);
        printf("ATM Location : %c\d", node->location);
        printf("ATM City : %c\d", node->city);
        printf("ATM Cash : %d\d", node->cash);
    }
    preorder(node->left, bankName);
    preorder(node->right, bankName);
}

void low_cash(struct node *node)
{
    if (node == NULL)
        return;
    if (node->cash <= 100000)
    {
        printf("ATM Machine Name : %c\d", node->atm_name);
        printf("Bank Name : %c\d", node->bank_name);
        printf("ATM Id : %d\d", node->atm_id);
        printf("ATM Location : %c\d", node->location);
        printf("ATM City : %c\d", node->city);
        printf("ATM Cash : %d\d", node->cash);
    }
    low_cash(node->left);
    low_cash(node->right);
}

// Adt function for queue to create a queue.
struct node **createQueue(int *front, int *rear)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *) * MaxQSize);

    *front = *rear = 0;

    return queue;
}

// Adt function for queue to enqueue.
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

// Adt function for queue to dequeue.
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

// Function to traverse in level order.
void levelOrder(struct node *root, char *bankName)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;

    while (temp_node)
    {

        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        temp_node = deQueue(queue, &front);
        if (temp_node->bank_name == bankName)
        {
            printf("ATM Machine Name : %c\d", root->atm_name);
            printf("Bank Name : %c\d", root->bank_name);
            printf("ATM Id : %d\d", root->atm_id);
            printf("ATM Location : %c\d", root->location);
            printf("ATM City : %c\d", root->city);
            printf("ATM Cash : %d\d", root->cash);
            break;
        }
    }
}

void update_cash(struct node *node, int ai, int amt)
{
    if (node == NULL)
        return;
    if (node->atm_id == ai)
    {
        if (node->cash < amt)
            printf("Low cash\n");
        else
        {
            node->cash -= amt;
            printf("ATM Balance Left :%d\n", node->cash);
        }
    }
    update_cash(node->left, ai, amt);
    update_cash(node->right, ai, amt);
}

void lowestCash_root(struct node *root)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;

    while (temp_node)
    {

        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        temp_node = deQueue(queue, &front);
        if (temp_node->cash <= 100000)
        {
            printf("ATM Machine Name : %c\d", root->atm_name);
            printf("Bank Name : %c\d", root->bank_name);
            printf("ATM Id : %d\d", root->atm_id);
            printf("ATM Location : %c\d", root->location);
            printf("ATM City : %c\d", root->city);
            printf("ATM Cash : %d\d", root->cash);
            break;
        }
    }
}

// Main Function.
int main()
{
    struct node *root = NULL;
    char *an;
    char *bn;
    int ai;
    char *loca;
    char *ci;
    int ca;

    printf("Enter the ATM Machine Name :- ");
    scanf("%c", &an);

    printf("Enter the Bank Name :- ");
    scanf("%c", &bn);

    printf("Enter the ATM Id :- ");
    scanf("%d", &ai);

    printf("Enter the ATM Location :- ");
    scanf("%c", &loca);

    printf("Enter the ATM city :- ");
    scanf("%c", &ci);

    printf("Enter the ATM cash:- ");
    scanf("%d", &ca);

    root = insert(root, an, bn, ai, loca, ci, ca);

    int check = 1;
    char *an1;
    char *bn1;
    int ai1;
    char *loca1;
    char *ci1;
    int ca1;
    char *bankName;
    int cash2;
    int ai2;
    while (check)
    {
        int z;
        printf("\n========================================================\n");
        printf("1) Insert a node.\n");
        printf("2) Traverse preorder and print.\n");
        printf("3) Print atm detail with low cash.\n");
        printf("4) Nearest ATM for given bank.\n");
        printf("5) Update cash.\n");
        printf("6) Nearest atm detail with low cash.\n");
        printf("7) QUIT!!.\n");
        printf("\n========================================================\n");

        printf("Enter your choice :- ");
        scanf("%d", &z);

        struct node *temp = root;

        switch (z)
        {
        case 1:
            printf("Enter the ATM Machine Name :- ");
            scanf("%c", &an1);

            printf("Enter the Bank Name :- ");
            scanf("%c", &bn1);

            printf("Enter the ATM Id :- ");
            scanf("%d", &ai1);

            printf("Enter the ATM Location :- ");
            scanf("%c", &loca1);

            printf("Enter the ATM city :- ");
            scanf("%c", &ci1);

            printf("Enter the ATM cash:- ");
            scanf("%d", &ca1);

            insert(root, an1, bn1, ai1, loca1, ci1, ca1);
            break;
        case 2:
            printf("Enter the bank name of which detials need to nbe displayed\n");
            scanf("%c", &bankName);
            preorder(root, bankName);
            break;
        case 3:
            low_cash(root);
            printf("\n");
            break;
        case 4:
            printf("Enter the bank name of which detials need to nbe displayed\n");
            scanf("%c", &bankName);
            levelOrder(root, bankName);
            printf("\n");
            break;
        case 5:
            printf("Enter cash\n");
            scanf("%d", cash2);

            printf("Enter ATM id\n");
            scanf("%d", ai2);

            update_cash(root, ai2, cash2);
            printf("\n");
            break;
        case 6:
            lowestCash_root(root);
            printf("\n");
            break;
        case 7:
            check = 0;
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