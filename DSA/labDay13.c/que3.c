#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node_198
{
    char data;
    struct node_198 *left_198;
    struct node_198 *right_198;
};

struct stack_198
{
    struct node_198 *val_198;
    struct stack_198 *next_198;
};

// func to check whether stack is empty or not
bool isEmpty_198(struct stack_198 *st)
{
    if (st == NULL)
        return true;
    else
        return false;
}

// func to push element in stack
void push_198(struct stack_198 **st, struct node_198 *nw)
{
    struct stack_198 *new = (struct stack_198 *)malloc(sizeof(struct stack_198));
    new->val_198 = nw;
    new->next_198 = *st;
    *st = new;
}

// func to pop element from stack
struct node_198 *pop_198(struct stack_198 **st)
{
    struct stack_198 *temp1;
    struct node_198 *pop_198ped;
    if (isEmpty_198(*st))
        return NULL;
    else
    {
        temp1 = *st;
        *st = (*st)->next_198;
        pop_198ped = temp1->val_198;
        free(temp1);
        return pop_198ped;
    }
}

// func to check if the character is operator or not
bool isOperator_198(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

// func to build new node
struct node_198 *makenode_198(char c)
{
    struct node_198 *root = (struct node_198 *)malloc(sizeof(struct node_198));
    root->data = c;
    root->right_198 = root->left_198 = NULL;

    return root;
}

// func to make expression tree from prefix expression
struct node_198 *makeprefix_198(char prefix_198[])
{
    struct stack_198 *st = NULL;

    struct node_198 *root;
    struct node_198 *popped1_198;
    struct node_198 *popped2_198;

    for (int i = strlen(prefix_198); i >= 0; i--)
    {
        if (!isOperator_198(prefix_198[i]))
        {
            root = makenode_198(prefix_198[i]);
            push_198(&st, root);
        }
        else
        {
            root = makenode_198(prefix_198[i]);
            popped1_198 = pop_198(&st);
            popped2_198 = pop_198(&st);

            root->right_198 = popped2_198;
            root->left_198 = popped1_198;

            push_198(&st, root);
        }
    }
    root = pop_198(&st);
    return root;
}

// func to travserse the tree in prefix manner
void prefixTraversal_198(struct node_198 *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    prefixTraversal_198(root->left_198);
    prefixTraversal_198(root->right_198);
}

// main func
int main()
{
    char prefix_198[] = {'-', '+', '7', '*', '4', '5', '+', '2', '0'};

    struct node_198 *ans = makeprefix_198(prefix_198);
    prefixTraversal_198(ans);

    return 0;
}