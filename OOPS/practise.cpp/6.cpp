#include <bits/stdc++.h>
using namespace std;

class tIme
{
    int hour;
    int min;
    int sec;

public:
    tIme()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    tIme(int a, int b, int c)
    {
        hour = a;
        min = b;
        sec = c;
    }
    void display()
    {
        cout << hour << "hour " << min << "min " << sec << "sec " << endl;
    }
    tIme operator+(tIme t2);
};
tIme tIme::operator+(tIme t2)
{
    tIme t;
    t.sec = sec + t2.sec;
    t.min = min + t2.min + (sec / 60);
    t.hour = hour + t2.hour + (min / 60);
    min = min % 60;
    sec = sec % 60;

    return t;
}
int main()
{
    tIme t1(10, 20, 30), t2(9, 10, 0), sum;
    t1.display();
    t2.display();
    sum = t1.operator+(t2);
    sum.display();

    return 0;
}