#include <bits/stdc++.h>
using namespace std;

class shape
{
public:
    void display(double res)
    {
        cout << "Area is: " << res << endl;
    }
};

class dimension2 : public shape
{
public:
    double length;
    double bredth;
    double raduis;
};

class dimension3 : public shape
{
public:
    double height2;
    double raduis2;
    double raduis3;
};
class rectangle : public dimension2
{

    double res;

public:
    rectangle(int l, int b)
    {
        length = l;
        bredth = b;
    }
    void calcArea()
    {
        res = length * bredth;
    }
    void display()
    {
        shape::display(res);
    }
};

class circle : public dimension2
{
    double res;

public:
    circle(int r)
    {
        raduis = r;
    }
    void calc()
    {
        res = 3.14 * raduis * raduis;
    }
    void display()
    {
        shape::display(res);
    }
};

class cyclinder : public dimension3
{
    double res1;
    double res2;

public:
    cyclinder(int r, int h)
    {
        raduis2 = r;
        height2 = h;
    }
    void calc()
    {
        res1 = (2 * 3.14 * raduis2 * height2) + (2 * 3.14 * raduis2 * raduis2);
        res2 = 3.14 * raduis2 * raduis2 * height2;
    }
    void display()
    {
        shape::display(res2);
        cout << "Surface area is :" << res1 << endl;
    }
};

class sphere : public dimension3
{
    double res1;
    double res2;

public:
    sphere(int r)
    {
        raduis3 = r;
    }
    void calc()
    {
        res1 = (4 / 3) * 3.14 * raduis3 * raduis3 * raduis3;
        res2 = 4 * 3.14 * raduis3 * raduis3;
    }
    void display()
    {
        shape::display(res2);
        cout << "Vol is :" << res1 << endl;
    }
};
int main()
{
    cout<<"Enter length and bredth\n";
    int l,b;
    cin>>l>>b;

    cout<<"Enter raduis of circler"<<endl;
    double r
    rectangle r;
    cyclinder c;
    sphere s;
    circle ci;


    return 0;
}