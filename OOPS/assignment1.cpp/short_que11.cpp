#include <bits/stdc++.h>
using namespace std;

class C: 
public 
A, 
virtual public 
B;
{ public:
C( ):A( ),B( )
{
cout<<"c class constructor";
}
};
int main()
{

   return 0;
}