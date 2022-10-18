//Implement four D-queues in an array
#include <stdio.h>
#include <stdlib.h>
void InsertRight(int *, int, int *, int *);
void InsertLeft(int *, int, int *, int *);
void DeleteLeft(int *, int, int *, int *);
void DeleteRight(int *, int, int *, int *);
void Display(int *, int, int, int);
void Input(int *, int, int *, int *);
void Output(int *, int, int *, int *);
int main()
{
    int i;
    int *p[4];
    int size[4];
    int left[4], right[4];
    int c;
    for (i = 0; i < 4; i++)
    {
        int n;
        printf("Enter the size of %d-subarray ", i + 1);
        scanf("%d", &n);
        size[i] = n;
        p[i] = (int *)malloc(n * sizeof(int));
        left[i] = -1;
        right[i] = -1;
    }
    char ch;
q:
    printf("Enter which sub-array you want to work with :");
    scanf("%d", &c);
    int Option = 0;
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("Enter your choice : ");
    scanf("%d", &Option);
    switch (Option)
    {
    case 1:
        Input(p[c], size[c], &left[c], &right[c]);
        break;
    case 2:
        Output(p[c], size[c], &left[c], &right[c]);
        break;
    default:
        printf("Wrong Option\n");
    }
    printf("Do you want to continue ?(y/n)");
    scanf("%s", &ch);
    if (ch == 'y' || ch == 'Y')
        goto q;
    else
        exit(0);
}
void Input(int *a, int n, int *l, int *r)
{
    int Option = 0;
    do
    {
        printf("1.Insert at Right\n");
        printf("2.Delete from Left\n");
        printf("3.Delete from Right\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &Option);
        switch (Option)
        {
        case 1:
            InsertRight(a, n, l, r);
            break;
        case 2:
            DeleteLeft(a, n, l, r);
            break;
        case 3:
            DeleteRight(a, n, l, r);
            break;
        case 4:
            Display(a, n, *l, *r);
            break;
        case 5:
            break;
        default:
            printf("Wrong Option\n");
        }
    } while (Option != 5);
}
void Output(int *a, int n, int *l, int *r)
{
    int Option = 0;
    do
    {
        printf("1.Insert at Right\n");
        printf("2.Insert at Left\n");
        printf("3.Delete from Left\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &Option);
        switch (Option)
        {
        case 1:
            InsertRight(a, n, l, r);
            break;
        case 2:
            InsertLeft(a, n, l, r);
            break;
        case 3:
            DeleteLeft(a, n, l, r);
            break;
        case 4:
            Display(a, n, *l, *r);
            break;
        case 5:
            break;
        default:
            printf("Wrong Option\n");
        }
    } while (Option != 5);
}
void InsertRight(int *a, int n, int *l, int *r)
{
    int added_item;
    if ((*l == 0 && *r == n - 1) || (*l == *r + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (*l == -1)
    {
        *l = 0;
        *r = 0;
    }
    else
    {
        if (*r == n - 1)
            *r = 0;
        else
            *r = *r + 1;
    }
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    a[*r] = added_item;
}
void InsertLeft(int *a, int n, int *l, int *r)
{
    int added_item;
    if ((*l == 0 && *r == n - 1) || (*l == *r + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (*l == -1)
    {
        *l = 0;
        *r = 0;
    }
    else
    {
        if (*l == 0)
            *l = n - 1;
        else
            *l = *l - 1;
    }
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    a[*l] = added_item;
}
void DeleteLeft(int *a, int n, int *l, int *r)
{
    if (*l == -1)
    {
        printf("Queue Under-flow\n");
        return;
    }
    printf("Element has been deleted from queue is : %d\n", a[*l]);
    if (*l == *r)
    {
        *l = -1;
        *r = -1;
    }
    else
    {
        if (*l == n - 1)
            *l = 0;
        else
            *l = *l + 1;
    }
}
void DeleteRight(int *a, int n, int *l, int *r)
{
    if (*l == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element has been deleted from queue is : %d\n", a[*r]);
    if (*l == *r)
    {
        *l = -1;
        *r = -1;
    }
    else
    {
        if (*r == 0)
            *r = n - 1;
        else
            *r = *r - 1;
    }
}
void Display(int *a, int n, int l, int r)
{
    int fpos = l, rpos = r;
    if (l == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (fpos <= rpos)

    {
        while (fpos <= rpos)
        {
            printf("%d ", a[fpos]);
            fpos++;
        }
    }
    else
    {
        while (fpos <= n - 1)
        {
            printf("%d ", a[fpos]);
            fpos++;
        }
        fpos = 0;
        while (fpos <= rpos)
        {
            printf("%d ", a[fpos]);
            fpos++;
        }
    }
    printf("\n");
}
