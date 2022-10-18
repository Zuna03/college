#include <bits/stdc++.h>
using namespace std;

class time_198
{
    int hour_198;
    int min_198;
    int sec_198;

public:
    time_198()
    {
        hour_198 = 0;
        min_198 = 0;
        sec_198 = 0;
    }
    time_198(int a, int b, int c)
    {
        hour_198 = a;
        min_198 = b;
        sec_198 = c;
    }
    void display()
    {
        cout << hour_198 << "hour " << min_198 << "min " << sec_198 << "sec" << endl;
    }
    time_198 operator++();
    friend time_198 operator++(time_198 t);
    time_198 operator++(int);
};
time_198 time_198::operator++()
{
    ++sec_198;
    min_198 = ++min_198 + (sec_198 / 60);
    hour_198 = ++hour_198 + (min_198 / 60);
    min_198 = min_198 % 60;
    sec_198 = sec_198 % 60;

    return *this;
}

time_198 operator++(time_198 t)
{
    time_198 t1;
    t1.sec_198 = ++t.sec_198;
    t1.min_198 = ++t.min_198 + (t1.sec_198 / 60);
    t1.hour_198 = ++t.hour_198 + (t1.min_198 / 60);
    t1.min_198 = t1.min_198 % 60;
    t1.sec_198 = t1.sec_198 % 60;

    return t1;
}

time_198 time_198::operator++(int)
{
    time_198 t;
    t.sec_198=sec_198++;
    t.min_198=t.min_198++;
    t.hour_198=t.hour_198++;

    return t;
}
int main()
{
    time_198 t1(10, 58, 59), t2(9, 38, 39), sum, sum2;
    t1.display();
    t2.display();
    sum.display();

    sum2 = operator++(t2);
    sum2.display();

    return 0;
}