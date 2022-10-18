#include <bits/stdc++.h>
using namespace std;

class dm_198;

class df_198
{
    float feet_198, inches_198;

public:
    friend void displayBig_198(dm_198 obj1_198, df_198 obj2_198);
    void getData_198(float a_198, float b_198)
    {
        feet_198 = a_198;
        inches_198 = b_198;
    }
};
class dm_198
{
    float m_198, cm_198;

public:
    friend void displayBig_198(dm_198 obj1_198, df_198 obj2_198);
    void getData_198(float a_198, float b_198)
    {
        m_198 = a_198;
        cm_198 = b_198;
    }
};
void displayBig_198(dm_198 obj1_198, df_198 obj2_198)
{
    float obj1val_198 = obj1_198.m_198 * 100 + obj1_198.cm_198;
    float obj2val_198 = obj2_198.feet_198 * 12 * 2.54 + obj2_198.inches_198 * 2.54;
    if (obj1val_198 > obj2val_198)
    {
        cout << obj1_198.m_198 << "m " << obj1_198.cm_198 << "cm" << endl;
    }
    else
    {
        cout << obj2_198.feet_198 << "feet" << obj2_198.inches_198 << "inches" << endl;
    }
}
int main()
{
    dm_198 obj1_198;
    df_198 obj2_198;

    float f_198, i_198, M_198, CM_198;

    cout << "Enter distance in feets and inches " << endl;
    cin >> f_198 >> i_198;

    cout << "Enter the distance in metres and centimetres " << endl;
    cin >> M_198 >> CM_198;

    obj1_198.getData_198(M_198, CM_198);
    obj2_198.getData_198(f_198, i_198);

    cout << "The greater of the two distances is :- ";
    displayBig_198(obj1_198, obj2_198);

    return 0;
}