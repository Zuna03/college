#include <bits/stdc++.h>
using namespace std;

void calcExpiry_198(int ed, int em, int ey, int cd, int cm, int cy)
{
    if (ey == cy)
    {
        if (em == cm)
        {
            if (ed < cd)
                throw 1;
            else
                cout << "No the medicine are not expiry\n";
        }
        else if (em > cm)
            cout << "No the medicine are not expiry\n";
        else
            throw 1;
    }
    else if (ey < cy)
        throw 1;

    else
        cout << "No the medicine are not expiry\n";
}
int main()
{
    int choice_198, ed, em, ey, cd, cm, cy;
    while (true)
    {
        cout << "Enter expiry date,month,year\n";
        cin >> ed >> em >> ey;
        cout << "Enter current date,month,year\n";
        cin >> cd >> cm >> cy;
        try
        {
            calcExpiry_198(ed, em, ey, cd, cm, cy);
        }
        catch (int x)
        {
            cout << "Medicine is expiry exception thrown with " << x << endl;
        }
        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}