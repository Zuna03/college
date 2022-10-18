#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack_198
{
    int data_198;
    struct stack_198 *next_198;
};

//pushing element in stack
void push(struct stack_198 **top_198, int n)
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

//popping element from stack_198
int pop_198(struct stack_198 **top_198)
{
    if (isEmpty_198(top_198) == true)
    {
        printf("The stack_198 is empty\n");
        return -1;
    }

    struct stack_198 *toDelete = (*top_198);
    (*top_198) = (*top_198)->next_198;
    int b = toDelete->data_198;
    free(toDelete);

    return b;
}

// Returns 1 if character1 and character2 are matching pairs
bool isMatching_198(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// Return 1 if expression has balanced Brackets
bool balanced_198(char exp[])
{

    // Declare an empty character stack_198
    struct stack_198 *stack_198 = NULL;

    for (int i = 0; exp[i]; i++)
    {
        // If the exp[i] is a opening bracket then push it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack_198, exp[i]);

        // If exp[i] is an ending bracket then pop from stack and check if the popped bracket is a matching pair
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {

            // If we see an ending bracket without a pair then return false
            if (stack_198 == NULL)
                return 0;

            // pop the top element from stack, if it is not a pair bracket of character then there is a mismatch.
            else if (!isMatching_198(pop_198(&stack_198), exp[i]))
                return 0;
        }
    }

    // If there is something left in expression then there is a starting bracket without a closing bracket
    if (stack_198 == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}

// Driver code
int main()
{
    char exp1[100] = "{()}[]";
    char exp2[100] = "{(}[]";

    // Function call
    if (balanced_198(exp1))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");

    if (balanced_198(exp2))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
