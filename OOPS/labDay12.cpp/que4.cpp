#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice_198, choose_198;
    while (true)
    {
        try
        {
            cout << "Choose from below options :\n";
            cout << "1 for int\n";
            cout << "2 for float\n";
            cout << "3 for char\n";
            cout << "4 for others\n";

            cin >> choose_198;
            switch (choose_198)
            {
            case 1:
                throw 1;
                break;
            case 2:
                throw 1.1f;
                break;
            case 3:
                throw 'c';
                break;
            case 4:
                throw "error";
                break;

            default:
                break;
            }
        }
        catch (int x)
        {
            cout << "Exception thrown with int " << x << endl;
        }
        catch (float x)
        {
            cout << "Exception thrown with float " << x << endl;
        }
        catch (char x)
        {
            cout << "Exception thrown with char " << x << endl;
        }
        catch (...)
        {
            cout << "Exception thrown with other " << endl;
        }
        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}