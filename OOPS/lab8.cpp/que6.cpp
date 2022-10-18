#include <bits/stdc++.h>
using namespace std;

class dist_198
{
    int m;
    int km;

public:
    dist_198()
    {
        m = 0;
        km = 0;
    }
    dist_198(int a, int b)
    {
        km = a;
        m = b;
    }

    bool operator==(dist_198 d)
    {
        int ans1 = m + km * 1000;
        int ans2 = d.m + d.km * 1000;

        if (ans1 == ans2)
            return true;
        else
            return false;
    }

    bool operator>(dist_198 d)
    {
        int ans1 = m + km * 1000;
        int ans2 = d.m + d.km * 1000;

        if (ans1 > ans2)
            return true;
        else
            return false;
    }
    void display()
    {
        cout << km << "km " << m << " m " << endl;
    }
};
int main()
{
    dist_198 d1_198(1, 900), d2_198(1, 900), d3;
    if (d1_198 == d2_198)
        cout << "Equal" << endl;
    else
        cout << "Unequal" << endl;

    dist_198 d4_198(1, 800), d5_198(1, 900);
    if (d4_198 > d5_198)
        d4_198.display();
    else
        d5_198.display();

    return 0;
}