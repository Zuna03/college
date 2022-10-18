#include <bits/stdc++.h>
using namespace std;

class employee_198
{
    int emp_id_198;
    char name_198[20];
    int age_198;
    float salary_198;
    float gross_198;

public:
    void getData_198(int id_198, char *s_198, int a_198, float sal_198)
    {
        emp_id_198 = id_198;
        strcpy(name_198, s_198);
        age_198 = a_198;
        salary_198 = sal_198;
        gross_198 = 1.9 * salary_198;
    }

    void display_198()
    {
        cout << "ID: " << emp_id_198 << "  ";
        cout << "Name: " << name_198 << "  ";
        cout << "Age: " << age_198 << "  ";
        cout << "Basic Salary: " << salary_198 << "  ";
        cout << "Gross Salary: " << gross_198 << "  ";
    }
};
int main()
{
    cout << "Enter number of employees" << endl;
    int n_198;
    cin >> n_198;

    employee_198 c_198[n_198];

    for (int j_198 = 0; j_198 < n_198; j_198++)
    {
        cout << "Enter details of employee-" << j_198 + 1 << endl;
        int id_198;
        char s_198[20];
        int a_198;
        float sal_198;

        cin >> id_198 >> s_198 >> a_198 >> sal_198;

        c_198[j_198].getData_198(id_198, s_198, a_198, sal_198);
    }

    for (int i_198 = 0; i_198 < n_198; i_198++)
    {
        c_198[i_198].display_198();
        cout << endl;
    }

    return 0;
}