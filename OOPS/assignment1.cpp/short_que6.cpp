#include <bits/stdc++.h>
using namespace std;

class person
{
    int age;

public:
    person(float a)
    {
        age = int(a);
    }
    person max_age( person p2)
    {
        return (age > p2.age) ? age : p2.age;
    }
    void display()
    {
        cout<<"Max of two ages is : "<<age;
    }
};

int main()
{
    person p1(12);
    person p2(13);
    person p3=p1.max_age(p2);
    p3.display();

    return 0;
}