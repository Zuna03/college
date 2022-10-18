#include <bits/stdc++.h>
using namespace std;

class stud_198
{
    int roll_198;
    char name_198[10];
    float marks_198;
    static float avg_198;

public:
    void getData(int r_198, char c_198[10], float m_198)
    {
        roll_198 = r_198;
        strcpy(name_198, c_198);
        marks_198 = m_198;
    }
    
    friend void calc_198(stud_198 *s_198, int n);
};

float stud_198::avg_198 = 0;
void calc_198(stud_198 *s_198, int n_198)
{
    float sum_198 = 0;
    for (int i_198 = 0; i_198 < n_198; i_198++)
    {
        sum_198 += s_198[i_198].marks_198;
    }
    stud_198::avg_198 = sum_198 / n_198;
    cout << "The average marks stored by the class is :- " << stud_198::avg_198 << endl;
}

int main()
{
    cout << "Enter number of students :-" << endl;
    int n_198;
    cin >> n_198;

    stud_198 a_198[n_198];

    for (int i_198 = 0; i_198 < n_198; i_198++)
    {
        cout << "Enter roll number,name,marks in Oops of student " << i_198 + 1 << endl;
        int roll_198;
        char name_198[10];
        float marks_198;
        cin >> roll_198 >> name_198 >> marks_198;
        a_198[i_198].getData(roll_198, name_198, marks_198);
    }

    calc_198(a_198, n_198);

    return 0;
}