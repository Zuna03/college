//SHIVANGI SHRIVASTAVA 2005198

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class student_198
{

    char name_198[10];
    int age_198;
    int roll_198;
    float average_198;
    

public:
    friend void compare(student_198 s1,student_198 s2);

    student_198()
    {
        strcpy(name_198,"xyz");
        age_198=10;
        roll_198=100;
        average_198=20;
    }

    student_198(const student_198 &s1)
    {
        strcpy(name_198,s1.name_198);
        age_198=s1.age_198;
        roll_198=s1.roll_198;
        average_198=s1.average_198;
    }

    void getDetails(void)
    {
    cout << "Enter name: \n" ;
    cin >> name_198;
    cout<<"Enter age :\n";
    cin>>age_198;
    cout << "Enter roll number:\n ";
    cin >> roll_198;
    cout<<"Enter marks in 5 subjects :\n";
    int marks_198[5];
    int total=0;
    for (int i = 0; i < 5; i++)
    {
        cin>>marks_198[i];
        total+=marks_198[i];
    }
    average_198=total/5;    
}

    void put_data_198(char s_198[10], int a_198,int rollnum_198, float totAlmarks_198)
    {
        //assigning values
        strcpy(name_198, s_198);
        age_198=a_198;
        roll_198 = rollnum_198;
        average_198 = totAlmarks_198;
    }

    void displayData()
    {
        //displaying the input

        cout << "Name of the student is :- " << name_198 << endl;
        
        cout << "Age of the student is :- " << age_198 << endl;

        cout << "Roll number of the student is :- " << roll_198 << endl;

        cout << "Average marks in 5 subjects are :- " << average_198;
    }

    
};

void compare(student_198 s1,student_198 s2)
{
    if(s1.average_198>s2.average_198)
    {
        cout<<"highest scorer is "<<s1.name_198;
    }
    else
    {
        cout<<"highest scorer is "<<s2.name_198;
    }
}

int main()
{
    student_198 s1;
    s1.getDetails();
    s1.displayData();
    cout<<endl;

    student_198 s2;
    s2.getDetails();
    s2.displayData();
    cout<<endl;
    
    student_198 s3(s2);
    compare(s1,s3);

   return 0;
}