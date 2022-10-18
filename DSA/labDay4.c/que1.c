#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int data;
    struct node_198 *next;
};

// 1) Program to  Print Current List :-

void print_198(struct node_198 **start)
{

    struct node_198 *temp_198 = *start;
    while (temp_198 != NULL)
    {
        printf("%d ", temp_198->data);
        temp_198 = temp_198->next;
    }
}

// 2) Program to check if the list is empty :-

void is_empty_198(struct node_198 *start)
{
    if (start == NULL)
    {
        printf("Yes the list is empty. \n");
    }
    else
    {
        printf("No the list is not empty \n");
    }
}

// 3) Program to ptint the list

void create_node_198_198(struct node_198 **start, int n_198)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n_198;
    new_198->next = NULL;

    struct node_198 *temp_198;

    if (*start == NULL)
    {
        *start = new_198;
        return;
    }
    else
    {
        temp_198 = *start;
        while (temp_198->next != NULL)
        {
            temp_198 = temp_198->next;
        }
        temp_198->next = new_198;
        new_198->next = NULL;
    }
}

// 4) Program to Insert a node_198 after a given data item

void insert_after_198(struct node_198 **start, int n_198, int k_198)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n_198;
    new_198->next = NULL;

    struct node_198 *temp_198 = *start;
    if (temp_198->data == k_198)
    {
        new_198->next = temp_198->next;
        temp_198->next = new_198;
        return;
    }
    else
    {
        while (temp_198->data != k_198)
        {
            temp_198 = temp_198->next;
        }
        new_198->next = temp_198->next;
        temp_198->next = new_198;
    }
}

// 5) Program to Insert a node_198 before a given data item

void insert_before_198(struct node_198 **start, int n_198, int k_198)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n_198;
    new_198->next = NULL;

    struct node_198 *temp_198 = *start;
    if (temp_198->data == k_198)
    {
        new_198->next = *start;
        *start = new_198;
        return;
    }
    else
    {
        while (temp_198->next->data != k_198)
        {
            temp_198 = temp_198->next;
        }
        new_198->next = temp_198->next;
        temp_198->next = new_198;
    }
}

// 6) Program to Delete a node_198 after a given data item

void delete_after_198(struct node_198 **start, int k_198)
{

    struct node_198 *temp_198 = *start;

    while (temp_198->data != k_198)
    {
        temp_198 = temp_198->next;
    }
    struct node_198 *toDelete_198 = temp_198->next;
    temp_198->next = temp_198->next->next;
    free(toDelete_198);
}

// 7) Program to Delete a node_198 before a given data item

void delete_before_198(struct node_198 **start, int k_198)
{
    struct node_198 *temp_198 = *start;
    struct node_198 *temp1_198 = *start;
    struct node_198 *temp2_198 = *start;

    if (temp_198->next->data == k_198)
    {
        struct node_198 *toDelete_198 = *start;
        *start = toDelete_198->next;
        free(toDelete_198);
        return;
    }
    else
    {

        while (temp2_198->next->data != k_198)
        {
            temp1_198 = temp2_198;
            temp2_198 = temp2_198->next;
        }
        struct node_198 *toDelete_198 = temp1_198->next;
        temp1_198->next = temp2_198->next;
        free(toDelete_198);
    }
}

// 8) Program to Insert a node_198 at the certain position (at beginning/end/any position).

void insert_certain_position_198(struct node_198 **start, int n_198, int k_198)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n_198;
    new_198->next = NULL;

    struct node_198 *temp_198 = *start;

    if (k_198 == 1)
    {
        new_198->next = temp_198->next;
        temp_198->next = new_198;
        return;
    }
    else
    {
        int i = 1;
        while (i < k_198)
        {
            temp_198 = temp_198->next;
            i++;
        }
        if (temp_198->next != NULL)
        {
            new_198->next = temp_198->next;
            temp_198->next = new_198;
        }
        else
        {
            temp_198->next = new_198;
            new_198->next = NULL;
        }
    }
}

// 9) Program to Delete a node_198 at the certain position (at beginning/end/any position).

void delete_at_certain_position_198(struct node_198 **start, int k_198)
{
    struct node_198 *temp_198 = *start;
    if (k_198 == 1)
    {
        struct node_198 *toDelete_198 = *start;
        *start = toDelete_198->next;
        free(toDelete_198);
        return;
    }
    else
    {
        int i = 1;
        while (i < k_198 - 1)
        {
            temp_198 = temp_198->next;
            i++;
        }
        if (temp_198->next->next != NULL)
        {
            struct node_198 *toDelete_198 = temp_198->next;
            temp_198->next = temp_198->next->next;
            free(toDelete_198);
        }
        else
        {
            struct node_198 *toDelete_198 = temp_198->next;
            temp_198->next = NULL;
            free(toDelete_198);
        }
    }
}

// 10) Program to Delete a node_198 for the given key.

void delete_given_key_198(struct node_198 **start, int k_198)
{
    struct node_198 *temp_198 = *start;

    if (temp_198->data == k_198)
    {
        struct node_198 *toDelete_198 = *start;
        *start = toDelete_198->next;
        free(toDelete_198);
        return;
    }
    while (temp_198->next->data != k_198)
    {
        temp_198 = temp_198->next;
    }
    if (temp_198->next->next == NULL)
    {
        struct node_198 *toDelete_198 = temp_198->next;
        temp_198->next = NULL;
        free(toDelete_198);
    }
    else
    {
        struct node_198 *toDelete_198 = temp_198->next;
        temp_198->next = temp_198->next->next;
        free(toDelete_198);
    }
}

// 11) Program to Search for an element in the linked list.

void search_element_198(struct node_198 **start, int k_198)
{
    struct node_198 *temp_198 = *start;
    int found_198 = 0;

    while (temp_198 != NULL)
    {
        if (temp_198->data == k_198)
        {
            found_198 = 1;
        }
        temp_198 = temp_198->next;
    }
    if (found_198 == 1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}

// 12) Program to Swap the elements of the linked list

void swap_198(struct node_198 *temp1_198, struct node_198 *temp2_198)
{
    int temp_198 = temp1_198->data;
    temp1_198->data = temp2_198->data;
    temp2_198->data = temp_198;
}

// 13) Program to Sort the elements of the linked list

void sort_198(struct node_198 **start)
{
    struct node_198 *temp1_198 = *start;
    struct node_198 *temp2_198 = temp1_198->next;

    while (temp1_198->next != NULL)
    {
        temp2_198 = temp1_198->next;
        while (temp2_198 != NULL)
        {
            if (temp2_198->data < temp1_198->data)
            {
                swap_198(temp1_198, temp2_198);
            }
            temp2_198 = temp2_198->next;
        }
        temp1_198 = temp1_198->next;
    }
}

// 14) Print the elements of the linked list in the reverse order.

void print_reverse_198(struct node_198 *start)
{
    struct node_198 *temp_198 = start;

    if (temp_198 == NULL)
    {
        return;
    }
    print_reverse_198(temp_198->next);
    printf("%d ", temp_198->data);
}

// 15) Reverse the node_198s of the linked list.

void reverse_198(struct node_198 **start)
{
    struct node_198 *t1 = *start;
    struct node_198 *t2;
    struct node_198 *t3 = NULL;

    while (t1 != NULL)
    {
        t2 = t1->next;
        t1->next = t3;
        t3 = t1;
        t1 = t2;
    }
    *start = t3;
}

// 16) Program to Print n th node_198 from the last of a linked list.

void print_Nth_From_Last_198(struct node_198 *start, int n_198)
{
    static int i_198 = 0;
    if (start == NULL)
    {
        return;
    }
    print_Nth_From_Last_198(start->next, n_198);
    if (++i_198 == n_198)
    {
        printf("%d", start->data);
    }
}

// 17) Program to Delete the duplicate elements in a linked list.

void remove_duplicates_198(struct node_198 **start)
{
    struct node_198 *temp1_198 = *start;
    struct node_198 *temp2_198;

    while (temp1_198 != NULL && temp1_198->next != NULL)
    {
        temp2_198 = temp1_198;
        while (temp2_198->next != NULL)
        {
            if (temp1_198->data == temp2_198->next->data)
            {
                struct node_198 *toDelete_198 = temp2_198->next;
                temp2_198->next = temp2_198->next->next;
                free(toDelete_198);
            }
            else
            {
                temp2_198 = temp2_198->next;
            }
        }
        temp1_198 = temp1_198->next;
    }
}

// Main function

int main()
{
    struct node_198 *start = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter a value \n");
    scanf("%d", &start->data);
    start->next = NULL;

    int x_198 = 1;

    struct node_198 *temp_198 = start;

    while (true)
    {

        printf("Do you want to enter another valur 1/0 ? \n");
        scanf("%d", &x_198);

        if (x_198 == 0)
        {
            break;
        }

        int val_198;
        printf("Enter a value \n");
        scanf("%d", &val_198);
        create_node_198_198(&temp_198, val_198);
        temp_198 = temp_198->next;
    }

    print_198(&temp_198);
    int check = 1;

    // Taking menu driven input

    printf("---------------------------------------------------------------------------------------\n");
    printf("1. Print Current List :-\n");
    printf("2. Check if the list is empty :-\n");
    printf("3. Insert a node_198 after a given data item :-\n");
    printf("4. Insert a node_198 before a given data item :-\n");
    printf("5. Delete a node_198 after a given data item :-\n");
    printf("6. Delete a node_198 before a given data item :-\n");
    printf("7. Insert a node_198 at the certain position :-\n");
    printf("8. Delete a node_198 at the certain position :-\n");
    printf("9. Delete a node_198 for the given key :-\n");
    printf("10. Search for an element in the linked list :-\n");
    printf("11. Sort the elements of the linked list :-\n");
    printf("12. Print the elements of the linked list in the reverse order :-\n");
    printf("13. Reverse the node_198s of the linked list :-\n");
    printf("14. Print nth node_198 from the last of a linked list :-\n");
    printf("15. Delete the duplicate elements in a linked list :-\n");
    printf("16. Quit!!\n");
    printf("---------------------------------------------------------------------------------------\n");

    while (check)
    {

        printf("Enter a number from the above menu to execute the program that is in front of that number :- \n");

        int num_198;
        scanf("%d", &num_198);

        int new_node_198_198;
        int node_198_num_198;

        switch (num_198)
        {
        case 1:
            print_198(&start);
            printf("\n");
            break;

        case 2:
            is_empty_198(start);
            printf("\n");
            break;

        case 3:
            printf("Enter new node_198 which need to be inserted\n");
            scanf("%d", &new_node_198_198);

            printf("Enter node_198 after which new node_198 need to be inserted\n");
            scanf("%d", &node_198_num_198);

            insert_after_198(&start, new_node_198_198, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 4:
            printf("Enter new node_198 which need to be inserted\n");
            scanf("%d", &new_node_198_198);

            printf("Enter node_198 before which new node_198 need to be inserted\n");
            scanf("%d", &node_198_num_198);

            insert_before_198(&start, new_node_198_198, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 5:
            printf("Enter node_198 after which a node_198 need to be deleted \n");
            scanf("%d", &node_198_num_198);

            delete_after_198(&start, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 6:
            printf("Enter node_198 before which a node_198 need to be deleted \n");
            scanf("%d", &node_198_num_198);

            delete_before_198(&start, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 7:
            printf("Enter new node_198 which need to be inserted\n");
            scanf("%d", &new_node_198_198);

            printf("Enter the position\n");
            scanf("%d", &node_198_num_198);

            insert_certain_position_198(&start, new_node_198_198, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 8:
            printf("Enter the position\n");
            scanf("%d", &node_198_num_198);

            delete_at_certain_position_198(&start, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 9:
            printf("Enter the key which needs to be deleted \n");
            scanf("%d", &node_198_num_198);
            delete_given_key_198(&start, node_198_num_198);
            print_198(&start);
            printf("\n");
            break;

        case 10:
            printf("Enter the element which is needed to be searched \n");
            scanf("%d", &node_198_num_198);

            search_element_198(&start, node_198_num_198);
            break;

        case 11:
            sort_198(&start);
            print_198(&start);
            printf("\n");
            break;

        case 12:
            print_reverse_198(start);
            break;

        case 13:
            reverse_198(&start);
            print_198(&start);
            printf("\n");
            break;

        case 14:
            printf("Enter position from the last which needs to be printrs \n");
            scanf("%d", &node_198_num_198);
            print_Nth_From_Last_198(start, node_198_num_198);
            printf("\n");
            break;

        case 15:
            remove_duplicates_198(&start);
            print_198(&start);
            printf("\n");
            break;

        case 16:
            printf("Quit!! \n");
            check = 0;
            break;

        default:
            printf("Invalid number \n");
            break;
        }
    }

    return 0;
}