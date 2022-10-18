#include <bits/stdc++.h>
using namespace std;

class comPlex
{
    int img, real;

public:
    comPlex()
    {
        real = 0;
        img = 0;
    }
    comPlex(int a, int b)
    {
        real = a;
        img = b;
    }
    void display()
    {
        cout << real << " + " << img << "i" << endl;
    }
    friend comPlex operator+(int x, comPlex c2);
};
comPlex operator+(int x, comPlex c2)
{
    comPlex c;
    c.real = x + c2.real;
    c.img = x + c2.img;

    return c;
}
int main()
{
    comPlex c1(10, 5), sum;
    c1.display();

    sum = 5 + c1;
    sum.display();

    return 0;
}