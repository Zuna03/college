#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file_198("que6.txt");
    char ch;
    if (!file_198)
    {
        cout << "Error in opening source file_198..!!";
    }
    while (file_198.get(ch))
    {
        if (ch == ' ')
            cout << " ";
        else if (ch >= 'a' && ch <= 'z')
            ch = toupper(ch);
        else
            ch = tolower(ch);
        cout << ch;
    }
    cout << endl;
    cout << "File has been converted  successfully !" << endl;
    file_198.close();

    return 0;
}