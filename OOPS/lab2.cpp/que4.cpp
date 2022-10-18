#include <bits/stdc++.h>
using namespace std;

class complexNum_198
{
    int real_198;
    int imag_198;

public:
    void getData_198(int reAl_198, int imAg_198)
    {

        for (int i_198 = 0; i_198 < 10; i_198++)
        {

            real_198 = reAl_198;
            imag_198 = imAg_198;
        }
    }

    void displayData_198()
    {

        cout << real_198 << " + " << imag_198 << " i " << endl;
    }
};
int main()
{
    complexNum_198 c_198[10];

    cout << "Enter real and imaginary parts of 10 complex numbers :-" << endl;

    for (int i_198 = 0; i_198 < 10; i_198++)
    {
        int reAl_198;
        int imAg_198;
        cin >> reAl_198 >> imAg_198;

        c_198[i_198].getData_198(reAl_198, imAg_198);
    }

    cout << "The complex numbers are :- " << endl;
    
    for (int i_198 = 0; i_198 < 10; i_198++)
    {
        c_198[i_198].displayData_198();
    }

    return 0;
}