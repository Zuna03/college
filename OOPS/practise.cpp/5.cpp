#include <bits/stdc++.h>
using namespace std;

class space
{
    int x, y, z;

public:
    space()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    space(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void display()
    {
        cout << x << " " << y << " " << z << endl;
    }
    space operator-();
};

space space::operator-()
{
    x = -x;
    y = -y;
    z = -z;
    return *this;
}
int main()
{
    space s(10, 20, 30);
    s.display();
    -s;
    s.display();

    return 0;
}