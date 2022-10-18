#include <bits/stdc++.h>
using namespace std;

class second;

class first
{
    int data1;

public:
    void putdata1(int n)
    {
        data1 = n;
    }
    friend int greatest(first &a, second &b);

    void display1()
    {
        cout << "n = " << data1 << endl;
    }
};

class second
{
    int data2;

public:
    void putdata2(int m)
    {
        data2 = m;
    }
    friend int greatest(first &a, second &b);

    void display2()
    {
        cout << "m = " << data2 << endl;
    }
};

int greatest(first &a, second &b)
{
    return (a.data1 > b.data2) ? a.data1 : b.data2;
}

int main()
{
    cout << "Enter two numbers :- " << endl;
    int n, m;
    cin >> n >> m;

    first a;
    a.putdata1(n);
    cout << "First num is :\n";
    a.display1();

    second b;
    b.putdata2(m);
    cout << "Second num is :\n";
    b.display2();

    int ans = greatest(a, b);
    cout << "the greatest of two numbers are :" << ans << endl;

    return 0;
}