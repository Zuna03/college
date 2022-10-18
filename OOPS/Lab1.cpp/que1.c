#include <stdio.h>

struct student_198
{
    char name_198[50];
    int roll_198;
    float marks_198[5];
};

int main()
{
    struct student_198 s_198;

    //taking input

    printf("Enter informations of student:\n\n");

    printf("Enter name of the student : \n");
    scanf("%s", s_198.name_198);

    printf("Enter roll number of the student : \n");
    scanf("%d", &s_198.roll_198);

    printf("Enter marks of the student in 5 subjects : \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Marks in subject-%d \n", i + 1);
        scanf("%f", &s_198.marks_198[i]);
    }
    printf("\n");
    
    // displaying

    printf("The name of the student is %s \n", s_198.name_198);

    printf("The roll number of the student is %d \n", s_198.roll_198);

    for (int i = 0; i < 5; i++)
    {
        printf("Marks in subject-%d is %.2f \n", i + 1, s_198.marks_198[i]);
    }

    return 0;
}