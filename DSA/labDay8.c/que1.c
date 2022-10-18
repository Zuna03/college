#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct stack_198
{
    int s[100];
    int top_198;
};

//checking if the stack is full
bool isFull_198(struct stack_198 *s1)
{
    if (s1->top_198 == 99)
    {
        return true;
    }
    return false;
}

//pushing element in stack
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

//popping element from stack
int pop_198(struct stack_198 *st)
{
    if (st->top_198 == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    int popped = st->s[st->top_198];
    st->top_198--;
    return popped;
}

//displaying elements of stack
void display_198(struct stack_198 *st)
{
    if (st->top_198 == -1)
        return;

    int y = st->s[st->top_198];
    printf("%d ", y);
    pop_198(st);
    display_198(st);
    push_198(st, y);
}

//finding lowest element of stack
int peekLowest_198(struct stack_198 *st)
{
    static int x = INT_MAX;
    if (st->top_198 != -1)
    {
        if (st->s[st->top_198] < x)
            x = st->s[st->top_198];

        int y = pop_198(st);
        peekLowest_198(st);
        push_198(st, y);
    }
    return x;
}

//finding highest element of stack
int peekHighest_198(struct stack_198 *st)
{
    static int y = INT_MIN;
    if (st->top_198 != -1)
    {
        if (st->s[st->top_198] > y)
            y = st->s[st->top_198];

        int z = pop_198(st);
        peekHighest_198(st);
        push_198(st, z);
    }
    return y;
}

//finding size of stack
int size_198(struct stack_198 *st)
{
    static int l = 0;
    if (st->top_198 == -1)
        return 1;

    int pop_198ped = pop_198(st);
    l++;
    size_198(st);
    push_198(st, pop_198ped);

    return l;
}

//finding middle element of stack
int peekMid_198(struct stack_198 *st, int len)
{
    static int found;
    static int count = 1;
    if (st->top_198 != -1)
    {
        if (count == len / 2 + 1)
        {
            found = st->s[st->top_198];
        }
        int pop_198ped = pop_198(st);
        count++;
        peekMid_198(st, len);
        push_198(st, pop_198ped);
    }

    return found;
}

//main function
int main()
{
    struct stack_198 st;
    st.top_198 = -1;

    int choice = 1;
    while (choice == 1)
    {
        printf("Enter element to be inserted \n");
        int a;
        scanf("%d", &a);
        push_198(&st, a);
        printf("The number is pushed sucessfully\n");

        printf("Do you want to enter more elements ? 1/0\n");
        scanf("%d", &choice);
        if (choice == 0)
            break;
    }

    printf("The stack_198 is :\n");
    display_198(&st);
    printf("\n");

    printf("1.Peek lowest element\n");
    printf("1.Peek highest element\n");
    printf("1.Peek middle element\n");

    int x = 1;
    int y = 1;

    int ans1, ans2, ans3, len;
    while (y)
    {
        printf("Enter a choice from 1-3");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            ans1 = peekLowest_198(&st);
            printf("Lowest element is : %d\n", ans1);
            break;

        case 2:
            ans2 = peekHighest_198(&st);
            printf("Highest element is : %d\n", ans2);
            break;

        case 3:
            len = size_198(&st);
            ans3 = peekMid_198(&st, len);
            printf("Middle element is :%d\n", ans3);

        default:
            break;
        }
        printf("Do you want to enter more elements ? 1/0\n");
        scanf("%d", &y);
        if (y == 0)
            break;
    }

    printf("The program is terminated !!\n");
    return 0;
}