
#include <iostream>
using namespace std;

class account_198
{
public:
    int acn_198, balance_198, minbal, wd_198, dp_198, bal_198;
    char name[25];
    void info()
    {
        cout << "Enter account number : ";
        cin >> acn_198;
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter balance_198 : ";
        cin >> balance_198;
        cout << "Enter amount to withdraw : ";
        cin >> wd_198;
        cout << "Enter amount to deposit : ";
        cin >> dp_198;
    }
    virtual void data() = 0;
    virtual void withdraw() = 0;
};
class savings_198 : public account_198
{
public:
    void withdraw()
    {
        minbal = 1000;
        bal_198 = balance_198 - wd_198 + dp_198;
        cout << "Minimum balance is : " << minbal << endl;
    }

    void data()
    {
        cout << "Account number : " << acn_198 << endl;
        cout << "Customer name : " << name << endl;
        if (bal_198 < minbal)
            cout << "You cannow withdraw below minimum balance, which is Rs. " << minbal << endl;
        else
            cout << "Balance is : " << bal_198 << endl;
    }
};
class current_198 : public account_198
{
public:
    void withdraw()
    {
        bal_198 = balance_198 - wd_198 + dp_198;
        cout << "Current balance is : " << bal_198 << endl;
    }
    void data()
    {
        cout << "Account number : " << acn_198 << endl;
        cout << "Customer name : " << name << endl;
        if (bal_198 < 0)
        {
            cout << "Amount Overdued." << endl;
        }
        else
        {
            cout << "Balance is : " << bal_198 << endl;
        }
    }
};

int main()
{
    int ch;
    savings_198 s;
    account_198 *as = &s;

    current_198 c;
    account_198 *ac = &c;

    while (1)
    {
        cout << "1. Savings" << endl;
        cout << "2. Current" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Savings Account." << endl;
            as->info();
            as->withdraw();
            as->data();
            break;

        case 2:
            cout << "Current Account." << endl;
            ac->info();
            ac->withdraw();
            ac->data();
            break;
        case 3:
            return 0;
        default:
            cout << "Wrong Choice!!" << endl;
        }
    }
}