#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int size_198 = 10;
    int choice_198, n;
    while (true)
    {
        cout << "Enter size of array : \n";
        cin >> n;
        try
        {
            if (n > size_198)
                throw -1;
            else
            {
                int arr_198[n];
                cout << "Enter elements of array : \n";
                for (int i = 0; i < n; i++)
                {
                    cin >> arr_198[i];
                }
                cout << "Elements of array : \n";
                for (int i = 0; i < n; i++)
                {
                    cout << arr_198[i] << " ";
                }
                cout << endl;
            }
        }
        catch (int x)
        {
            cout << "Array is out of bound with exception " << x << endl;
        }
        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}