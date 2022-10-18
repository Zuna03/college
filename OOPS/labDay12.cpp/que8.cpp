#include <bits/stdc++.h>
using namespace std;

void checkEMail_198(string s)
{
    int l = s.length();
    int check = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '@')
            check = 1;
    }
    if (check == 0)
        throw 1;

    string substring = s.substr(l - 4, l);
    string reqString = ".com";

    if (substring.compare(reqString) == 0)
        cout << "Yes the mail id is valid\n";
    else
        throw 1;
}
int main()
{
    int choice_198;
    string s;
    while (true)
    {
        cout << "Enter the mail id\n";
        cin >> s;

        try
        {
            checkEMail_198(s);
        }
        catch (int x)
        {
            cout << "Mail id is not valid exception thrown with " << x << endl;
        }
        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}