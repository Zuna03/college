#include <bits/stdc++.h>
using namespace std;

template <class T_198>
void swap_198(T_198 &a, T_198 &b)
{
     T_198 temp_198 = a;
     a = b;
     b = temp_198;
}
int main()
{
     int a = 4, b = 5;
     cout << "Num before swapping :\n";
     cout << a << " " << b << endl;
     swap_198(a, b);
     cout << "Num after swapping :\n";
     cout << a << " " << b << endl
          << endl;

     float c = 4.2, d = 6.7;
     cout << "Num before swapping :\n";
     cout << c << " " << d << endl;
     swap_198(c, d);
     cout << "Num after swapping :\n";
     cout << c << " " << d << endl
          << endl;

     char e = 'A', f = 'B';
     cout << "Char before swapping :\n";
     cout << e << " " << f << endl;
     swap_198(e, f);
     cout << "Char after swapping :\n";
     cout << e << " " << f << endl
          << endl;

     return 0;
}