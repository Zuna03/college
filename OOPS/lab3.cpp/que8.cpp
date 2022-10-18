#include <bits/stdc++.h>
using namespace std;

void swap_by_value_198(int a_198, int b_198)
{
    int temp_198;
    temp_198 = a_198;
    a_198 = b_198;
    b_198 = temp_198;
}

void swap_by_reference_198(int &a_198, int &b_198)
{
    int temp_198 = a_198;
    a_198 = b_198;
    b_198 = temp_198;
}

void swap_by_address_198(int *a_198, int *b_198)
{
    int temp_198 = *a_198;
    *a_198 = *b_198;
    *b_198 = temp_198;
}

int main()
{
    cout << "Enter two numbers :-" << endl;
    int a_198, b_198;
    cin >> a_198 >> b_198;

    cout << "Before swapping a = " << a_198 << "and b = " << b_198 << endl;

    swap_by_value_198(a_198, b_198);
    cout << "By swap by value :- a = " << a_198 << " and b = " << b_198 << endl;

    swap_by_reference_198(a_198, b_198);
    cout << "By swap by reference :- a = " << a_198 << " and b = " << b_198 << endl;

    swap_by_address_198(&a_198, &b_198);
    cout << "By swap by adress :- a = " << a_198 << " and b = " << b_198 << endl;

    return 0;
}