#include <bits/stdc++.h>

using namespace std;

float area_198(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float area_198(float a, float b)
{
    return 0.5 * (sqrt(pow(a, 2) + pow(b, 4) / 4) * b);
}

float area_198(float a)
{
    return (sqrt(3) / 4.0) * pow(a, 2);
}

int main()
{
    float a, b, c;
    cout << "Enter the sides of scalene triangle :-\n";
    cin >> a >> b >> c;
    cout << "area of scalene triangle is " << area_198(a, b, c) << ".\n";

    cout << "Enter the sides of isosceles triangle :-\n";
    cin >> a >> b;
    cout << "area of isosceles triangle is " << area_198(a, b) << ".\n";

    cout << "Enter the sides of equilateral triangle :-\n";
    cin >> a;
    cout << "area of equilateral triangle is " << area_198(a) << ".\n";

    return 0;
}