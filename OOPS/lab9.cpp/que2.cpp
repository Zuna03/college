#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class employee_198
{
   string name_198;
   int id_198;

protected:
   int salary_198;

public:
   employee_198(string n, int i)
   {
      name_198 = n;
      id_198 = i;
   }

   void display_198()
   {
      cout << "Name : " << name_198 << endl;
      cout << "Employee Id : " << id_198 << endl;
   }

   virtual void calcSalary_198() = 0;
};

class regular_198 : public employee_198
{
   float basic_198;
   float DA_198;
   float HRA_198;

public:
   regular_198(float b_198, string n, int i) : employee_198(n, i)
   {
      basic_198 = b_198;
      DA_198 = 0.8 * basic_198;
      HRA_198 = 0.1 * basic_198;
      salary_198 = basic_198 + DA_198 + HRA_198;
   }

   void calcSalary_198()
   {
      cout << "The salary of regular employee is : " << salary_198 << endl;
   }
};

class part_time_198 : public employee_198
{
   int hours_198;
   float pay_per_hour_198;

public:
   part_time_198(int h_198, float p_198, string n, int i) : employee_198(n, i)
   {
      hours_198 = h_198;
      pay_per_hour_198 = p_198;
      salary_198 = hours_198 * pay_per_hour_198;
   }
   void calcSalary_198()
   {
      cout << "The salary of part-time employee is : " << hours_198 * pay_per_hour_198 << endl;
   }
};

int main()
{
   cout << "Enter name , id and basic salary of employee " << endl;
   string name1_198;
   int id1_198;
   float salary1_198;
   cin >> name1_198;
   cin >> id1_198;
   cin >> salary1_198;

   regular_198 r_198(salary1_198, name1_198, id1_198);
   employee_198 *ptr = &r_198;
   ptr->display_198();
   ptr->calcSalary_198();

   cout << "Enter name , id ,number of hours and pay per hour of employee " << endl;
   string name2_198;
   int id2_198;
   int h_198;
   float salary2_198;
   cin >> name2_198 >> id2_198 >> h_198 >> salary2_198;

   part_time_198 p_198(h_198, salary2_198, name2_198, id2_198);
   ptr = &p_198;
   ptr->display_198();
   ptr->calcSalary_198();

   return 0;
}