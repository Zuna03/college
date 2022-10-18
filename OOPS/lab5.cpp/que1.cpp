#include <bits/stdc++.h>
using namespace std;

class complex_198
{
    int real_198;
    int imag_198;

    public:
    complex_198()
    {
        real_198=0;
        imag_198=0;
    }
    complex_198(int r,int i)
    {
        real_198=r;
        imag_198=i;

    }
    complex_198(const complex_198 &c)
    {
        real_198=c.real_198;
        imag_198=c.imag_198;
    }
    void display()
    {
       cout<<real_198<<" + "<<imag_198<<"i"<<endl;
    }
    ~complex_198()
    {
        cout<<"Destructor is invoked\n";
    }

};
int main()
{
    complex_198 c1,c2(4,5);
    complex_198 c3(c2);
    c1.display();
    c2.display();
    c3.display();


   return 0;
}