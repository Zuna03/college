#include <bits/stdc++.h>
using namespace std;

class array_198
{
    int n;
    int *arr_198;

public:
    array_198()
    {
        n = 0;
    }
    array_198(int size_198)
    {
        n = size_198;
        arr_198 = new int[n];
    }
    friend istream &operator>>(istream &in, array_198 a);
    friend ostream &operator<<(ostream &out, array_198 a);
};
istream &operator>>(istream &in, array_198 a)
{
    cout << "Enter elements of array :\n";
    for (int i = 0; i < a.n; i++)
    {
        in >> a.arr_198[i];
    }
    cout << endl;
    return in;
}
ostream &operator<<(ostream &out, array_198 a)
{

    cout << "Elements of array are :\n";
    for (int i = 0; i < a.n; i++)
    {
        out << a.arr_198[i] << " ";
    }
    cout << endl;
    return out;
}
int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    array_198 a_198(n);
    cin >> a_198;
    cout << a_198;

    return 0;
}