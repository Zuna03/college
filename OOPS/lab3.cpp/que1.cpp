#include <bits/stdc++.h>
using namespace std;

float area_198(int r_198)
{
    return 3.14 * r_198 * r_198;
}

float area_198(int l_198, int b_198)
{
    return l_198 * b_198;
}

float area_198(int a_198, int b_198, int c_198)
{
    int s_198 = (a_198 + b_198 + c_198) / 2;
    return sqrt(s_198 * (s_198 - a_198) * (s_198 - b_198) * (s_198 - c_198));
}

int main()
{
    cout << "Enter radius of the circle:-" << endl;
    int r_198;
    cin >> r_198;

    cout << "Enter length and bredth of reactangle:-" << endl;
    int l_198, br_198;
    cin >> l_198 >> br_198;

    cout << "Enter three sides of triangle:-" << endl;
    int a_198, b_198, c_198;
    cin >> a_198 >> b_198 >> c_198;

    cout << "area_198 of circle is :- " << area_198(r_198) << endl;
    cout << "area_198 of reactangle  is :- " << area_198(l_198, br_198) << endl;
    cout << "area_198 of triangle is :- " << area_198(a_198, b_198, c_198) << endl;
    return 0;
}