#include <bits/stdc++.h>
using namespace std;

class dist
{
    float feet, inches;

public:
    dist()
    {
        feet = 0;
        inches = 0;
    }
    dist(int a, int b)
    {
        feet = a;
        inches = b;
    }

    bool operator>(dist d2);
    void display()
    {
        cout << feet << "feet " << inches << "inches" << endl;
    }
};

bool dist::operator>(dist d2)
{
    float t1, t2;
    t1 = feet + inches / 12.0;
    t2 = d2.feet + d2.inches / 12.0;

    return (t1 > t2) ? true : false;
}
int main()
{
    dist d1(50, 7), d2(7, 11);
    if (d1 > d2)
    {
        cout << "d1 is more";
    }
    else
    {
        cout << "d2 is more";
    }
    return 0;
}