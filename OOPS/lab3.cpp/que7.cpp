#include <bits/stdc++.h>
using namespace std;

int sum_198(int a_198, int b_198 = 10, int c_198 = 20)
{
    return a_198 + b_198 + c_198;
}

int main()
{
    cout << "Enter three numbers :-" << endl;

    int a_198, b_198, c_198;
    cin >> a_198 >> b_198 >> c_198;

    cout << sum_198(a_198, b_198, c_198) << endl;
    cout << sum_198(a_198, b_198) << endl;
    cout << sum_198(a_198) << endl;

    return 0;
}