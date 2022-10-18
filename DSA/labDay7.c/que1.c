#include <stdio.h>
#include <stdbool.h>

struct stack_198
{
    int s[100];
    int top_198;
};

// checking whether stack is full or not
bool isFull_198(struct stack_198 *s1)
{
    if (s1->top_198 == 99)
    {
        return true;
    }
    return false;
}

//pushing an element in stack
void push_198(struct stack_198 *s1, int n)
{
    if (isFull_198(s1))
    {
        printf("Overflow\n");
        return;
    }

    s1->top_198++;
    s1->s[s1->top_198] = n;
}

bool isEmpty_198(struct stack_198 *s1)
{
    if (s1->top_198 == -1)
    {
        return true;
    }
    return false;
}

//popping element out of stack
void pop_198(struct stack_198 *s1, int *b)
{
    if (isEmpty_198(s1))
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        *b = s1->s[s1->top_198];
        s1->top_198--;
    }
}

//adding elemnts in sorted order in sorted stack
void sorted_add_198(struct stack_198 *s1, int x)    
{
    if (s1->top_198 == -1 || x > s1->s[s1->top_198])
    {
        push_198(s1, x);
        return;
    }
    int b;
    pop_198(s1, &b);
    sorted_add_198(s1, x);
    push_198(s1, b);
}

//sorting the stack
void sorting_198(struct stack_198 *s1)
{
    int x;
    if (s1->top_198 != -1)
    {
        pop_198(s1, &x);
        sorting_198(s1);
        sorted_add_198(s1, x);
    }
}

//displaying elements of stack
void display_198(struct stack_198 *s1)
{
    if (s1->top_198 == -1)
        return;
    int b = s1->s[s1->top_198];
    printf("%d  ", b);
    pop_198(s1, &b);
    display_198(s1);
    push_198(s1, b);
}

//copying one stack to other
void copy_198(struct stack_198 *s1, struct stack_198 *s2)
{
    if (s1->top_198 == -1)
        return;
    int b = s1->s[s1->top_198];
    pop_198(s1, &b);
    copy_198(s1, s2);
    push_198(s2, b);
    push_198(s1, b);
}

int main()
{
    struct stack_198 s1, s2;
    s1.top_198 = -1;
    s2.top_198 = -1;
    int ch_198;
    int b = 0;
    int c_198 = 1;

    printf("1.Push element in stack\n");
    printf("2.Pop element from stack\n");
    printf("3.Display stack\n");
    printf("4.Copy one stack to other\n");
    printf("5.Sorting elements of stack\n");

    while (c_198)
    {
        printf("Enter your choice from 1-5\n");
        scanf("%d", &ch_198);

        switch (ch_198)
        {
        case 1:
            printf("Enter element to be inserted \n");
            int a;
            scanf("%d", &a);
            push_198(&s1, a);
            printf("The number is pushed sucessfully\n");
            break;

        case 2:
            pop_198(&s1, &b);
            printf("The number is popped sucessfully\n");
            break;

        case 3:
            printf("The stack is\n");
            display_198(&s1);
            break;

        case 4:
            copy_198(&s1, &s2);
            printf("The copied stack is\n");
            display_198(&s2);
            break;

        case 5:
            sorting_198(&s1);
            printf("The sorted stack is\n");
            display_198(&s1);
            break;

        default:
            printf("invalid choice");
        }
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &c_198);

        if (c_198 == 0)
        {
            break;
        }
    }
    printf("The program is terminated !!\n");

    return 0;
}
