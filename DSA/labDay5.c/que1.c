#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int data;
    struct node_198 *next;
};

// to create a linked list
void create_198(struct node_198 **start_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n;
    new_198->next = NULL;

    if (*start_198 == NULL)
    {
        *start_198 = new_198;
        return;
    }
    else
    {
        struct node_198 *temp_198 = *start_198;
        while (temp_198->next != NULL)
        {
            temp_198 = temp_198->next;
        }
        temp_198->next = new_198;
        new_198->next = NULL;
    }
}

// to display linked list
void display_198(struct node_198 **start)
{
    struct node_198 *temp_198 = *start;
    while (temp_198 != NULL)
    {
        printf("%d ", temp_198->data);
        temp_198 = temp_198->next;
    }
    printf("\n");
}

// to search element of a linked list
bool search_198(struct node_198 **start, int n)
{
    struct node_198 *temp_198 = *start;
    bool check_198 = 0;
    while (temp_198 != NULL)
    {
        if (temp_198->data == n)
        {
            return true;
        }
        temp_198 = temp_198->next;
    }
    return false;
}

//  to insert element n the beginning
void insert_198(struct node_198 **st_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n;
    new_198->next = *st_198;
    *st_198 = new_198;
}

// a program to search an element in a simple linked list, if found delete that node and insert that node at beginning. Otherwise display an appropriate message.
bool delete_198(struct node_198 **start_198, int n)
{
    if (search_198(start_198, n) == false)
    {
        printf("Node which needs to be delete_198d is not found \n"); // displaying a message
        return 0;
    }

    else
    {
        struct node_198 *temp_198;
        if ((*start_198)->data == n)
        {
            struct node_198 *todelete_198 = *start_198;
            *start_198 = todelete_198->next;
            free(todelete_198);
        }
        else
        {
            temp_198 = *start_198;
            while (temp_198->next->data != n)
            {
                temp_198 = temp_198->next;
            }
            struct node_198 *todelete_198 = temp_198->next;
            temp_198->next = temp_198->next->next;
            free(todelete_198); // deleting the found node
        }

        insert_198(start_198, n); // insertung the found node
    }
    return 1;
}

// program to find the middle node in a single linked list
void middle_198(struct node_198 **start_198)
{
    struct node_198 *temp1_198 = (*start_198);
    struct node_198 *temp2_198 = (*start_198);

    while (temp1_198->next != NULL && temp1_198->next->next != NULL)
    {
        temp1_198 = temp1_198->next->next;
        temp2_198 = temp2_198->next;
    }
    if (temp1_198->next == NULL)
    {
        printf("The middle node is %d\n", temp2_198->data);
    }
    if (temp1_198->next->next == NULL)
    {
        printf("The middle nodes are %d , %d\n", temp2_198->data, temp2_198->next->data);
    }
}

// program to reverse the first m elements of a linked list of n nodes.
void reverse_m_198(struct node_198 **start_198, int m_198)
{
    struct node_198 *temp_198 = *start_198;
    m_198--;
    while (m_198--)
        temp_198 = temp_198->next;
    struct node_198 *joint_198 = temp_198->next;
    temp_198->next = NULL;
    struct node_198 *prev_198 = NULL;
    struct node_198 *current_198 = *start_198;
    struct node_198 *next = NULL;
    while (current_198 != NULL)
    {
        next = current_198->next;
        current_198->next = prev_198;
        prev_198 = current_198;
        current_198 = next;
    }
    *start_198 = prev_198;
    struct node_198 *temp2_198 = *start_198;
    while (temp2_198->next != NULL)
        temp2_198 = temp2_198->next;
    temp2_198->next = joint_198;
}

// program to check whether a given linked list is sorted or not.
bool is_sorted_198(struct node_198 **start_198)
{
    struct node_198 *curr_198 = *start_198;
    struct node_198 *n;

    while (curr_198->next != NULL)
    {
        n = curr_198->next;
        while (n != NULL)
        {
            if (curr_198->data > n->data)
            {
                return false;
            }
            n = n->next;
        }
        curr_198 = curr_198->next;
    }
    return true;
}

// Given a linked list which is sorted, write a program to insert an element into the linked list in sorted way.
void insert_in_sorted_198(struct node_198 **start_198, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n;
    new_198->next = NULL;
    struct node_198 *temp_198;

    if ((*start_198)->data > new_198->data)
    {
        new_198->next = *start_198;
        *start_198 = new_198;
    }
    else
    {
        temp_198 = *start_198;

        while (temp_198->next != NULL && temp_198->next->data <= new_198->data)
        {
            temp_198 = temp_198->next;
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

// finding intersections elements of two linked list and store them in a third linked list.
struct node_198 *intersection_ele_198(struct node_198 *start1_198, struct node_198 *start2_198)
{
    struct node_198 *start3_198 = NULL;
    struct node_198 *temp1_198 = start1_198;
    struct node_198 *temp2_198 = start2_198;

    while (temp1_198 != NULL)
    {
        temp2_198 = start2_198;
        while (temp2_198 != NULL)
        {
            if (temp1_198->data == temp2_198->data)
            {
                create_198(&start3_198, temp1_198->data);
                break;
            }
            temp2_198 = temp2_198->next;
        }
        temp1_198 = temp1_198->next;
    }
    return start3_198;
}

// modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
void even_before_odd_198(struct node_198 **start)
{
    struct node_198 *curr_198 = *start;
    struct node_198 *n;

    while (curr_198->next != NULL)
    {
        n = curr_198->next;
        while (n != NULL)
        {
            if (curr_198->data % 2 != 0 && n->data % 2 == 0)
            {
                int temp_198 = curr_198->data;
                curr_198->data = n->data;
                n->data = temp_198;
            }
            n = n->next;
        }
        curr_198 = curr_198->next;
    }
}

// a program to check whether a singly linked list is a palindrome or not.
bool is_palindrome_198(struct node_198 **start)
{
    struct node_198 *temp1_198 = *start;
    struct node_198 *temp2_198 = *start;
    struct node_198 *temp3_198;

    while (temp2_198->next != NULL)
    {
        temp2_198 = temp2_198->next;
    }
    if (temp1_198->data == temp2_198->data)
    {
        while (temp1_198 != temp2_198 && temp1_198->next != temp2_198)
        {
            temp2_198 = temp1_198->next;
            while (temp2_198->next != temp2_198)
            {
                temp2_198 = temp2_198->next;
            }
            if (temp2_198->next->data != temp1_198->data)
            {
                return false;
            }
            temp2_198 = temp2_198;
            temp1_198 = temp1_198->next;
        }
        if (temp1_198->next == temp2_198)
        {
            if (temp1_198->data == temp2_198->data)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

// creating cycle in a linked list
void create_cycle_198(struct node_198 **start, int pos)
{
    struct node_198 *temp_198 = *start;
    struct node_198 *temp2_198 = *start;
    int i = 1;

    while (i < pos)
    {
        temp_198 = temp_198->next;
        i++;
    }
    struct node_198 *joint_198 = temp_198->next;

    while (temp2_198->next != NULL)
    {
        temp2_198 = temp2_198->next;
    }
    temp2_198->next = joint_198;
}

// detect a cycle in a linked list.
bool detect_cycle_198(struct node_198 **start_198)
{
    struct node_198 *slow_198 = *start_198;
    struct node_198 *fast_198 = *start_198;

    while (fast_198 != NULL && fast_198->next != NULL)
    {
        slow_198 = slow_198->next;
        fast_198 = fast_198->next->next;
        if (slow_198 == fast_198)
        {
            return true;
        }
    }
    return false;
}

// reverse only even position nodes in a singly linked list.
void reverse_even_198(struct node_198 **start)
{
    struct node_198 *odd_198 = *start;
    struct node_198 *even_198 = NULL;

    while (odd_198 != NULL && odd_198->next != NULL)
    {
        struct node_198 *temp_198 = odd_198->next;
        odd_198->next = temp_198->next;
        temp_198->next = even_198;
        even_198 = temp_198;
        odd_198 = odd_198->next;
    }

    odd_198 = *start;
    while (even_198 != NULL)
    {
        struct node_198 *temp_198 = even_198->next;
        even_198->next = odd_198->next;
        odd_198->next = even_198;
        odd_198 = odd_198->next->next;
        even_198 = temp_198;
    }
}

// swap kth node from beginning with kth node from end in a Linked List
void swap_Kth_198(struct node_198 **start_198, int k)
{
    int i = 1;
    struct node_198 *temp1_198 = *start_198;
    struct node_198 *temp2_198 = *start_198;
    struct node_198 *temp3_198;
    while (temp2_198->next != NULL)
    {
        temp2_198 = temp2_198->next;
    }
    while (i < k)
    {
        temp3_198 = temp1_198->next;
        while (temp3_198->next != temp2_198)
        {
            temp3_198 = temp3_198->next;
        }
        temp2_198 = temp3_198;
        temp1_198 = temp1_198->next;
        i++;
    }
    if (i == k)
    {
        int temp_198 = temp1_198->data;
        temp1_198->data = temp2_198->data;
        temp2_198->data = temp_198;
    }
}

// function to reverse every k nodes.
struct node_198 *reverse_every_k_198(struct node_198*start_198, int k)
{
    if (start_198 == NULL)
    {
        return NULL;
    }

    struct node_198 *curr_198 = start_198;
    struct node_198 *n = NULL;
    struct node_198 *prev_198 = NULL;
    int count_198 = 0;

    while (curr_198 != NULL && count_198 < k)
    {
        n = curr_198->next;
        curr_198->next = prev_198;
        prev_198 = curr_198;
        curr_198 = n;
        count_198++;
    }

    if (n != NULL)
    {
        start_198->next = reverse_every_k_198(n, k);
    }

    return prev_198;
}

// rotate the linked list counter-clockwise by k nodes.
struct node_198 *rotating_198(struct node_198 *start, int k)
{
    if (k < 1)
    {
        return NULL;
    }
    struct node_198 *curr_198 = start;
    struct node_198 *kth = NULL;
    int i = 1;
    while (i < k && curr_198 != NULL)
    {
        curr_198 = curr_198->next;
        i++;
    }
    if (curr_198 == NULL)
    {
        return NULL;
    }
    kth = curr_198;
    while (curr_198->next != NULL)
    {
        curr_198 = curr_198->next;
    }
    curr_198->next = start;
    start = kth->next;
    kth->next = NULL;
    return start;
}

int main()
{
    struct node_198 *start_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value :-\n");
    scanf("%d", &start_198->data);
    start_198->next = NULL;

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
        temp_198 = temp_198->next;
    }

    printf("The entered linked list is :-\n");
    display_198(&start_198);

    int check_198 = 1;

    while (check_198)
    {

        printf("\n**************************************************************************************\n");
        printf("\t1. Print the current list.\n");
        printf("2. Write a program to search an element in a simple linked list, if found delete that node and insert that node at beginning. Otherwise display an appropriate message.\n");
        printf("3. Write a program to find the middle node in a single linked list without counting the number of nodes.\n");
        printf("4. Write a program to reverse first m elements of a linked list of n nodes.\n");
        printf("5. Write a program to check whether a given linked list is sorted or not.\n");
        printf("6. Given a linked list which is sorted, write a program to insert an element into the linked list in sorted way.\n");
        printf("7. Write a program to find the intersections elements of two linked list and store them in a third linked list.\n");
        printf("8. Write a program to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.\n");
        printf("9. Write a program to check whether a singly linked list is a palindrome or not.\n");
        printf("10. A linked list is said to contain a cycle if any node is visited more than once while traversing the list. Write a program to detect a cycle in a linked list.\n");
        printf("11. Write a program to reverse only even position nodes in a singly linked list.\n");
        printf("12. Write a program to swap kth node from beginning with kth node from end in a Linked List.\n");
        printf("13. Given a linked list, write a function to reverse every k nodes. (where k is an input to the function).\n");
        printf("14. Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer.(k<n)\n");
        printf("\t15. Quit!!\n");
        printf("\n");
        printf("\n**************************************************************************************\n");
        printf("\n");

        printf("Enter a number from above list to execute the operation in front of it :\n");
        int z_198;
        scanf("%d", &z_198);
        int k_198, key_198, m_198, pos_198, w_198, data;
        switch (z_198)
        {
        case 1:
            display_198(&start_198);
            printf("The Program ran successfully.\n");
            break;
        case 2:
            printf("Enter the key :-");
            scanf("%d", &key_198);
            delete_198(&start_198, key_198);
            display_198(&start_198);
            printf("The program ran successfully.\n");
            break;
        case 3:
            middle_198(&start_198);
            break;
        case 4:
            printf("Enter the value :-");
            scanf("%d", &m_198);
            reverse_m_198(&start_198, m_198);
            display_198(&start_198);
            printf("The program ran successfully.\n");
            break;
        case 5:
            if (is_sorted_198(&start_198))
                printf("The List is sorted.\n");
            else
                printf("The List is unsorted.\n");
            break;
        case 6:
            printf("Enter the data which need to be inserted in sorted list:- ");
            scanf("%d", &data);
            insert_in_sorted_198(&start_198, data);
             display_198(&start_198);
            printf("The program ran successfully.\n");
            break;
        case 7:
            printf("Enter the values for the second list :-\n");
            struct node_198 *start2_198 = (struct node_198 *)malloc(sizeof(struct node_198));
            printf("Enter a value :- ");
            scanf("%d", &start2_198->data);
            start2_198->next = NULL;
            int x2_198 = 1;
            struct node_198 *temp2_198 = start2_198;
            while (true)
            {
                printf("Do you want to continue (1 = YES/ 0 = NO) :- ");
                scanf("%d", &x2_198);
                if (x2_198 == 0)
                    break;
                int val2_198;
                printf("Enter a value :- ");
                scanf("%d", &val2_198);
                create_198(&temp2_198, val2_198);
                temp2_198 = temp2_198->next;
            }
            struct node_198 *start3_198 = intersection_ele_198(start_198, start2_198);
            printf("The Program ran successfully.\n");
            printf("The common linked list is :- \n");
            display_198(&start3_198);
            break;
        case 8:
            even_before_odd_198(&start_198);
            display_198(&start_198);
            printf("The Program ran successfully.\n");
            break;
        case 9:
            if (is_palindrome_198(&start_198))
                printf("The list is a palindrome.\n");
            else
                printf("The list is not a palindrome.\n");
            break;
        case 10:
            printf("Do you want to make a cycle ((0 == No) or (1 == Yes)) :-");
            scanf("%d", &w_198);
            if (w_198 == 1)
            {
                printf("Enter the position where you want to create the cycle.\n");
                scanf("%d", &pos_198);
                create_cycle_198(&start_198, pos_198);
                printf("The cycle was created.\n");
            }
            if (detect_cycle_198(&start_198))
                printf("This linked list has a cycle.\n");
            else
                printf("This linked list has no cycle.\n");
            break;
        case 11:
            reverse_even_198(&start_198);
            display_198(&start_198);
            printf("The Program ran successfully.\n");
            break;
        case 12:
            printf("Enter the value :-");
            scanf("%d", &k_198);
            swap_Kth_198(&start_198, k_198);
            display_198(&start_198);
            printf("The program ran successfully.\n");
            break;
        case 13:
            printf("Enter the value :-");
            scanf("%d", &k_198);
            start3_198 = reverse_every_k_198(start_198, k_198);
            display_198(&start3_198);
            printf("The program ran successfully.\n");
            break;
        case 14:
            printf("Enter the value :-");
            scanf("%d", &k_198);
            rotating_198(start_198, k_198);
            printf("The program ran successfully.\n");
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    return 0;
}
