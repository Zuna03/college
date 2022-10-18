#include <bits/stdc++.h>
using namespace std;

const int max_length = 10;
class bank
{
    string name;
    int acc_num;
    string acc_type;
    float bal_amt;

public:
    bank(string n, int a, string acc, float b)
    {
        n = name;
        acc_num = a;
        acc_type = acc;
        bal_amt = b;
    }
    void deposit(float amt)
    {
        bal_amt += amt;
        cout << "Total Balance : " << bal_amt << endl;
    }
    void withdraw(float amt)
    {
        if (bal_amt < 0)
            cout << "No money can't withdraw\n";
        else
        {
            bal_amt -= amt;
            cout << "Total Balance : " << bal_amt << endl;
        }
    }
    void display()
    {
        cout << "Name of the depositor : " << name;
        cout << "Balance of the depositor : " << bal_amt;
    }
};
int main()
{
    string n;
    int a;
    string acc;
    float b;
    cout << "Enter name of the depositor,account number,accout type and balance amount in acc\n";
    cin >> n >> a >> acc >> b;

    bank b1(n, a, acc, b);
    b1.display();

    float d_amt;
    cout << "Enter amount need be deposited\n";
    cin >> d_amt;
    b1.deposit(d_amt);

    float w_amt;
    cout << "Enter amount need be withdrawn\n";
    cin >> w_amt;
    b1.withdraw(w_amt);

    b1.display();

    return 0;
}