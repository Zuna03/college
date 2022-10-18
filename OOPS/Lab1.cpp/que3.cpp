#include <bits/stdc++.h>

using namespace std;

struct employee_198
{
    int id_198;
    string name_198;
    int age_198;
    float salary_198;
    float gross_198;
};

int main()
{
    cout << "Enter num of employees :- " << endl;
    int n_198;
    cin >> n_198;

    employee_198 e_198[n_198];

    cout << "Enter id,name,age,salary of " << n_198 << " employees" << endl;

    for (int i = 0; i < n_198; i++)
    {
        cout << "Enter details of employee " << i + 1 << endl;
        cin >> e_198[i].id_198 >> e_198[i].name_198 >> e_198[i].age_198 >> e_198[i].salary_198;
        e_198[i].gross_198 = e_198[i].salary_198 * (1.9);
    }

    cout << "\n";

    for (int i = 0; i < n_198; i++)
    {
        cout << "Employee's id is :- " << e_198[i].id_198 << " " << endl;
        cout << "Employee's name is :- " << e_198[i].name_198 << endl;
        cout << "Employee's age is :- " << e_198[i].age_198 << endl;
        cout << "Employee's salary is :- " << e_198[i].salary_198 << endl;
        cout << "Employee's gross salary is :-" << e_198[i].gross_198 << endl;
        cout << "\n";
    }

    return 0;
}