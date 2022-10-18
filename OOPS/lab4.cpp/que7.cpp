#include <bits/stdc++.h>
using namespace std;

class db_198;

class dm_198
{
    float metres_198;
    float centimetres_198;

public:
    class dm_198 getData(float m1_198, float cm1_198)
    {
        metres_198 = m1_198;
        centimetres_198 = cm1_198;
    }
    friend class dm_198 add1(dm_198 d1_198, db_198 d2_198);
    friend class db_198 add2(dm_198 d1_198, db_198 d2_198);

    void display1_198()
    {
        cout << "Distance is " << metres_198 << " metres and " << centimetres_198 << " centimetres " << endl;
    }
};

class db_198
{
    float feet_198;
    float inches_198;

public:
    class dm_198 getData(float f1_198, float i1_198)
    {
        feet_198 = f1_198;
        inches_198 = i1_198;
    }
    friend class dm_198 add1(dm_198 d1_198, db_198 d2_198);
    friend class db_198 add2(dm_198 d1_198, db_198 d2_198);

    void display2_198()
    {
        cout << "Distance is " << feet_198 << " feets and " << inches_198 << " inches " << endl;
    }
};

class dm_198 add1(dm_198 d1_198, db_198 d2_198)
{
    float ans1_198 = d1_198.metres_198 * 100 + d1_198.centimetres_198 + d2_198.feet_198 * 30.48 + d2_198.inches_198 * 2.54;
    dm_198 ans1;
    ans1.metres_198 = ans1_198 / 100;
    ans1.centimetres_198 = int(ans1_198) % 100;

    return ans1;
}

class db_198 add2(dm_198 d1_198, db_198 d2_198)
{
    float ans2_198 = d1_198.metres_198 * 39.3701 + d1_198.centimetres_198 * 0.393701 + d2_198.inches_198 + d2_198.feet_198 * 12;
    db_198 ans2;
    ans2.feet_198 = ans2_198 / 12;
    ans2.inches_198 = int(ans2_198) % 12;

    return ans2;
}
int main()
{
    float Metres_198;
    float Centimetres_198;
    float Feet_198;
    float Inches_198;

    cout << "Enter first distance in metres and centimetres :- " << endl;
    cin >> Metres_198 >> Centimetres_198;

    cout << "Enter second distance in feets and inches :- " << endl;
    cin >> Feet_198 >> Inches_198;

    dm_198 d1_198;
    db_198 d2_198;

    d1_198.getData(Metres_198, Centimetres_198);
    d2_198.getData(Feet_198, Inches_198);

    cout << "Enter 1 for displaying and in m and cm and 0 for displaying in feets and inches :- " << endl;
    bool x_198;
    cin >> x_198;

    if (x_198 == 1)
    {
        dm_198 ans1 = add1(d1_198, d2_198);
        ans1.display1_198();
    }
    else
    {
        db_198 ans2_198 = add2(d1_198, d2_198);
        ans2_198.display2_198();
    }

    return 0;
}