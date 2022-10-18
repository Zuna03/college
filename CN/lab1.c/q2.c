#include <stdio.h>

struct info
{
    int rollno;
    char *name;
    float cgpa;
};
struct info assignVal(int x, char *n, float c)
{
    struct info i;
    i.rollno = x;
    i.name = n;
    i.cgpa = c;

    return i;
}

void print(struct info *i)
{
    printf("Roll : %d\n", i->rollno);
    printf("Name: %s\n", i->name);
    printf("CGPA : %f\n", i->cgpa);
}

int main()
{
    struct info i = assignVal(198, "Shivangi", 9.8);

    print(&i);

    return 0;
}