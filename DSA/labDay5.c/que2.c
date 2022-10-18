#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int data;
    struct node_198 *next;
};

void create(struct node_198 **start, int n)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->data = n;
    new_198->next = NULL;

    struct node_198 *temp_198;

    if ((*start) == NULL)
    {
        (*start) = new_198;
        return;
    }
    else
    {
        temp_198 = (*start);
        while (temp_198->next != NULL)
        {
            temp_198 = temp_198->next;
        }
        temp_198->next = new_198;
        new_198->next = NULL;
    }
}

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

struct node_198 *merge_198(struct node_198 *s1, struct node_198 *s2, struct node_198 *head)
{

    while (s1 != NULL && s2 != NULL)
    {

        if (s1->data < s2->data)
        {
            create(&head, s1->data);
            s1 = s1->next;
        }
        else if (s1->data > s2->data)
        {
            create(&head, s2->data);
            s2 = s2->next;
        }
        else
        {
            create(&head, s2->data);
            s1 = s1->next;
            s2 = s2->next;
        }
    }

    while (s1 != NULL)
    {
        create(&head, s1->data);
        s1 = s1->next;
    }

    while (s2 != NULL)
    {
        create(&head, s2->data);
        s2 = s2->next;
    }

    return head;
}

int main()
{
    struct node_198 *start1_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value of first linked list :-\n");
    scanf("%d", &start1_198->data);
    start1_198->next = NULL;

    struct node_198 *temp_1981 = start1_198;

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
        create(&temp_1981, val);
        temp_1981 = temp_1981->next;
    }

    printf("The entered first linked list is :-\n");
    display_198(&start1_198);

    struct node_198 *start2_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter first value of second linked list :-\n");
    scanf("%d", &start2_198->data);
    start2_198->next = NULL;

    struct node_198 *temp_1982 = start2_198;

    int y = 1;
    while (true)
    {
        printf("Do you want to add other node 1/0 :-\n");
        scanf("%d", &y);

        if (y == 0)
        {
            break;
        }

        printf("Enter the value :-\n");
        int val2;
        scanf("%d", &val2);
        create(&temp_1982, val2);
        temp_1982 = temp_1982->next;
    }

    printf("The entered second linked list is :-\n");
    display_198(&start2_198);

    struct node_198 *head = NULL;
    struct node_198 *ans = merge_198(start1_198, start2_198, head);
    printf("The mergesd linked list is :-\n");
    display_198(&ans);

    return 0;
}