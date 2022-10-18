#include <bits/stdc++.h>
using namespace std;

class dIst_198
{
    int feets_198;
    int inches_198;

public:
    void getData_198(int feEts_198, int inChes_198)
    {
        feets_198 = feEts_198;
        inches_198 = inChes_198;
    }

    dIst_198 addDis_198(dIst_198 d_198)
    {
        dIst_198 temp_198;
        temp_198.inches_198 = inches_198 + d_198.inches_198;
        temp_198.feets_198 = feets_198+ d_198.feets_198+(temp_198.inches_198/12) ;
        temp_198.inches_198 %= 12;
        return temp_198;
    }

    void displayData_198()
    {
        cout << "The total distance is " << feets_198 << "\'"
             << " " << inches_198 << "\"";
    }
};
int main()
{
    dIst_198 c1_198, c2_198, c3_198;

    cout << "Enter the distance in heights and inches :- " << endl;

    int f1_198, i1_198, f2_198, i2_198;
    cin >> f1_198 >> i1_198 >> f2_198 >> i2_198;

    c1_198.getData_198(f1_198, i1_198);
    c2_198.getData_198(f2_198, i2_198);

    c3_198=c1_198.addDis_198(c2_198);
    c3_198.displayData_198();

    return 0;
}