#include <bits/stdc++.h>
using namespace std;

const int size = 3;
template <class T_198>
class vector_198
{
    T_198 *vec;

public:
    vector_198()
    {
        vec = new T_198[size];
        for (int i = 0; i < size; i++)
        {
            vec[i] = 0;
        }
    }
    vector_198(T_198 *a)
    {
        vec = new T_198[size];
        for (int i = 0; i < size; i++)
        {
            vec[i] = a[i];
        }
    }
    void modify_198(T_198 newValue, int idx)
    {
        vec[idx] = newValue;
    }
    void multiply_198(T_198 value)
    {
        for (int i = 0; i < size; i++)
        {
            vec[i] *= value;
        }
    }
    void display_198()
    {
        for (int i = 0; i < size; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int arr[] = {4, 6, 7};
    vector_198<int> v1(arr);
    cout << "The vector is : ";
    v1.display_198();

    int idx1_198 = 2;
    int modify1_198 = 10;
    v1.modify_198(modify1_198, idx1_198);
    cout << "The vector after modifying value is : ";
    v1.display_198();

    int scalar = 5;
    v1.multiply_198(scalar);
    cout << "The vector after multiplying with scalar is : ";
    v1.display_198();

    float arr2[] = {4.3, 6.9, 7.5};
    vector_198<float> v2(arr2);
    cout << "T8he vector is : ";
    v2.display_198();

    int idx2_198 = 0;
    float modify2_198 = 1.9;
    v2.modify_198(modify2_198, idx2_198);
    cout << "The vector after modifying value is : ";
    v2.display_198();

    float scalar2 = 1.1;
    v2.multiply_198(scalar2);
    cout << "The vector after multiplying with scalar is : ";
    v2.display_198();

    return 0;
}