#include <bits/stdc++.h>
using namespace std;

class student_198
{
protected:
    string name_198;
    int age_198;
    int roll_198;

    student_198(string n, int a, int r)
    {
        name_198 = n;
        age_198 = a;
        roll_198 = r;
    }

public:
    void display_198()
    {
        cout << "Name : " << name_198 << endl;
        cout << "Age  : " << age_198 << endl;
        cout << "Roll : " << roll_198 << endl;
    }
};

class test_198 : public student_198
{
protected:
    int marks[5];

public:
    test_198(string n, int a, int r, int m[5]) : student_198(n, a, r)
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
    }
    void display_198()
    {
        student_198::display_198();
        cout << "Marks in 5 subjects are :\n";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
    }
};
int main()
{
    cout << "Enter name ,age , roll numbers of student :\n";
    string n;
    int a, r;
    getline(cin, n);
    cin >> a >> r;
    cout << "Enter marks in 5 diffrent subjects :\n";
    int m[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> m[i];
    }
    test_198 t(n, a, r, m);
    t.display_198();

    return 0;
}