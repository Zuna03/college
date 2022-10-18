#include <bits/stdc++.h>
using namespace std;

class student_198
{

    char name_198[10];
    int roll_198;
    float marks_198[5];
    float total_198;

public:
    void getData_198(char s_198[10], int rollnum_198, float totAlmarks_198)
    {

        //assigning values

        strcpy(name_198, s_198);
        roll_198 = rollnum_198;
        total_198 = totAlmarks_198;
    }

    void displayData()
    {

        //displaying the input

        cout << "Name of the student is :- " << name_198 << endl;

        cout << "Roll number of the student is :- " << roll_198 << endl;

        cout << "Total marks in 5 subjects are :- " << total_198;
    }
};

int main()
{
    char s_198[10];
    int rollnum_198;
    float mArks_198[5];

    //taking input

    cout << "Enter name of student : " << endl;
    cin >> s_198;

    cout << "Enter roll number of the student :-" << endl;
    cin >> rollnum_198;

    cout << "Enter marks in 5 subjects :-";
    for (int i_198 = 0; i_198 < 5; i_198++)
    {
        cin >> mArks_198[i_198];
    }

    float totAlmarks_198 = 0;

    for (int i_198 = 0; i_198 < 5; i_198++)
    {
        totAlmarks_198 += mArks_198[i_198];
    }
    student_198 st_198;
    st_198.getData_198(s_198, rollnum_198, totAlmarks_198);
    st_198.displayData();

    return 0;
}