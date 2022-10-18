#include <bits/stdc++.h>
using namespace std;

void func(int&,int&,int*);

int main()
{
    int a=10,b=20,c=30;
    func(a,b,&c);
    cout<<a<<" "<<b<<" "<<c;

   return 0;
}
void func(int &x,int &y,int *z)
{
    x=y;
    //cout<<x<<endl;
    y=x;
    // cout<<y<<endl;
    // cout<<x<<endl;
    *z=y;
    // cout<<z<<endl;
    // cout<<*z<<endl;
    // cout<<y;
}