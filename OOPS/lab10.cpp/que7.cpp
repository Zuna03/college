#include <bits/stdc++.h>
using namespace std;

template <class T_198>
class pAir
{
    T_198 num1_198, num2_198;

public:
    pAir()
    {
        cout << "Enter two data members : ";
        cin >> num1_198 >> num2_198;
    }
    T_198 getMax_198()
    {
        return num1_198 > num2_198 ? num1_198 : num2_198;
    }
};
int main()
{
    pAir<int> ob;
    cout << "The greatest of two data-types is : " << ob.getMax_198();
    cout << endl;

    pAir<float> ob2;
    cout << "The greatest of two data-types is : " << ob2.getMax_198();
    cout << endl;
    return 0;
}