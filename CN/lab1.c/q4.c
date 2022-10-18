// #include <stdio.h>

// struct pkt
// {
//     char ch1;
//     char ch2[2];
//     char ch3;
// };

// int main()
// {
//     int num = 69;
//     unsigned char *p = (unsigned char *)&num;
//     struct pkt i;
//     i.ch1 = p[0];
//     i.ch2[0] = p[1];
//     i.ch2[1] = p[2];
//     i.ch3 = p[3];

//     printf("%x %x %x %x\n", i.ch1, i.ch2[0], i.ch2[1], i.ch3);

//     return 0;
// }

#include <stdio.h>
struct pkt
{
    char ch1;
    char ch2[2];
    char ch3[2];
} p;
int main()
{
    printf("\nEnter 1st char : ");
    scanf("%c", &p.ch1);

    printf("\nEnter 2nd char : ");
    scanf("%s", &p.ch2);

    printf("\nEnter  3rd char : ");
    scanf("%s", &p.ch3);

    printf("\n1st char : %c\n2nd char : %s\n3rd char : %s\n", p.ch1, p.ch2, p.ch3);
}