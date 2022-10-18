#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    int count_even = 0;
    int count_odd = 0;

    cout << "enter the elements of the array\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            count_even++;
        }
        else
        {
            count_odd++;
        }
    }

    int *even = new int[count_even];
    int *odd = new int[count_odd];

    int j = 0, k = 0;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 == 0 )
        {
            even[j] = a[i];
            j++;
        }
        else if (a[i] % 2 != 0 )
        {
            odd[k] = a[i];
            k++;
        }
    }

    cout << "The even array is :-\n";
    for (int i = 0; i < count_even; i++)
    {
        cout << even[i] << " ";
    }
    cout << "\n";

    cout << "The odd array is :-\n";
    for (int i = 0; i < count_odd; i++)
    {
        cout << odd[i] << " ";
    }
    delete[] even;
    delete[] odd;

    return 0;
}