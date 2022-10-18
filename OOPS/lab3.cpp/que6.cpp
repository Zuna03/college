#include <bits/stdc++.h>
using namespace std;

class comPlex_198
{
    int real_198;
    int imag_198;

public:
    void getData(int r_198, int i_198)
    {
        real_198 = r_198;
        imag_198 = i_198;
    }

    comPlex_198 add_198(int a_198, comPlex_198 s1_198)
    {
        comPlex_198 temp_198;
        temp_198.real_198 = a_198 + s1_198.real_198;
        temp_198.imag_198 = s1_198.imag_198;

        return temp_198;
    }

    comPlex_198 add_198(comPlex_198 s2_198, comPlex_198 s1_198)
    {
        comPlex_198 temp_198;
        temp_198.real_198 = s1_198.real_198 + s2_198.real_198;
        temp_198.imag_198 = s1_198.imag_198 + s2_198.imag_198;

        return temp_198;
    }

    void display()
    {
        cout << real_198 << "+" << imag_198 << "i";
    }
};

int main()
{
    comPlex_198 s1_198;
    comPlex_198 s2_198;
    comPlex_198 s3_198;

    int r1_198, i1_198;
    cout << "Enter real and imaginary part of  complex number" << endl;
    cin >> r1_198 >> i1_198;

        cout << "Enter a number" << endl;
    int n_198;
    cin >> n_198;

    s1_198.getData(r1_198, i1_198);
    s2_198 = s1_198.add_198(n_198, s1_198);
    cout << "The sum of two complex numbers is :- ";
    s2_198.display();
    cout << endl;

    s3_198 = s1_198.add_198(s1_198, s2_198);
    cout << "The sum of two complex numbers is :- ";
    s3_198.display();
    cout << endl;

    return 0;
}