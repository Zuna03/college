#include <bits/stdc++.h>
using namespace std;

class complex_198
{
    int real_198;
    int img_198;

public:
    complex_198()
    {
        real_198 = 0;
        img_198 = 0;
    }
    complex_198(int r, int i)
    {
        real_198 = r;
        img_198 = i;
    }
    bool operator==(complex_198 c)
    {
        if (real_198 == c.real_198 && img_198 == c.img_198)
            return true;
        else
            return false;
    }
};

int main()
{
    complex_198 c1(1, 2), c2(1, 2);
    if (c1 == c2)
        cout << "Equal";
    else
        cout << "Unequal";

    return 0;
}