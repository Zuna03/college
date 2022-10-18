#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_198
{
    int coeff;
    int expo;
    struct node_198 *next;
};

void create_198(struct node_198 **start_198, int c, int e)
{
    struct node_198 *new_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    new_198->coeff = c;
    new_198->expo = e;
    new_198->next = NULL;

    struct node_198 *temp_198;

    if (*start_198 == NULL)
    {
        *start_198 = new_198;
        return;
    }
    else
    {
        temp_198 = *start_198;
        while (temp_198->next != NULL)
        {
            temp_198 = temp_198->next;
        }
        temp_198->next = new_198;
        new_198->next = NULL;
    }
}

void duplicates(struct node_198 **start_198)
{
    struct node_198 *temp1_198 = *start_198;
    struct node_198 *temp2_198;
    struct node_198 *dup_198;

    while (temp1_198 != NULL && temp1_198->next != NULL)
    {
        temp2_198 = temp1_198;
        while (temp2_198->next != NULL)
        {
            if (temp1_198->expo == temp2_198->next->expo)
            {
                temp1_198->coeff = temp1_198->coeff + temp2_198->next->coeff;
                dup_198 = temp2_198->next;
                temp2_198->next = temp2_198->next->next;
                free(dup_198);
            }
            else
            {
                temp2_198 = temp2_198->next;
            }
        }
        temp1_198 = temp1_198->next;
    }
}
void multiply_198(struct node_198 *start1_198, struct node_198 *start2_198, struct node_198 **start3_198)
{
    struct node_198 *temp1_198 = start1_198;
    struct node_198 *temp2_198 = start2_198;
    int sum1 = 0;
    while (temp1_198 != NULL)
    {
        // int coeff, expo;
        while (temp2_198 != NULL)
        {
            create_198(start3_198, temp1_198->coeff * temp2_198->coeff, temp1_198->expo + temp2_198->expo);
            temp2_198 = temp2_198->next;
        }
        temp2_198 = start2_198;
        temp1_198 = temp1_198->next;
    }
    duplicates(start3_198);
}

void display_198(struct node_198 *start_198)
{
    struct node_198 *temp_198 = start_198;
    while (temp_198 != NULL)
    {
        printf("%dx^%d + ", temp_198->coeff, temp_198->expo);
        temp_198 = temp_198->next;
    }
    printf("0");
    printf("\n");
}
int main()
{
    printf("Enter the values for the first polynomial :- \n");
    printf("\n*****************************************************************\n");
    struct node_198 *start1_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter a coefficient :- ");
    scanf("%d", &start1_198->coeff);
    printf("Enter the exponent :- ");
    scanf("%d", &start1_198->expo);
    start1_198->next = NULL;
    int x1_198 = 1;
    struct node_198 *temp1_198 = start1_198;
    while (true)
    {
        printf("Do you want to continue (1 = YES/ 0 = NO) :- ");
        scanf("%d", &x1_198);
        if (x1_198 == 0)
            break;
        int coe1_198;
        printf("Enter a coefficient :- ");
        scanf("%d", &coe1_198);
        int ex1_198;
        printf("Enter a exponent :- ");
        scanf("%d", &ex1_198);
        create_198(&temp1_198, coe1_198, ex1_198);
        temp1_198 = temp1_198->next;
    }
    printf("The First Polynomial is :- \n");
    display_198(start1_198);
    printf("\n*****************************************************************\n");
    printf("Enter the values for the second polynomial :- \n");
    struct node_198 *start2_198 = (struct node_198 *)malloc(sizeof(struct node_198));
    printf("Enter a coefficient :- ");
    scanf("%d", &start2_198->coeff);
    printf("Enter a exponent :- ");
    scanf("%d", &start2_198->expo);
    start2_198->next = NULL;
    int x2_198 = 1;
    struct node_198 *temp2_198 = start2_198;
    while (true)
    {
        printf("Do you want to continue (1 = YES/ 0 = NO) :- ");
        scanf("%d", &x2_198);
        if (x2_198 == 0)
            break;
        int coe2_198;
        printf("Enter a coefficient :- ");
        scanf("%d", &coe2_198);
        int ex2_198;
        printf("Enter a exponent :- ");
        scanf("%d", &ex2_198);
        create_198(&temp2_198, coe2_198, ex2_198);
        temp2_198 = temp2_198->next;
    }
    printf("The Second Polynomial is :- \n");
    display_198(start2_198);
    printf("\n*****************************************************************\n");
    struct node_198 *head3_198 = NULL;
    multiply_198(start1_198, start2_198, &head3_198);
    printf("The equation is as follows :-\n");
    display_198(start1_198);
    printf(" * ");
    display_198(start2_198);
    printf(" = ");
    display_198(head3_198);
    printf("\n");
    return 0;
}