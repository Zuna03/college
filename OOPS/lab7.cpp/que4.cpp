#include <bits/stdc++.h>
using namespace std;

class shape_198
{
protected:
    float area;

public:
    void display_198()
    {
        cout << "Area is : " << area << endl;
    }
};

class circle_198 : public shape_198
{
    int radius;

public:
    circle_198(int r)
    {
        radius = r;
    }
    void calculate()
    {
        area = 3.14 * radius * radius;
    }
};

class triangle_198 : public shape_198
{
    int side1;
    int side2;
    int side3;

public:
    triangle_198(int a, int b, int c)
    {
        side1 = a;
        side2 = b;
        side3 = c;
    }
    void calculate()
    {
        int s = (side1 + side2 + side3) / 2;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

class reactangle_198 : public shape_198
{
    int length;
    int bredth;

public:
    reactangle_198(int l, int b)
    {
        length = l;
        bredth = b;
    }
    void calculate()
    {
        area = length * bredth;
    }
};
int main()
{
    cout << "Enter radius of circle:\n";
    int r;
    cin >> r;
    circle_198 ci(r);
    ci.calculate();
    ci.display_198();

    cout << "Enter three sides of triangle :\n";
    int a, b, c;
    cin >> a >> b >> c;
    triangle_198 t(a, b, c);
    t.calculate();
    t.display_198();

    cout << "Enter length and bredth of rectangle :\n";
    int le, br;
    cin >> le >> br;
    reactangle_198 re(le, br);
    re.calculate();
    re.display_198();

    return 0;
}