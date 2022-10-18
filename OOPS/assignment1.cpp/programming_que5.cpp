#include <bits/stdc++.h>
using namespace std;

class student_198
{
    string name;
    int roll;
    float avg;
    float avg_class_marks;

public:
    void get_data(string n, int r, float a)
    {
        name = n;
        roll = r;
        avg = a;
    }

    friend void avg_class(int n, student_198 *s);
    friend void above_avg(int n, student_198 *s);
    friend void below_avg(int n, student_198 *s);
    friend void display(int n, student_198 *s);
    friend void sorting(int n, student_198 *s);
    friend void highest_marks_student(int n, student_198 *s);
    friend void lowest_marks_student(int n, student_198 *s);
};

void display(int n, student_198 *s)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Name :- " << s[i].name << setw(10) << "Roll  :- " << s[i].roll << setw(5) << "Marks :- " << s[i].avg << "\n";
    }
}
void avg_class(int n, student_198 *s)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += s[i].avg;
    }
    s->avg_class_marks = float(total / n);
}

void above_avg(int n, student_198 *s)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].avg > s->avg_class_marks)
            count++;
    }
    cout << "The percentage of  students above average are :" << (float(float(count) / float(n)) * 100.0) << "%" << endl;
}

void below_avg(int n, student_198 *s)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].avg < s->avg_class_marks)
            count++;
    }

    cout << "The percentage of  students above average are :" << (float(float(count) / float(n)) * 100.0) << "%" << endl;
}

void sorting(int n, student_198 *s)
{
    class student_198 temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (s[j].avg > s[j + 1].avg)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void highest_marks_student(int n, student_198 *s)
{
    cout << "The student having highest marks is :-" << s[n - 1].name << endl;
}

void lowest_marks_student(int n, student_198 *s)
{
    cout << "The student having highest marks from bottom is :-" << s[0].roll << endl;
}

int main()
{
    cout << "Enter number of students :\n";
    int n;
    cin >> n;

    student_198 *s = new student_198[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of the student-" << i + 1 << "\n";
        string st;
        getchar();
        getline(cin, st);
        cout << "Enter roll number of the student-" << i + 1 << "\n";
        int r;
        cin >> r;
        cout << "Enter average marks of student-" << i + 1 << "\n";
        int a;
        cin >> a;
        s[i].get_data(st, r, a);
    }
    cout << "Before sorting :\n";
    display(n, s);
    sorting(n, s);
    cout << "After sorting :\n";
    display(n, s);
    cout << endl;
    highest_marks_student(n, s);
    lowest_marks_student(n, s);
    avg_class(n, s);
    above_avg(n, s);
    below_avg(n, s);

    return 0;
}