#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// Struct declaration.
struct Employee_198
{
    char name_198[50];
    char designation_198[50];
    char gender_198[10];
    char department_198[20];
    double salary_198;
    double gross_198;
};
// Takes input.
void getData_198(int n_198, struct Employee_198 *a_198)
{
    for (int i = 0; i < n_198; i++)
    {
        printf("Enter details of employee %d :- \n", i + 1);
        scanf("%lf", &a_198[i].salary_198);
        getchar();
        fgets(a_198[i].name_198, sizeof(a_198[i].name_198), stdin);
        fgets(a_198[i].designation_198, sizeof(a_198[i].designation_198), stdin);
        fgets(a_198[i].gender_198, sizeof(a_198[i].gender_198), stdin);
        fgets(a_198[i].department_198, sizeof(a_198[i].department_198), stdin);
        a_198[i].gross_198 = 2.0 * a_198[i].salary_198;
        
    }
}
// Gives output.
void display_198(int n_198, struct Employee_198 *a_198)
{
    for (int i = 0; i < n_198; i++)
    {
        printf("NAME : %s\n", a_198[i].name_198);
        printf("DESIGNATION : %s\n", a_198[i].designation_198);
        printf("gender : %s\n", a_198[i].gender_198);
        printf("DEPARTMENT : %s\n", a_198[i].department_198);
        printf("SALARY : %lf , GROSS SALARY : %lf\n", a_198[i].salary_198, a_198[i].gross_198);
        printf("\n");
    }
}
// Main Function.
int main()
{
    printf("Enter number of employees \n");
    int n_198;
    scanf("%d", &n_198);
    

    struct Employee_198 *a_198;
    a_198 = (struct Employee_198 *)malloc(n_198 * sizeof(struct Employee_198));

    getData_198(n_198, a_198);
   

    display_198(n_198, a_198);
    return 0;
}