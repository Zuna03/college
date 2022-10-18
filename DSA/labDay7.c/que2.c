#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack_198
{
    int data_198;
    struct stack_198 *next_198;
};

//pushing element in stack
void push_198(struct stack_198 **top_198, int n)
{
    struct stack_198 *new_198 = (struct stack_198 *)malloc(sizeof(struct stack_198));
    new_198->data_198 = n;
    new_198->next_198 = *top_198;
    *top_198 = new_198;
}

//checking whether stack is empty
bool isEmpty_198(struct stack_198 **top_198)
{
    if (*top_198 == NULL)
    {
        return true;
    }
    else
        return false;
}

//popping element from stack
int pop_198(struct stack_198 **top_198, int *b)
{
    if (isEmpty_198(top_198) == true)
    {
        printf("The stack is empty\n");
        return -1;
    }

    struct stack_198 *toDelete = (*top_198);
    (*top_198) = (*top_198)->next_198;
    *b = toDelete->data_198;
    free(toDelete);

    return *b;
}

//displaying stack
void display_198(struct stack_198 *top_198)
{
    if (isEmpty_198(&top_198) == true)
    {
        printf("The stack is empty\n");
        return;
    }  
        int b ;
        int temp_198 = pop_198(&top_198, &b);
        printf("%d ", temp_198);
        display_198(top_198);
        push_198(&top_198, temp_198);
    
}

int main()
{
    struct stack_198 *st_198 = NULL;

    int check_198 = 1;
    int b;

    printf("1.Push an element into the stack.\n");
    printf("2.Pop an element from the stack.\n");
    printf("3.Display a stack.\n");

    while (check_198)
    {
        int ch_198, val_198;
        printf("Enter your choice (1-3) ");
        scanf("%d", &ch_198);
        switch (ch_198)
        {
        case 1:
            printf("Enter the value need to be inserted :- \n");
            scanf("%d", &val_198);
            push_198(&st_198, val_198);
            printf("%d is pushed successfully.\n", val_198);
            break;
        case 2:
            pop_198(&st_198, &b);
            printf("The element was popped successfully.\n");
            break;
        case 3:
            printf("The current stack is :-\n");
            display_198(st_198);
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &check_198);

        if (check_198 == 0)
        {
            break;
        }
    }
    printf("The program is terminated !!\n");
    return 0;
}
