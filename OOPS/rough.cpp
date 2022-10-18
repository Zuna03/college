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
    friend int swap(first &a, second &b);

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
    friend int swap(first &a, second &b);

    void display2()
    {
        cout << "m = " << data2 << endl;
    }
};

int swap(first &a, second &b)
{
    return  a.data1 > b.data2 ? a.data1 : b.data2;  
}

int main()
{
    cout << "Enter two numbers :- "<< endl;
    int n, m;
    cin >> n >> m;

    first a;
    a.putdata1(n);

    second b;
    b.putdata2(m);

    cout << "the numbers before swapping are :-" << endl;
    a.display1();
    b.display2();

    swap(a, b);
    cout << "the numbers after swapping are :-" << endl;
    a.display1();
    b.display2();

    return 0;
}