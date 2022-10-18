#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice_198, a, b;
    while (true)
    {
        cout << "Enter two numbers : \n";
        cin >> a >> b;

        try
        {
            if (b == 0)
                throw 0;
            else
                cout << "The result is " << a / b << endl;
        }
        catch (int x)
        {
            cout << "Divison not possible exception thrown with " << x << endl;
        }
        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}