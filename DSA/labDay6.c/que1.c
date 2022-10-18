#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int data_198;
    struct node_198 *next_198;
    struct node_198 *prev_198;
};

// Create the list
void create_198(struct node_198**start_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data_198 = n;
    new_198->prev_198 = NULL;
    new_198->next_198 = NULL;

    struct node_198 *temp_198;

    if ((*start_198) == NULL)
    {
        *start_198 = new_198;
        return;
    }
    else
    {
        temp_198 = (*start_198);
        while (temp_198->next_198 != NULL)
        {
            temp_198 = temp_198->next_198;
        }
        new_198->prev_198 = temp_198;
        temp_198->next_198 = new_198;
        new_198->next_198 = NULL;
    }
}

//Traverse the list in forward direction
void display_198(struct node_198 **start_198)
{
    struct node_198 *temp_198 = (*start_198);
    while (temp_198 != NULL)
    {
        printf("%d ", temp_198->data_198);
        temp_198 = temp_198->next_198;
    }
    printf("\n");
}

//Traverse the list in backward direction
void traverse_backward_198(struct node_198 **start_198)
{
    //struct node_198 *t1 = *start_198;
    if (*start_198 != NULL)
    {
        traverse_backward_198(&(*start_198)->next_198);
        printf("%d ", (*start_198)->data_198);
    }
}

//Add a node after a given data item
void add_after_data_198(struct node_198 **start_198, int n, int k)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data_198 = n;
    new_198->prev_198 = NULL;
    new_198->next_198 = NULL;

    struct node_198 *temp_198 = (*start_198);

    while (temp_198->data_198 != k && temp_198->next_198 != NULL)
    {
        temp_198 = temp_198->next_198;
    }
    if (temp_198->next_198 != NULL)
    {
        new_198->prev_198 = temp_198;
        new_198->next_198 = temp_198->next_198;
        temp_198->next_198 = new_198;
        temp_198->next_198->prev_198 = new_198;
    }
    else
    {
        new_198->prev_198 = temp_198;
        temp_198->next_198 = new_198;
        new_198->next_198 = NULL;
    }
}

//Add a node before a given data item
void add_before_data_198(struct node_198 **start_198, int n, int k)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data_198 = n;
    new_198->prev_198 = NULL;
    new_198->next_198 = NULL;

    struct node_198 *temp_198;
    if ((*start_198)->data_198 == k)
    {
        new_198->next_198 = (*start_198);
        (*start_198)->prev_198 = new_198;
        *start_198 = new_198;
        return;
    }
    else
    {
        temp_198 = (*start_198);
        while (temp_198->next_198->data_198 != k)
        {
            temp_198 = temp_198->next_198;
        }
        new_198->prev_198 = temp_198;
        new_198->next_198 = temp_198->next_198;
        temp_198->next_198 = new_198;
        temp_198->next_198->prev_198 = new_198;
    }
}

//Delete a node at a given position
void delete_at_given_198(struct node_198 **start_198, int pos)
{
    struct node_198 *temp_198;
    int i = 1;
    if (pos == 1)
    {
        struct node_198 *toDelete_198 = *start_198;
        *start_198 = (*start_198)->next_198;
        (*start_198)->prev_198 = NULL;
        free(toDelete_198);
    }
    else
    {
        temp_198 = *start_198;
        while (temp_198->next_198 != NULL && i < pos)
        {
            temp_198 = temp_198->next_198;
            i++;
        }
        if (temp_198->next_198 != NULL)
        {
            struct node_198 *toDelete_198 = temp_198;
            temp_198->next_198->prev_198 = temp_198->prev_198;
            temp_198->prev_198->next_198 = temp_198->next_198;
            free(toDelete_198);
        }
        else
        {
            struct node_198 *toDelete_198 = temp_198;
            temp_198->prev_198->next_198 = NULL;
            temp_198->prev_198=NULL;
            free(toDelete_198);
        }
    }
}

//Add a node a first node
void add_first_198(struct node_198 **start_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data_198 = n;
    new_198->prev_198 = NULL;
    new_198->next_198 = *start_198;
    (*start_198)->prev_198 = new_198;
    *start_198 = new_198;
}

//Delete the first node
void delete_first_198(struct node_198 **start_198)
{
    struct node_198 *toDelete_198 = *start_198;
    *start_198 = (*start_198)->next_198;
    (*start_198)->prev_198 = NULL;
    free(toDelete_198);
}

//Reverse the content of the linked list by traversing each node only once.
void reverse_198(struct node_198 **start_198)
{
    struct node_198 *curr = *start_198;
    struct node_198 *p = NULL;
    struct node_198 *n;

    while (curr != NULL)
    {
        n = curr->next_198;
        curr->next_198 = p;
        curr->prev_198 = n;
        p = curr;
        curr = n;
    }
    *start_198 = p;
}

int main()
{
    struct node_198 *start_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value :-\n");
    scanf("%d", &start_198->data_198);
    start_198->next_198 = NULL;

    struct node_198 *temp_198 = start_198;

    int x = 1;
    while (true)
    {
        printf("Do you want to add other node 1/0 :-\n");
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }

        printf("Enter the value :-\n");
        int val;
        scanf("%d", &val);
        create_198(&temp_198, val);
        temp_198 = temp_198->next_198;
    }

    printf("The entered linked list is :-\n");
    display_198(&start_198);

    int check_198 = 1;

    printf("1. Traverse the list in forward direction\n");
    printf("2. Traverse the list in backward direction\n");
    printf("3. Add a node after a given data item\n");
    printf("4. Add a node before a given data item\n");
    printf("5. Delete a node at a given position\n");
    printf("6. Add a node a first node\n");
    printf("7. Delete the first node\n");
    printf("8. Reverse the content of the linked list by traversing each node only once.\n");

    int choice;
    char ch;
    int n, n1, n2, k, k1, k2, p;
    do
    {
        printf("\nEnter your choice(1-8): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 2:
            printf("The reverse linked list is :\n");
            traverse_backward_198(&start_198);
            break;

        case 3:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n);
            printf("Enter value of node after which you want new node to be added :\n");
            scanf("%d", &k);
            add_after_data_198(&start_198, n, k);
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 4:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n1);
            printf("Enter value of node before which you want new node to be added :\n");
            scanf("%d", &k1);
            add_before_data_198(&start_198, n, k);
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 5:
            printf("Enter the position after which you want new node to be deleted :\n");
            scanf("%d", &p);
            delete_at_given_198(&start_198, p);
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 6:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n2);
            add_first_198(&start_198, n2);
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 7:
            delete_first_198(&start_198);
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 8:
            reverse_198(&start_198);
            printf("The linked list with reverse content  is :\n");
            display_198(&start_198);
            break;

        default:
            printf("\nYou entered a wrong choice!!");
            break;
        }
        printf("\n Do you want to enter more choice(Y/N): ");
        scanf("%s", &ch);
    } while (ch == 'Y' || ch == 'y');

    printf("The program is terminated\n");

    return 0;
}