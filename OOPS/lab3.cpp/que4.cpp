#include <bits/stdc++.h>
using namespace std;

inline int sq(int n)
{
    return n*n;
}

inline int cube(int n)
{
    return n*n*n;
}
int main()
{
   cout<<"Enter num"<<endl;
   int n;
   cin>>n;

   cout<<"Sqaure of a num is :- "<<sq(n)<<endl;
   cout<<"Cube of a num is :- "<<cube(n)<<endl;
   return 0;
}