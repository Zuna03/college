#include <bits/stdc++.h>
using namespace std;

class polynomial_198
{
    int coeff_198[10];
    int order_198;

public:
    void initialize_198();
    void get_order_198(int o);
    void create_198();
    void poly3_order_add_198(polynomial_198 p1, polynomial_198 p2);
    void poly3_order_multiply_198(polynomial_198 p1, polynomial_198 p2);
    void poly_add_198(polynomial_198 p1, polynomial_198 p2);
    void poly_multiply_198(polynomial_198 p1, polynomial_198 p2);
    void display_198();
};

void polynomial_198::initialize_198()
{
    order_198 = 0;
    for (int i = 0; i < 10; i++)
    {
        coeff_198[i] = 0;
    }
}

void polynomial_198::get_order_198(int o)
{
    order_198 = o;
}

void polynomial_198::create_198()
{
    for (int i = order_198; i >= 0; i--)
    {
        cout << "exponent : " << i << endl;
        cout << "coefficient :" << endl;
        cin >> coeff_198[i];
    }
}

void polynomial_198::poly3_order_add_198(polynomial_198 p1, polynomial_198 p2)
{
    order_198 = (p1.order_198 > p2.order_198) ? p1.order_198 : p2.order_198;
}

void polynomial_198::poly3_order_multiply_198(polynomial_198 p1, polynomial_198 p2)
{
    order_198 = p1.order_198 + p2.order_198;
}

void polynomial_198::poly_add_198(polynomial_198 p1, polynomial_198 p2)
{
    for (int i = order_198; i >= 0; i--)
    {
        coeff_198[i] = p1.coeff_198[i] + p2.coeff_198[i];
    }
}

void polynomial_198::poly_multiply_198(polynomial_198 p1, polynomial_198 p2)
{

    for (int i = 0; i <= p1.order_198; i++)
    {
        for (int j = 0; j <= p2.order_198; j++)
        {
            coeff_198[i + j] += (p1.coeff_198[i] * p2.coeff_198[j]);
        }
    }
}

void polynomial_198::display_198()
{
    for (int i = order_198; i >= 0; i--)
    {
        if (i == order_198)
            cout << coeff_198[i] << "x^" << i;
        else
        {
            if (coeff_198[i] >= 0)
                cout << "+";

            cout << coeff_198[i] << "x^" << i << " ";
        }
    }
    cout << "\n";
}
int main()
{
    polynomial_198 p1;
    p1.initialize_198();
    cout << "Enter the highest order:-\n";
    int o;
    cin >> o;
    p1.get_order_198(o);
    p1.create_198();

    polynomial_198 p2;
    p2.initialize_198();
    cout << "Enter the highest order :-\n";
    int o1;
    cin >> o1;
    p2.get_order_198(o1);
    p2.create_198();

    polynomial_198 p3;
    p3.poly3_order_add_198(p1, p2);
    p3.poly_add_198(p1, p2);

    cout << "First polynomial is :\n";
    p1.display_198();
    cout << "Second polynomial is :\n";
    p2.display_198();
    cout << "Sum of both polynomial is :\n";
    p3.display_198();

    polynomial_198 p4;
    p4.initialize_198();
    p4.poly3_order_multiply_198(p1, p2);
    p4.poly_multiply_198(p1, p2);
    cout << "Product of both polynomials is :\n";
    p4.display_198();

    return 0;
}