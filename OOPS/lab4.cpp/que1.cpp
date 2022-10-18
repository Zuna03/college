#include <bits/stdc++.h>
using namespace std;

class second_198;

class first_198
{
    int data1_198;

public:
    void putdata1_198(int n_198)
    {
        data1_198 = n_198;
    }
    friend void swap_198(first_198 &a_198, second_198 &b_198);

    void display1_198()
    {
        cout << "n_198 = " << data1_198 << endl;
    }
};

class second_198
{
    int data2_198;

public:
    void putdata2_198(int m_198)
    {
        data2_198 = m_198;
    }
    friend void swap_198(first_198 &a, second_198 &b);

    void display2_198()
    {
        cout << "m_198 = " << data2_198 << endl;
    }
};

void swap_198(first_198 &a_198, second_198 &b)
{
    int temp_198 = a_198.data1_198;
    a_198.data1_198 = b.data2_198;
    b.data2_198 = temp_198;
}

int main()
{
    cout << "Enter two numbers :- "<< endl;
    int n_198, m_198;
    cin >> n_198 >> m_198;

    first_198 a_198;
    a_198.putdata1_198(n_198);

    second_198 b_198;
    b_198.putdata2_198(m_198);

    cout << "the numbers before swapping are :-" << endl;
    a_198.display1_198();
    b_198.display2_198();

    swap_198(a_198, b_198);
    cout << "the numbers after swapping are :-" << endl;
    a_198.display1_198();
    b_198.display2_198();

    return 0;
}