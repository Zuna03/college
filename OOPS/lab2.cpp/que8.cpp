#include <bits/stdc++.h>
using namespace std;

class bankAcc_198
{
    string depName_198;
    int accNum_198;
    string accType_198;
    double balance_198;

public:
    void initial_198(string n_198, int a_198, string t_198, double b_198)
    {
        depName_198 = n_198;
        accNum_198 = a_198;
        accType_198 = t_198;
        balance_198 = b_198;
    }

    void deposit_198(double money_198)
    {
        balance_198 += money_198;
    }

    void withDraw(int amount_198)
    {
        if (balance_198 < amount_198 || balance_198 - amount_198 < 500) // corner case handled
        {
            cout << "insufficient amount to withdraw" << endl;
        }

        else
        {
            cout << endl
                 << endl;
            cout << "The balance is :- " << balance_198 << endl;
            balance_198 -= amount_198;
        }
    }

    void display_198()
    {
        cout << "Name of account holder :- " << depName_198 << endl;
        cout << "Final balance of account holder :- " << balance_198 << endl;
    }
};
int main()
{
    cout << "Enter bank details :- " << endl;
    string n_198;
    int a_198;
    string t_198;
    double b_198;

    cin >> n_198 >> a_198 >> t_198 >> b_198;

    bankAcc_198 d_198;

    d_198.initial_198(n_198, a_198, t_198, b_198);

    cout << "Enter the amount deposited :- " << endl;
    double money_198;
    cin >> money_198;
    d_198.deposit_198(money_198);

    cout << "Enter the amount withdrawn :- " << endl;
    int amount_198;
    cin >> amount_198;
    d_198.withDraw(amount_198);

    d_198.display_198();

    return 0;
}