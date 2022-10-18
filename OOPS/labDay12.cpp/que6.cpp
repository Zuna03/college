#include <bits/stdc++.h>
using namespace std;

void calcSquareRoot_198(int n)
{
    if (n < 0)
        throw -1;
    else
        cout << "Square Root of num is : " << sqrt(n) << endl;
}
int main()
{
    int choice_198, n;
    while (true)
    {
        cout << "Enter the num : \n";
        cin >> n;
        try
        {
            calcSquareRoot_198(n);
        }
        catch (int x)
        {
            cout << "Calculating square root not possible exception thrown with " << x << endl;
        }
        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}