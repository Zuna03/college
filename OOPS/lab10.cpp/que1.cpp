#include <bits/stdc++.h>
using namespace std;

template <class T_198>
T_198 minNum(T_198 arr_198[], int size)
{
   T_198 minFound_198 = arr_198[0];
   for (int i = 1; i < size; i++)
   {
      minFound_198 = min(arr_198[i], minFound_198);
   }
   return minFound_198;
}

int main()
{
   int arr_1981[] = {4, 11, 13, 10, 12};
   int size1 = 5;
   int minFound1_198 = minNum(arr_1981, size1);
   cout << "Min num found is : " << minFound1_198 << endl;

   float arr_1982[] = {3.4, 2.8, 9.1, 3.1};
   int size2 = 4;
   float minFound2_198 = minNum(arr_1982, size2);
   cout << "Min num found is : " << minFound2_198 << endl;

     return 0;
}