#include<stdio.h>
struct student_198
{
    char name_198[50];
    int roll_198;
    float marks_198[5];
    float total_198;
    float perc_198;
};
void totalPerc(struct student_198 s[],int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<=4;j++)
        {
            sum+= s[i].marks_198[j];
        }
        s[i].total_198=sum;
        s[i].perc_198=sum/5.0;
    }
}
void display(struct student_198 s[], int n,int i)
{
    printf("student details: \n");
        printf("NAME:%s \n",s[i].name_198);
        printf("ROLL NO.:%d \n",s[i].roll_198);
        printf("marks in 5 subs: \n");
        for(int j=0;j<=4;j++)
        {
            printf("%f \n",s[i].marks_198[j]);
        }
        printf("TOTAL: %f \n",s[i].total_198);
        printf("PERCENTAGE: %f \n",s[i].perc_198);
}
void search(struct student_198 s[], int n,int r)
{
    int i;
    for(i=0;i<n;i++)
    { 
        if(s[i].roll_198==r)
        break;
    }
    if(i==n)
    printf("student not found");
    else
    {
        display(s,n,i);
    }
}

void range(struct student_198 s[], int n, int ur, int lr)
{
    int i;
    for( i=0;i<n;i++)
    {
        if(s[i].perc_198>=lr&&s[i].perc_198<=ur)
        display(s,n,i);
    }
}
void arrange(struct student_198 s[],int n)
{
    struct student_198 t1;
    int t;
    for(int j=0;j<n-1;j++)
    {
        t=0;
        for(int k=j+1;k<n;k++)
        {
            if(s[k].total_198<s[j].total_198)
            t=k;
        }
     if(t!=0)
     {   
    t1=s[j];
    s[j]=s[t];
    s[t]=t1;
    }
    }
     printf("in ascending order of marks \n");
     for(int a=0;a<n;a++)
     display(s,n,a);
}
int main()
{
    struct student_198 s[20];
    int n;
    printf("enter the no of students \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter name,roll no and marks in 5 subs \n");
        scanf("%s",s[i].name_198);
        scanf("%d",&s[i].roll_198);
        for(int j=0;j<=4;j++)
        {
            scanf("%f",&s[i].marks_198[j]);
        }
    }
    totalPerc(s,n);
    int r,lr,ur;
    printf("enter a roll no for search %d \n");
    scanf("%d",&r);
    search(s,n,r);
    printf("enter a range \n");
    scanf("%d%d",&lr,&ur);
    range(s,n,ur,lr);
    printf("all arranged markswise \n");
    arrange(s,n);
}