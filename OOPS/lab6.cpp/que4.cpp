#include <bits/stdc++.h>
using namespace std;

class shape_198
{
protected:
    float area_198;

public:
    void display_198()
    {
        cout << "Area is : " << area_198 << endl;
    }
};

class circle_198 : public shape_198
{
    int radius;

public:
    void getRadius_198(int r)
    {
        radius = r;
    }
    void calculate_198()
    {
        area_198 = 3.14 * radius * radius;
    }
};

class triangle_198 : public shape_198
{
    int side1;
    int side2;
    int side3;

public:
    void getSides_198(int a, int b, int c)
    {
        side1 = a;
        side2 = b;
        side3 = c;
    }
    void calculate_198()
    {
        int s = (side1 + side2 + side3) / 2;
        area_198 = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

class reactangle_198 : public shape_198
{
    int length;
    int bredth;

public:
    void getTwoSides_198(int l, int b)
    {
        length = l;
        bredth = b;
    }
    void calculate_198()
    {
        area_198 = length * bredth;
    }
};
int main()
{
    cout << "Enter radius of circle :\n";
    int r;
    cin >> r;
    circle_198 ci;
    ci.getRadius_198(r);
    ci.calculate_198();
    ci.display_198();

    cout << "Enter three sides of triangle :\n";
    int a, b, c;
    cin >> a >> b >> c;
    triangle_198 t;
    t.getSides_198(a, b, c);
    t.calculate_198();
    t.display_198();

    cout << "Enter length and bredth of rectangle :\n";
    int le, br;
    cin >> le >> br;
    reactangle_198 re;
    re.getTwoSides_198(le, br);
    re.calculate_198();
    re.display_198();

    return 0;
}