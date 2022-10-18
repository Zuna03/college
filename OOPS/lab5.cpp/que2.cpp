#include <bits/stdc++.h>
using namespace std;

class time_198
{
    int hour_198;
    int min_198;

    public:
    time_198()
    {
        hour_198=0;
        min_198=0;
    }
    time_198(int h)
    {
        hour_198=h;
        min_198=0;
    }
    time_198(int h,int m)
    {
        hour_198=h;
        min_198=m;
    }
    time_198(const time_198 &t)
    {
        hour_198=t.hour_198;
        min_198=t.min_198;
    }
    void display()
    {
        cout<<hour_198<<" : "<<min_198<<endl;
    }
    ~time_198()
    {
        cout<<"Destructor is invoked\n";
    }

};
int main()
{
    time_198 t1,t2(1),t3(2,20);
    time_198 t4(t2);
    t1.display();
    t2.display();
    t3.display();
    t4.display();

   return 0;
}