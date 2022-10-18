#include <bits/stdc++.h>
using namespace std;

class comPlex{
    int real;
    int imag;

public:
    void getData(int r,int i)
    {
        real=r;
        imag=i;
    }

    comPlex add(comPlex s2,comPlex s1)
    {
        comPlex temp;
        temp.real=s1.real+s2.real;
        temp.imag=s1.imag+s2.imag;

        return temp;
    }

    void display()
    {
        cout<<real<<"+"<<imag<<"i";
    }
};

int main()
{
    comPlex s1;
    comPlex s2;
    comPlex s3;
    s1.getData(2,3);
    s2.getData(5,1);
    s3=s3.add(s1,s2);

    s3.display();




   return 0;
}