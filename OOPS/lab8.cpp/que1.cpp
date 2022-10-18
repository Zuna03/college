#include <bits/stdc++.h>
using namespace std;

class dist_198
{
    float feet_198;
    float inches_198;

public:
    dist_198()
    {
        feet_198 = 0;
        inches_198 = 0;
    }
    dist_198(int a, int b)
    {
        feet_198 = a;
        inches_198 = b;
    }

    dist_198 operator+(dist_198 d2);
    friend dist_198 operator+(int d1, dist_198 d2);
    void display_198()
    {
        cout << feet_198 << " feet " << inches_198 << " inches_198" << endl;
    }
};

dist_198 dist_198::operator+(dist_198 d2)
{
    dist_198 t;
    t.feet_198 = feet_198 + d2.feet_198;
    t.inches_198 = inches_198 + d2.inches_198;
    t.feet_198 += (int(t.inches_198 / 12));
    t.inches_198 = fmod(t.inches_198, 12);

    return t;
}

dist_198 operator+(int d1, dist_198 d2)
{
    dist_198 t;
    t.feet_198 = d2.feet_198;
    t.inches_198 = d1 + d2.inches_198;

    t.feet_198 += (int(t.inches_198 / 12));
    t.inches_198 = fmod(t.inches_198, 12);

    return t;
}

int main()
{
    dist_198 d1(5, 9), d2(7, 12), sum_198,sum2_198;
    sum_198=d1+d1;
    
    cout << "The two distances are :\n";
    d1.display_198();
    d2.display_198();

    cout << "The sum of distances is :\n";
    sum_198.display_198();

    sum2_198=3+d1;
    cout << "The sum of distances is :\n";
    sum2_198.display_198();

    return 0;
}