#include <bits/stdc++.h>
using namespace std;

template <class T_198>
bool seaRch(T_198 arr_198[], T_198 key_198, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr_198[i] == key_198)
            return true;
    }
    return false;
}
int main()
{
    int arr_1981[] = {1, 4, 9, 20, 11};
    int size1 = 5;
    int key_1981 = 1;

    if (seaRch(arr_1981, key_1981, size1))
        cout << "Yes the element is found" << endl;
    else
        cout << "No the element is not found" << endl;

    char arr2_198[] = {'a', 'b', 'c'};
    int size2 = 3;
    char key_1982 = 'c';
    if (seaRch(arr2_198, key_1982, size2))
        cout << "Yes the element is found" << endl;
    else
        cout << "No the element is not found" << endl;

    double arr3_198[] = {4.567, 9.45, 8.654};
    int size3 = 3;
    double key_1983 = 4.568;
    if (seaRch(arr3_198, key_1983, size3))
        cout << "Yes the element is found" << endl;
    else
        cout << "No the element is not found" << endl;
    return 0;
}