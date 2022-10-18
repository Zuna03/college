#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Define the size of the array.
#define max_198 100
// Structure to create a stack ADT where 2 stacks are implemented for a array.
struct stack_198
{
    int top1_198, top2_198, data_198[max_198];
};
// Function to check whether a stack is full or not.
int isFull_198(struct stack_198 *st_198)
{
    if ((st_198->top1_198 + 1) == st_198->top2_198)
        return 1;
    return 0;
}
// Functions for stack 1.
// Function to check whether a stack 1 is empty or not.
int isEmpty1_198(struct stack_198 *st_198)
{
    if (st_198->top1_198 == -1)
        return 1;
    return 0;
}
// Function to push an item in the stack 1.
void pushStack1_198(struct stack_198 *st_198, int val_198)
{
    if (isFull_198(st_198))
    {
        printf("Stack Full!!\n");
        return;
    }
    st_198->data_198[++st_198->top1_198] = val_198;
}
// Function to pop an item from the stack 1.
int popStack1_198(struct stack_198 *st_198)
{
    if (isEmpty1_198(st_198))
    {
        printf("Stack Empty!!\n");
        return INT_MIN;
    }
    return st_198->data_198[st_198->top1_198--];
}
// Function to display the present stack 1.
void displayStack1_198(struct stack_198 *st_198)
{
    if (isEmpty1_198(st_198))
        return;
    int val_198 = popStack1_198(st_198);
    printf("%d ", val_198);
    displayStack1_198(st_198);
    pushStack1_198(st_198, val_198);
}
// Functions for stack 2.
// Function to check whether a stack 2 is empty or not.
int isEmpty2_198(struct stack_198 *st_198)
{
    if (st_198->top2_198 == max_198)
        return 1;
    return 0;
}
// Function to push an item in the stack 2.
void pushStack2_198(struct stack_198 *st_198, int val_198)
{
    if (isFull_198(st_198))
    {
        printf("Stack Full!!\n");
        return;
    }
    st_198->data_198[--st_198->top2_198] = val_198;
}
// Function to pop an item from the stack 2.
int popStack2_198(struct stack_198 *st_198)
{
    if (isEmpty2_198(st_198))
    {
        printf("Stack Empty!!\n");
        return INT_MIN;
    }
    return st_198->data_198[st_198->top2_198++];
}
// Function to display the present stack 2.
void displayStack2_198(struct stack_198 *st_198)
{
    if (isEmpty2_198(st_198))
        return;
    int val_198 = popStack2_198(st_198);
    printf("%d ", val_198);
    displayStack2_198(st_198);
    pushStack2_198(st_198, val_198);
}
// Main Function.
int main()
{
    struct stack_198 *st_198 = (struct stack_198 *)malloc(sizeof(struct
                                                                 stack_198));
    st_198->top1_198 = -1;
    st_198->top2_198 = max_198;
    int check_198 = 1;

    printf("Stack ID:\n(1 == stack1)\t(2 == stack2)\n\n");
    printf("1.PUSH.\n");
    printf("2.POP.\n");
    printf("3.DISPLAY.\n");
    printf("4.QUIT!!\n");

    while (check_198)
    {

        printf("Enter your choice :- ");
        int z_198, id_198, val_198, popped_198;
        scanf("%d", &z_198);
        switch (z_198)
        {
        case 1:
            printf("Enter the stack ID :- ");
            scanf("%d", &id_198);
            printf("Enter the value :- ");
            scanf("%d", &val_198);
            if (id_198 == 1)
                pushStack1_198(st_198, val_198);
            else
                pushStack2_198(st_198, val_198);
            printf("%d was pushed successfully in stack %d.\n", val_198,
                   id_198);
            break;
        case 2:
            printf("Enter the stack ID :- ");
            scanf("%d", &id_198);
            if (id_198 == 1)
                popped_198 = popStack1_198(st_198);
            else
                popped_198 = popStack2_198(st_198);
            if (popped_198 != INT_MIN)
                printf("%d was popped successfully from stack %d.\n",
                       popped_198, id_198);
            break;
        case 3:
            printf("Enter the stack ID :- ");
            scanf("%d", &id_198);
            if (id_198 == 1)
            {
                printf("The current stack is :-\n");
                displayStack1_198(st_198);
                printf("\n");
            }
            else
            {
                printf("The current stack is :-\n");
                displayStack2_198(st_198);
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &check_198);

        if (check_198 == 0)
        {
            break;
        }
    }

    printf("The Program is terminated!!\n");
    return 0;
}