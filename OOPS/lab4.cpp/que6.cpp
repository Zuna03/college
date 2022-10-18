#include <bits/stdc++.h>
using namespace std;

class num2_198;

class num1_198
{
    int data1_198;

public:
    void getData1_198(int n1_198)
    {
        data1_198 = n1_198;
    }

    int compare_198(num2_198 n2_198);
    ;
};

class num2_198
{
    int data2_198;

public:
    void getData2_198(int n2_198)
    {
        data2_198 = n2_198;
    }
    friend int num1_198::compare_198(num2_198 n2_198);
};

int num1_198::compare_198(num2_198 n2_198)
{
    int ans1_198 = (n2_198.data2_198 > data1_198) ? n2_198.data2_198 : data1_198;
    return ans1_198;
}
int main()
{
    num1_198 n1_198;
    num2_198 n2_198;

    cout << "Enter two numbers :- " << endl;
    int data1_198, data2_198;
    cin >> data1_198 >> data2_198;

    n1_198.getData1_198(data1_198);
    n2_198.getData2_198(data2_198);

    cout << "The greatest of two numbers is :- " << n1_198.compare_198(n2_198) << endl;

    return 0;
}