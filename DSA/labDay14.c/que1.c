#include <stdio.h>
#include <stdlib.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];

int delete_198 ()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
    }
}

void add_198(int item)
{
    if (rear == 19)
        printf("QUEUE FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}

void push_198(int item)
{
    if (top == 19)
        printf("Stack overflow ");
    else
        stack[++top] = item;
}

int pop_198()
{
    int k;
    if (top == -1)
        return (0);
    else
    {
        k = stack[top--];
        return (k);
    }
}
void BFS_198(int s, int n)
{
    int p, i;
    add_198(s);
    vis[s] = 1;
    p = delete_198 ();
    if (p != 0)
        printf(" % d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add_198(i);
                vis[i] = 1;
            }
        p = delete_198 ();
        if (p != 0)
            printf(" % d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            BFS_198(i, n);
}

void DFS_198(int s, int n)
{
    int i, k;
    push_198(s);
    vis[s] = 1;
    k = pop_198();
    if (k != 0)
        printf(" % d ", k);
    while (k != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[k][i] != 0) && (vis[i] == 0))
            {
                push_198(i);
                vis[i] = 1;
            }
        k = pop_198();
        if (k != 0)
            printf(" % d ", k);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            DFS_198(i, n);
}

int main()
{
    int n, i, s, ch, j;
    char c, dummy;
    printf("ENTER THE NUMBER VERTICES ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("ENTER 1 IF % d HAS A NODE WITH % d ELSE 0 ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("THE ADJACENCY MATRIX IS\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    do
    {
        for (i = 1; i <= n; i++)
            vis[i] = 0;
        printf("\nMENU");
        printf("\n1.B.F.S");
        printf("\n2.D.F.S");
        printf("\nENTER YOUR CHOICE");
        scanf("%d", &ch);
        printf("ENTER THE SOURCE VERTEX:");
        scanf("%d", &s);

        switch (ch)
        {
        case 1:
            BFS_198(s, n);
            printf("\n");
            break;
        case 2:
            DFS_198(s, n);
            printf("\n");
            break;
        }
        printf("DO U WANT TO CONTINUE(Y/N) ? ");
        scanf("%c", &dummy);
        scanf("%c", &c);
    } while ((c == 'y') || (c == 'Y'));

    printf("Program terminated successfully\n");
    return 0;
}
