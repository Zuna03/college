#include <bits/stdc++.h>
using namespace std;

float vol_198(int r_198)
{
    return (4/3.0)*3.14*r_198*r_198*r_198;
}

float vol_198(int r_198,int h_198)
{
    return 3.14*r_198*r_198*h_198;
}

float vol_198(int l_198,int b_198,int h_198)
{
    return l_198*b_198*h_198;
}
int main()
{
    cout<<"Enter radius of sphere:-"<<endl;
    int r1_198;
    cin>>r1_198;

    cout<<"Enter radius of and height of cyclinder:-"<<endl;
    int r2_198,h1_198;
    cin>>r2_198>>h1_198;

    cout<<"Enter length,bredth and height of cuboid"<<endl;
    int l_198,b_198,h2_198;
    cin>>l_198>>b_198>>h2_198;


    cout<<"volume of sphere is :- "<<vol_198(r1_198)<<endl;
    cout<<"volume of cylinder is :- "<<vol_198(r2_198,l_198)<<endl;
    cout<<"volume of cuboid is :- "<<vol_198(l_198,b_198,h2_198)<<endl;

   return 0;
}