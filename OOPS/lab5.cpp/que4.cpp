#include <bits/stdc++.h>
using namespace std;

class array_198
{
    int *arr_198;
    int n;

public:
    array_198();
    array_198(int num_198);
    array_198(int *a, int num_198);
    array_198(const array_198 &a);
    void show_data_198();
    void add_198(array_198 &a, array_198 &b);
    ~array_198()
    {
        cout<<"Here destructor is invoked\n";
    }
};

array_198::array_198()
{
    n = 1;
    arr_198 = new int[1];
    arr_198[0] = 1;
}

array_198 ::array_198(int num_198)
{
    n = num_198;
    arr_198 = new int[n];
    cout << "Enter elements of array_198\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr_198[i];
    }
}

array_198 ::array_198(int *a, int num_198)
{
    n = num_198;
    arr_198 = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr_198[i] = a[i];
    }
}

array_198::array_198(const array_198 &a)
{
    n = a.n;
    arr_198 = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr_198[i] = a.arr_198[i];
    }
}

void array_198 ::show_data_198()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr_198[i] << " ";
    }
    cout << endl;
}

void array_198::add_198(array_198 &a, array_198 &b)
{
    n = a.n + b.n;
    arr_198 = new int[n];
    for (int i = 0; i < a.n; i++)
    {
        arr_198[i] = a.arr_198[i];
    }
    int k = 0;
    for (int i = a.n; i < n; i++)
    {
        arr_198[i] = b.arr_198[k];
        k++;
    }
}
int main()
{
    int size1;
    cout << "Enter size of first array_198 :- " << endl;
    cin >> size1;

    array_198 a(size1);
    cout << "The elements of first array_198 are :- " << endl;
    a.show_data_198();

    int size2;
    cout << "Enter size of second array_198 :- " << endl;
    cin >> size2;

    array_198 b(size2);
    cout << "The elements of second array_198 are :- " << endl;
    b.show_data_198();

    array_198 c;
    c.add_198(a, b);
    cout << "The elements of resultant array_198 are :- " << endl;
    c.show_data_198();

    return 0;
}