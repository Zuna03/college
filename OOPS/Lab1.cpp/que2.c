#include <stdio.h>

struct student_198
{

    char name_198[50];
    int roll_198;
    float marks_198[5];
    float total_198;
    float percent_198;
};

// Calculating percentage and sum of marks of each student

void percentageANdTotalMarks_198(struct student_198 s_198[],int num_198)
{
    float sum_198=0;
    for (int i = 0; i < num_198; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum_198+=s_198[i].marks_198[j];
        }

        s_198[i].total_198=sum_198;
        s_198[i].percent_198=sum_198/5;
        
    }   
}

void findStudent(struct student_198 s_198[],int num_198,int givenRoll_198)
{
    int  i = 0;
    for (  i = 0; i < num_198 ; i++)
    {
        if(s_198[i].roll_198 == givenRoll_198)
        {
            break;
        }
        if(i == num_198)
        {
            printf("Student not found\n");
        }
        else
        {
            display_198(s_198,num_198);
        }
    }    
}
void givenRange(struct student_198 s_198[],int num_198,int lowerRange_198,int upperRange_198 )
{
    int i=0;
    for (  i = 0; i < num_198 ; i++)
    {
        if(s_198[i].percent_198 >= lowerRange_198 && s_198[i].percent_198 <= upperRange_198)
        {
           display_198(s_198,num_198);
        }
    } 
}

// displaying

void display_198(struct student_198 s_198[],int num_198)
{
    for (int i = 0; i < num_198; i++)
    {
        printf("The name of the student%d is %s : \n", i + 1, s_198[i].name_198);
        printf("The roll number of the student%d is %d: \n", i + 1, s_198[i].roll_198);
        for (int j = 0; j < 5; j++)
        {
            printf("Marks of student%d in subject-%d is %.2f \n", i + 1, j + 1, s_198[i].marks_198[j]);
        }
        printf("Total marks of student%d is %.2f \n", i + 1, s_198[i].total_198);
        printf("Total percentage of student%d is %.2f \n", i + 1, s_198[i].percent_198);
        printf("\n\n");
    }
}


int main()
{
    
    printf("Enter number of students :\n");
    int num_198;
    scanf("%d", &num_198);
    struct student_198 s_198[num_198];
    

    //taking input

    printf("Enter informations of student:\n\n");

    for (int i = 0; i < num_198; i++)
    {
        printf("Enter name of the student%d : \n", i + 1);
        scanf("%s", s_198[i].name_198);

        printf("Enter roll number of the student%d : \n", i + 1);
        scanf("%d", &s_198[i].roll_198);

        printf("Enter marks of the student%d : \n", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("Marks of student%d in subject-%d \n", i + 1, j + 1);
            scanf("%f", &s_198[i].marks_198[j]);
        }
        printf("\n\n");
    }
    
    percentageANdTotalMarks_198(s_198,num_198);
    display_198(s_198,num_198);
    
    int givenRoll_198;
    scanf("%d",&givenRoll_198);

    int lowerRange_198,upperRange_198;
    scanf("%d,%d",lowerRange_198,upperRange_198);


    

    return 0;
}