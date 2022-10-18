#include <bits/stdc++.h>
using namespace std;

class length
{
    int km, m, cm;

public:
    length()
    {
        km = 0;
        m = 0;
        cm = 0;
    }
    length(int a, int b, int c)
    {
        km = a;
        m = b;
        cm = c;
    }
    void display()
    {
        cout << km << "km " << m << "m " << cm << "cm " << endl;
    }

    bool operator==(length l2);
};

bool length::operator==(length l)
{
    int l1, l2;
    l1 = cm + (m * 100) + (km * 100000);
    l2 = l.cm + (l.m * 100) + (l.km * 100000);

    return (l1 == l2) ? true : false;
}
int main()
{
    length l1(10, 20, 30), l2(10, 200, 30);
    
    if (l1==l2)
    {
        cout << "Equal";
    }
    else
    {
        cout << "Unequal";
    }

    return 0;
}