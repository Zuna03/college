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
    comPlex operator+(comPlex c2);
};
comPlex comPlex::operator+(comPlex c2)
{
    comPlex c;
    c.real = real + c2.real;
    c.img = img + c2.img;

    return c;
}
int main()
{
    comPlex c1(10, 5), c2(8, 1), sum;
    c1.display();
    c2.display();

    sum = c1.operator+(c2);
    sum.display();

    return 0;
}