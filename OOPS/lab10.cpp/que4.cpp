#include <bits/stdc++.h>
using namespace std;

template <class T_198>
void swap_198(T_198 &a, T_198 &b)
{
    T_198 temp_198 = a;
    a = b;
    b = temp_198;
}

template <class T_198, int size>
void Sort(T_198 arr_198[])
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr_198[j] > arr_198[j + 1])
                swap_198(arr_198[j], arr_198[j + 1]);
        }
    }
}
template <class T_198, int size>
void printArray(T_198 arr_198[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr_198[i] << " ";
    }
    printf("\n");
}

int main()
{
    int arr_198[] = {6, 1, 3, 10, 2};
    const int size1 = 5;

    Sort<int, size1>(arr_198);
    printf("the sorted array is : \n");
    printArray<int, size1>(arr_198);

    float arr2_198[] = {9.6, 11.8, 4.5};
    const int size2 = 3;
    Sort<float, size2>(arr2_198);
    printf("the sorted array is : \n");
    printArray<float, size2>(arr2_198);

    return 0;
}