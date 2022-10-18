#include <stdio.h>

struct que1
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct que1 assign(int a, int b, int c, int d, int e)
{
    struct que1 u;
    u.a = a;
    u.b = b;
    u.c = c;
    u.d = d;
    u.e = e;

    return u;
}

void display(struct que1 *u)
{
    printf("%d %d %d %d %d\n", u->a, u->b, u->c, u->d, u->e);
}

int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    struct que1 v = assign(a, b, c, d, e);
    display(&v);
    return 0;
}