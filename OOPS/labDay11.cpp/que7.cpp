#include <bits/stdc++.h>
using namespace std;

class student_198
{
    string name_198;
    int roll_198;
    char gender_198;
    int marks_198[3];

public:
    void getInfo()
    {
        ofstream file_198("que7.txt");
        if (!file_198)
        {
            cout << "Error in opening source file_198..!!";
        }

        cout << "Enter name of the student : ";
        cin >> name_198;
        file_198 << "Name : " << name_198 << endl;

        cout << "Enter roll of the student : ";
        cin >> roll_198;
        file_198 << "Roll : " << roll_198 << endl;

        cout << "Enter gender of the student : ";
        cin >> gender_198;
        file_198 << "Gender : " << gender_198 << endl;

        cout << "Enter marks in three subjects : ";
        file_198 << "Marks : " << endl;
        ;
        for (int i = 0; i < 3; i++)
        {
            cin >> marks_198[i];
            file_198 << marks_198[i] << endl;
        }
    }
    void readInfo()
    {
        ifstream file_198("que7.txt");
        int sum = 0;
        float avg;
        string s;
        int x; 
        int line;
        int i = 0;
        string s1 = "Marks : ";

        while (getline(file_198, s))
        {
            if (s1.compare(s) == 0)
                line = i;
            else
            {

                if (i >= line)
                {
                    cout << s << endl;
                    x = stoi(s);
                    sum += x;
                }

                else
                    cout << s << endl;
                i++;
            }
        }
        avg = sum / 3.0;
        cout << "Average of marks is : " << avg << endl;
    }
};

int main()
{
    student_198 A;
    A.getInfo();
    cout << "Content has been copied successfully" << endl;
    A.readInfo();

    return 0;
}