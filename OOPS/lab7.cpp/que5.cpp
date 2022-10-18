#include <bits/stdc++.h>
using namespace std;

class employee_198
{
protected:
    string name_198;
    int id;
    float salary_198;

public:
    employee_198(string n, int i, float s)
    {
        name_198 = n;
        id = i;
        salary_198 = s;
    }
    void display_198()
    {
        cout << "Name   :" << name_198 << endl;
        cout << "Id     :" << id << endl;
        cout << "Salary :" << salary_198 << endl;
    }
};

class regular_198 : public employee_198
{
    float da;
    float hra;

public:
    regular_198(string n, int i, float s) : employee_198(n, i, s)
    {
        da = 1.7 * salary_198;
        hra = 0.8 * salary_198;
    }
    void display_198()
    {
        employee_198::display_198();
        cout << "DA    :" << da << endl;
        cout << "HRA   :" << hra << endl;
    }
};

class part_time_198 : public employee_198
{
    int hour;
    float pph;

public:
    part_time_198(string n, int i, float s, int h, float p) : employee_198(n, i, s)
    {
        hour = h;
        salary_198 = h * p;
    }
    void display_198()
    {
        employee_198::display_198();
    }
};
int main()
{
    cout << "Enter name,id of employee,salary \n";
    string n1;
    int i1;
    float s1;
    cin >> n1 >> i1 >> s1;

    regular_198 r(n1, i1, s1);
    r.display_198();

    cout << "Enter name,id of employee \n";
    string n2;
    int i2;
    cin >> n2 >> i2;
    cout << "Enter hours of working and pay per hour of employee\n";
    int h;
    float p;
    cin >> h >> p;

    part_time_198 pt(n2, i2, h * p, h, p);
    pt.display_198();

    return 0;
}