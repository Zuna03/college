#include <bits/stdc++.h>
using namespace std;

float product(int a,int b)
{
    return a*b;
}

float product(int a,int b,int c)
{
    return a*b*c;
}
   
float product(int a,int b,int c,int d)
{
    return a*b*c*d;
}
  
int main()
{
    cout<<"Enter 4 numbers :-\n";
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    cout<<product(a,b)<<endl;
    cout<<product(a,b,c)<<endl;
    cout<<product(a,b,c,d);

   return 0;
}