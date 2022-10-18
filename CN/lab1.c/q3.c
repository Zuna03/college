#include <stdio.h>

int main()
{
    int n = 100;
    unsigned char *p = (unsigned char *)&n;
    for (size_t i = 0; i < sizeof(n); i++)
        printf("%x\n", p[i]);
    return 0;
}