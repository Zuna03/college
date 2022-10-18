#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure Formed.
struct employee_195
{
    int id_195, age_195;
    char name_195[100];
    float salary_195; 
};
// Function To find average Salary.
float avgSalary_195(struct employee_195 *a_195, int n_195)
{
    float avgSalary_195 = 0;
    for (int i = 0; i < n_195; i++)
        avgSalary_195 += a_195[i].salary_195;

    avgSalary_195 /= (float)n_195;
    return avgSalary_195;
}
// Function to find Highest Salary.
float highSalary_195(struct employee_195 *a_195, int n_195)
{
    float high_195 = -2147453645;
    for (int i = 0; i < n_195; i++)
    {
    if (high_195 < a_195[i].salary_195)
            high_195 = a_195[i].salary_195;
    }

    return high_195;
}
// Main Function.
int main()
{
    printf("Enter number of employees \n");
    int n_195;
    scanf("%d", &n_195);
    struct employee_195 *a_195;
    a_195 = (struct employee_195 *)malloc(n_195 * sizeof(struct employee_195));
    // Input.
    printf("Enter id,name,age,salary of employees \n");
    for (int i = 0; i < n_195; i++)
    {
        scanf("%d", &a_195[i].id_195);
        getchar();
        fgets(a_195[i].name_195, 100, stdin);
        scanf(" %d", &a_195[i].age_195);
        scanf("%f", &a_195[i].salary_195);
    }
    // Output.
    printf("\n");
    printf("Average salary is :- %f\n", avgSalary_195(a_195, n_195));   // Function called inside printf function.
    printf("Highest salary is :-  %f\n", highSalary_195(a_195, n_195)); // Function called inside printf function.
    return 0;
}