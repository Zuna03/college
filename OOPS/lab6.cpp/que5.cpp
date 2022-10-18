#include <bits/stdc++.h>
using namespace std;

class employee_198
{
protected:
    string name_198;
    int id;
    float salary_198;

public:
    void getInfo_198(string n, int i, float s)
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
    void calculate_198()
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
    int hour_198;
    float pph_198;

public:
    part_time_198(string n, int i, int h, float p)
    {
        name_198 = n;
        id = i;
        hour_198 = h;
        salary_198 = h * p;
    }
    void display_198()
    {
        employee_198::display_198();
    }
};
int main()
{
    cout << "Enter name_198,id of employee_198,salary_198 \n";
    string n1;
    int i1;
    float s1;
    cin >> n1 >> i1 >> s1;

    regular_198 r;
    r.getInfo_198(n1, i1, s1);
    r.calculate_198();
    r.display_198();

    cout << "Enter name_198,id of employee_198 \n";
    string n2;
    int i2;
    cin >> n2 >> i2;
    cout << "Enter hour_198s of working and pay per hour_198 of employee_198 \n";
    int h;
    float p;
    cin >> h >> p;

    part_time_198 pt(n2, i2, h, p);
    pt.display_198();

    return 0;
}