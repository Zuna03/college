#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top_198 = -1;

int isEmpty_198()
{

    if (top_198 == -1)
        return 1;
    else
        return 0;
}

int isFull_198()
{

    if (top_198 == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek_198()
{
    return stack[top_198];
}

int pop_198()
{
    int data;

    if (!isEmpty_198())
    {
        data = stack[top_198];
        top_198 = top_198 - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push_198(int data)
{

    if (!isFull_198())
    {
        top_198 = top_198 + 1;
        stack[top_198] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

int main()
{
    // push_198 items on to the stack
    push_198(3);
    push_198(5);
    push_198(9);
    push_198(1);
    push_198(12);
    push_198(15);

    printf("Element at top of the stack: %d\n", peek_198());
    printf("Elements: \n");

    // print stack data
    while (!isEmpty_198())
    {
        int data = pop_198();
        printf("%d ", data);
    }
    printf("\n");
    printf("Stack full: %s\n", isFull_198() ? "true" : "false");
    printf("Stack empty: %s\n", isEmpty_198() ? "true" : "false");

    return 0;
}