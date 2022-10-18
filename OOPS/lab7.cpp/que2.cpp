#include <bits/stdc++.h>
using namespace std;

class student_198
{
protected:
    string name_198;
    int age_198;
    int roll_198;

public:
    student_198(string n, int a, int r)
    {
        name_198 = n;
        age_198 = a;
        roll_198 = r;
    }
    void display()
    {
        cout << "Name : " << name_198 << endl;
        cout << "Age  : " << age_198 << endl;
        cout << "Roll : " << roll_198 << endl;
    }
};

class test : public student_198
{
protected:
    int marks[5];

public:
    test(string n, int a, int r, int m[5]) : student_198(n, a, r)
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
    }
    void display()
    {
        student_198::display();
        cout << "Marks in 5 subjects are :\n";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class result : public test
{
    char grade;
    float percent;
    int totalMarks;

public:
    result(string n, int a, int r, int m[5]) : test(n, a, r, m)
    {
    }
    void calculate()
    {
        int total = 0;
        for (size_t i = 0; i < 5; i++)
        {
            total += marks[i];
        }
        totalMarks = total;
        percent = totalMarks / 5.0;
        if (percent >= 90 && percent <= 100)
            grade = 'A';
        else if (percent >= 80 && percent <= 90)
            grade = 'B';
        else if (percent >= 70 && percent < 60)
            grade = 'C';
        else if (percent >= 60 && percent < 50)
            grade = 'D';
        else
            grade = 'F';
    }

    void display()
    {
        test::display();
        student_198::display();
        cout << "Percent of the student is : " << percent << "%" << endl;
        cout << "Grade of the student is : " << grade << endl;
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
    result r1(n, a, r, m);
    r1.calculate();
    r1.display();

    return 0;
}