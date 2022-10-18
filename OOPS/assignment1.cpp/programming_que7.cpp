#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b);

void reducefraction_198(int &x, int &y);

class fraction_198
{
    int num, den;

public:
    fraction_198()
    {
        num = 0;
        den = 1;
    }
    fraction_198(int n, int d)
    {
        num = n;
        den = d;
    }
    fraction_198 add_198(fraction_198 a)
    {
        fraction_198 temp;
        temp.den = lcm(den, a.den);
        temp.num = num * (temp.den / den) + a.num * (temp.den / a.den);

        return temp;
    }
    fraction_198 subtract_198(fraction_198 &a)
    {
        fraction_198 temp;
        temp.den = lcm(den, a.den);
        temp.num = num * (temp.den / den) - a.num * (temp.den / a.den);

        return temp;
    }
    fraction_198 multiply_198(fraction_198 *a)
    {
        fraction_198 temp;
        int u = a->den * den;
        int v = a->num * num;

        reducefraction_198(u, v);

        temp.num = v;
        temp.den = u;

        return temp;
    }
    void display()
    {
        cout << num << "/" << den << "\n";
    }
};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void reducefraction_198(int &x, int &y)
{
    int d;
    d = gcd(x, y);

    x = x / d;
    y = y / d;
}

int main()
{
    int f1n, f1d, f2n, f2d;
    cout << "Enter the numerator for fraction 1 :- ";
    cin >> f1n;
    cout << "Enter the denominator for fraction 1 :- ";
    cin >> f1d;
    fraction_198 f1(f1n, f1d);
    f1.display();
    cout << "Enter the numerator for fraction 2 :- ";
    cin >> f2n;
    cout << "Enter the denominator for fraction 2 :- ";
    cin >> f2d;
    fraction_198 f2(f2n, f2d);
    f2.display();

    fraction_198 add_198Ans = f1.add_198(f2);
    fraction_198 subAns = f1.subtract_198(f2);
    fraction_198 mulAns = f1.multiply_198(&f2);

    cout << "Result of add_198ition :- ";
    add_198Ans.display();

    cout << "Result of subtract_198ion :- ";
    subAns.display();

    cout << "Result of multiplication :- ";
    mulAns.display();

    return 0;
}