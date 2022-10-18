#include <bits/stdc++.h>
using namespace std;

class student_198
{
protected:
    string name_198;
    int age_198;
    int roll_198;

public:
    void getInfo_198(string n, int a, int r)
    {
        name_198 = n;
        age_198 = a;
        roll_198 = r;
    }
    void display_198()
    {
        cout << "Name : " << name_198 << endl;
        cout << "Age  : " << age_198 << endl;
        cout << "Roll : " << roll_198 << endl;
    }
};

class test_198 : virtual public student_198
{
protected:
    int marks[3];

public:
    void getMarks_198(int m[3])
    {
        for (int i = 0; i < 3; i++)
        {
            marks[i] = m[i];
        }
    }
    void display_198()
    {
        student_198::display_198();
        cout << "Marks in 3 subjects are :\n";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class activity_198 : virtual public student_198
{
protected:
    int act[2];

public:
    void getAct_198(int a[2])
    {
        for (int i = 0; i < 2; i++)
        {
            act[i] = a[i];
        }
    }
    void display_198()
    {
        cout << "Marks in activities are :\n";
        for (int i = 0; i < 2; i++)
        {
            cout << act[i] << " ";
        }
        cout << endl;
    }
};

class result_198 : public test_198, public activity_198
{
    char grade;
    float percent;
    float totalMarks;

public:
    void calculate_198()
    {
        int total = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i < 2)
                total += marks[i] + act[i];
            else
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

    void display_198()
    {
        test_198::display_198();
        activity_198::display_198();
        cout << "Percent of the student_198 is : " << percent << "%" << endl;
        cout << "Grade of the student_198 is : " << grade << endl;
    }
};

int main()
{

    cout << "Enter name ,age , roll numbers of student :\n";
    string n;
    int a, r;
    getline(cin, n);
    cin >> a >> r;
    cout << "Enter marks in 3 diffrent subjects :\n";
    int m[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> m[i];
    }
    cout << "Enter marks in 2 activities :\n";
    int ac[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> ac[i];
    }
    result_198 r1;
    r1.getInfo_198(n, a, r);
    r1.getMarks_198(m);
    r1.getAct_198(ac);
    r1.calculate_198();
    r1.display_198();

    return 0;
}