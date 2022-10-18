#include <bits/stdc++.h>
using namespace std;

class person
{
    string name_198;
    int age_198;

public:
    person()
    {
        name_198 = "noname_198";
        age_198 = 0;
    }
    person(string s, int a)
    {
        name_198 = s;
        age_198 = a;
    }

    void display()
    {
        cout << "Hi I am " << name_198 << " and my age is " << age_198 << endl;
    }
};

int main()
{
    fstream file_198("que8.bin", ios::binary | ios::in | ios::out | ios::trunc);
    if (!file_198)
    {
        cout << "Error in opening source file_198..!!";
    }

    person p("Xyz", 20);

    file_198.write((char *)&p, sizeof(p));

    file_198.seekg(0);

    person p1;
    file_198.read((char *)&p1, sizeof(p));

    p.display();
    p1.display();

    file_198.close();

    return 0;
}