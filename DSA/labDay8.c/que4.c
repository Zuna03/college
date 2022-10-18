#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack_198
{
    int top_198;
    int capacity_198;
    int *arr_198;
};

//creating stack
struct stack_198 *create_198(int capacity_198)
{
    struct stack_198 *st = (struct stack_198 *)malloc(sizeof(struct stack_198));

    if (!st)
        return NULL;

    st->top_198 = -1;
    st->capacity_198 = capacity_198;

    st->arr_198 = (int *)malloc(st->capacity_198 * sizeof(int));

    return st;
}

//checking if the satck is empty
int isEmpty_198(struct stack_198 *st)
{
    return st->top_198 == -1;
}

//finding top element of stack
char peek_198(struct stack_198 *st)
{
    return st->arr_198[st->top_198];
}

//popping element from stack
char pop_198(struct stack_198 *st)
{
    if (!isEmpty_198(st))
        return st->arr_198[st->top_198--];
    return '0';
}

//pushing element to stack
void push_198(struct stack_198 *st, char op)
{
    st->arr_198[++st->top_198] = op;
}

//  to check if the given character is operand
int isOperand_198(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

//to check higher precedence_198
int precedence_198(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    else
        return -1;
}

// converting given infix expression to postfix expression.
void infixToPostfix_198(char *exp)
{
    int i, k;

    // create_198 a st of capacity equal to expression size
    struct stack_198 *st = create_198(strlen(exp));
    if (!st) // See if st was created successfully
        return ;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output.
        if (isOperand_198(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an '(', push_198 it to the st.
        else if (exp[i] == '(')
            push_198(st, exp[i]);

        // If the scanned character is an ')', pop the st until an '(' is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty_198(st) && peek_198(st) != '(')
                exp[++k] = pop_198(st);
            if (!isEmpty_198(st) && peek_198(st) != '(')
                return ; // invalid expression
            else
                pop_198(st);
        }
        else // an operator is encountered
        {
            while (!isEmpty_198(st) &&
                   precedence_198(exp[i]) <= precedence_198(peek_198(st)))
                exp[++k] = pop_198(st);
            push_198(st, exp[i]);
        }
    }

    // pop all the operators from the st
    while (!isEmpty_198(st))
        exp[++k] = pop_198(st);

    exp[++k] = '\0';
    printf("%s", exp);
}

// Driver program to test above functions
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix_198(exp);
    return 0;
}