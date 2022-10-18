#include <bits/stdc++.h>
using namespace std;

// define a class to store student data
class student_198
{
    int add_198;
    char name_198[90];
    float totalMarks_198;

public:
    student_198() {}
    void getData_198(); // get student data from user
    void display_198(); // display data
    float retTotalMarks_198() { return totalMarks_198; }
};

void student_198 ::getData_198()
{
    cout << "\nEnter Roll No. :: ";
    cin >> add_198;
    cin.ignore(); // ignore the newline char inserted when you press enter
    cout << "\nEnter Name :: ";
    cin.getline(name_198, 90);
    cout << "\nEnter totalMarks_198 :: ";
    cin >> totalMarks_198;
}

void student_198 ::display_198()
{
    cout << "\nRoll No. :: " << add_198 << endl;
    cout << "\nName :: " << name_198 << endl;
    cout << "\ntotalMarks_198 :: " << totalMarks_198 << endl;
}

int main()
{
    int n{0};
    cout << "ENTER THE TOTAL NUMBER OF STUDENTS: ";
    cin >> n;
    student_198 s[n]; // array of 3 student objects
    fstream file;
    int i;

    file.open("file.txt", ios ::out); // open file for writing
    cout << "\nWriting Student information to the file :- " << endl;
    cout << "\nEnter N students Details to the File :- " << endl;

    for (i = 0; i < n; i++)
    {
        s[i].getData_198();
        // write the object to a file
        file.write((char *)&s[i], sizeof(s[i]));
    }

    file.close(); // close the file

    file.open("file.txt", ios ::in); // open file for reading
    cout << "\nReading Student information to the file :- " << endl;

    for (i = 0; i < n; i++)
    {
        // read an object from a file
        file.read((char *)&s[i], sizeof(s[i]));
        if (s[i].retTotalMarks_198() <= 498 && s[i].retTotalMarks_198() >= 456)
            s[i].display_198();
    }

    file.close(); // close the file

    return 0;
}