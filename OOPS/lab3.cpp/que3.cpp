#include <bits/stdc++.h>
using namespace std;

void print_198(char ch_198='*', int n_198=80)
{
    for (int i = 0; i < n_198; i++)
    {
        cout << ch_198 << " ";
    }
    cout << endl << endl;
}


int main()
{
    cout << "Enter the num:-" << endl;
    int n_198;
    cin >> n_198;

    cout << "Enter the character" << endl;
    char ch_198;
    cin >> ch_198;

    print_198(ch_198, n_198);
    print_198(ch_198);
    print_198();

    return 0;
}