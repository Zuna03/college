#include <bits/stdc++.h>
#include <math.h>
using namespace std;
class base
{
public:
    int num_198;
    void get_num()
    {
        cout << "Enter the Number: ";
        cin >> num_198;
    }
    virtual void convert() = 0;
    virtual void display() = 0;
};
class dec_198 : public base
{
    int decimal_198;

public:
    void convert()
    {
        decimal_198 = num_198 * 1.00;
    }
    void display()
    {
        cout << "Decimal:" << decimal_198 << endl;
    }
};
class hexadecimal_198 : public base
{
    char hex[100];

public:
    void convert()
    {
        itoa(num_198, hex, 16);
    }
    void display()
    {
        cout << "Hexadecimal: ";
        cout << hex;
    }
};

class octal_198 : public base
{
    char oct_198[100];
    int i = 0;
    int n = num_198;

public:
    void convert()
    {
        itoa(num_198, oct_198, 8);
    }
    void display()
    {
        cout << "Octal: ";
        cout << oct_198;
    }
};

int main()
{
    base *bptr_198;
    cout << "DECIMAL:\n";
    bptr_198 = new dec_198();
    bptr_198->get_num();
    bptr_198->convert();
    bptr_198->display();
    delete bptr_198;
    cout << "\n";

    cout << "HEXADECIMAL:\n";
    bptr_198 = new hexadecimal_198();
    bptr_198->get_num();
    bptr_198->convert();
    bptr_198->display();
    delete bptr_198;
    cout << "\n";

    cout << "OCTAL:\n";
    octal_198 O;
    bptr_198 = &O;
    bptr_198->get_num();
    bptr_198->convert();
    bptr_198->display();
    return 0;
}