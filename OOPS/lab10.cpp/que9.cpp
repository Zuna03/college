#include <iostream>
#define MAX 50
#include <string>
using namespace std;
template <class type, class type1, class type2>
class Stack
{
    int top_198;
    type name_198[MAX];
    type1 roll_198[MAX];
    type2 cgpa_198[MAX];

public:
    Stack()
    {
        top_198 = -1;
    }
    void push(type n, type1 r, type2 c)
    {
        if (top_198 == MAX - 1)
        {
            cout << "overflow" << endl;
        }
        top_198++;
        name_198[top_198] = n;
        roll_198[top_198] = r;
        cgpa_198[top_198] = c;
    }
    void pop_student()
    {
        type n;
        type1 r;
        type2 c;
        n = name_198[top_198];
        r = roll_198[top_198];
        c = cgpa_198[top_198];
        top_198--;
        cout << "info deleted:" << endl;
        cout << "name: " << n << endl;
        cout << "roll: " << r << endl;
        cout << "cgpa: " << c << endl;
    }
    void pop_employee()
    {
        type n;
        type1 r;
        type2 c;
        n = name_198[top_198];
        r = roll_198[top_198];
        c = cgpa_198[top_198];
        top_198--;
        cout << "info deleted:" << endl;
        cout << "name: " << n << endl;
        cout << "employee id: " << r << endl;
        cout << "salary: " << c << endl;
    }
    void display_student()
    {
        cout << endl;
        for (int i = top_198; i >= 0; i--)
        {
            cout << "***" << endl;
            cout << "Name :" << name_198[i] << endl;
            cout << "Roll number:" << roll_198[i] << endl;
            cout << "CGPA:" << cgpa_198[i] << endl;
            cout << "***" << endl;
            cout << endl;
        }
        cout << endl;
    }
    void display_employee()
    {
        cout << endl;
        for (int i = top_198; i >= 0; i--)
        {
            cout << "***" << endl;
            cout << "Name :" << name_198[i] << endl;
            cout << "employee id:" << roll_198[i] << endl;
            cout << "salary:" << cgpa_198[i] << endl;
            cout << "***" << endl;
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    cout << "\nSTUDENT RECORD\n"
         << endl;
    Stack<string, int, float> s;
    int ch_198 = 1;
    while (ch_198 == 1)
    {
        string name_198;
        int roll_198;
        float cgpa_198;
        cout << "enter the name of student:" << endl;
        cin >> name_198;
        cout << "enter the roll number:" << endl;
        cin >> roll_198;
        cout << "enter the cgpa:" << endl;
        cin >> cgpa_198;
        s.push(name_198, roll_198, cgpa_198);
        cout << "enter 1 if wanna add more values" << endl;
        cin >> ch_198;
    }

    cout << "\nstudent details:" << endl;
    s.display_student();
    int ch1_198 = 1;
    while (ch1_198 == 1)
    {
        cout << "enter 1 if wanna pop a value" << endl;
        cin >> ch1_198;
        if (ch1_198 == 1)
        {
            s.pop_student();
        }
        else
            break;
    }
    cout << "\nstudent details:" << endl;
    s.display_student();

    cout << "\nEMPLOYEE RECORD\n"
         << endl;
    Stack<string, int, float> e;
    ch_198 = 1;
    while (ch_198 == 1)
    {
        string name_198;
        int empid_198;
        float salary_198;
        cout << "enter the name of employee:" << endl;
        cin >> name_198;
        cout << "enter the employee id:" << endl;
        cin >> empid_198;
        cout << "enter the salary:" << endl;
        cin >> salary_198;
        e.push(name_198, empid_198, salary_198);
        cout << "enter 1 if wanna add more values" << endl;
        cin >> ch_198;
    }

    cout << "\nemployee details:" << endl;
    e.display_employee();
    ch1_198 = 1;
    while (ch1_198 == 1)
    {
        cout << "enter 1 if wanna pop a value" << endl;
        cin >> ch1_198;
        if (ch1_198 == 1)
        {
            e.pop_employee();
        }
        else
            break;
    }
    cout << "\nemployee details:" << endl;
    e.display_employee();
}