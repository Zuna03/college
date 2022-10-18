#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int data_198;
    struct node_198 *next_198;
};

struct node_198 *create_198(struct node_198 **start_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data_198 = n;
    new_198->next_198 = new_198;

    struct node_198 *temp_198;
    if (*start_198 == NULL)
    {
        new_198->next_198 = new_198;
        *start_198 = new_198;
    }
    else
    {
        temp_198 = *start_198;
        while (temp_198->next_198 != *start_198)
        {
            temp_198 = temp_198->next_198;
        }
        temp_198->next_198 = new_198;
        new_198->next_198 = *start_198;
    }
}

void display_198(struct node_198 **start_198)
{
    struct node_198 *temp_198 = *start_198;
    do
    {
        printf("%d ", temp_198->data_198);
        temp_198 = temp_198->next_198;
    } while (temp_198 != *start_198);
    printf("\n");
}

void add_first_198(struct node_198 **start_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data_198 = n;
    new_198->next_198 = new_198;

    struct node_198 *temp_198;
    if (*start_198 == NULL)
    {
        *start_198 = new_198;
        (*start_198)->next_198 = *start_198;
    }
    else
    {
        temp_198 = *start_198;

        while (temp_198->next_198 != *start_198)
        {
            temp_198 = temp_198->next_198;
        }
        temp_198->next_198 = new_198;
        new_198->next_198 = *start_198;
        *start_198 = new_198;
    }
}

void delete_first_198(struct node_198 **start_198)
{
    struct node_198 *temp_198 = *start_198;

    while (temp_198->next_198 != *start_198)
    {
        temp_198 = temp_198->next_198;
    }
    struct node_198 *toDelete = *start_198;
    *start_198 = (*start_198)->next_198;
    temp_198->next_198 = *start_198;
    free(toDelete);
}
int main()
{
    struct node_198 *start_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value :-\n");
    scanf("%d", &start_198->data_198);
    start_198->next_198 = start_198;

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

    printf("1. Traverse the list \n");
    printf("2. Add a node a first node\n");
    printf("3. Delete the first node\n");

    int choice;
    char ch;
    int n;

    do
    {
        printf("\nEnter your choice(1-3): ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 2:
            printf("Add value of new node you want to add :\n");
            scanf("%d", &n);
            add_first_198(&start_198, n);
            printf("The linked list is :\n");
            display_198(&start_198);
            break;

        case 3:
            delete_first_198(&start_198);
            printf("The linked list is :\n");
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