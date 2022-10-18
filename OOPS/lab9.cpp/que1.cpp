#include <bits/stdc++.h>
using namespace std;

class shape_198
{
public:
    virtual void displayArea_198() = 0;
};

class circle_198 : public shape_198
{
    float raduis_198;

public:
    circle_198(float r)
    {
        raduis_198 = r;
    }
    void displayArea_198()
    {
        cout << "Area of circle is " << 3.14 * raduis_198 * raduis_198 << endl;
    }
};

class square_198 : public shape_198
{
    float side_198;

public:
    square_198(float s)
    {
        side_198 = s;
    }
    void displayArea_198()
    {
        cout << "Area of square is " << side_198 * side_198 << endl;
    }
};

class triangle_198 : public shape_198
{
    float bredth_198;
    float height_198;

public:
    triangle_198(float b, float h)
    {
        bredth_198 = b;
        height_198 = h;
    }
    void displayArea_198()
    {
        cout << "Area of triangle is " << 0.5 * bredth_198 * height_198 << endl;
    }
};

int main()
{
    cout << "Enter raduis of the circle \n";
    int r;
    cin >> r;
    circle_198 c(r);
    shape_198 *ptr = &c;
    ptr->displayArea_198();

    cout << "Enter side of the square \n";
    int s;
    cin >> s;
    square_198 sq(s);
    ptr = &sq;
    ptr->displayArea_198();

    cout << "Enter bredth_198 and height of triangle \n";
    int b, h;
    cin >> b >> h;
    triangle_198 t(b, h);
    ptr = &t;
    ptr->displayArea_198();

    return 0;
}
