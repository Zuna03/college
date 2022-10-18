#include <bits/stdc++.h>
using namespace std;

template <class T_198>
class test
{
    T_198 num1_198, num2_198;

public:
    test(T_198 a, T_198 b)
    {
        num1_198 = a;
        num2_198 = b;
    }
    void sum_198()
    {
        cout << "The sum is : " << num1_198 + num2_198 << endl;
    }
};
int main()
{
    test<int> t(3, 4);
    t.sum_198();

    test<float> t2(3.7, 4.4);
    t2.sum_198();

    return 0;
}