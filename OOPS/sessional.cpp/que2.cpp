#include <bits/stdc++.h>
using namespace std;

class person
{
public:
    string name;
    string address;
    int phone_num;
    float salary;

    person(string n, string a, int p, float s)
    {
        name = n;
        address = a;
        phone_num = p;
        salary = s;
    }
    void display()
    {
        cout << "Name of the person : " << name << endl;
        cout << "address of the person : " << address << endl;
        cout << "phone num of the person : " << phone_num << endl;
        cout << "salary of the person : " << salary << endl;
    }
};

class household_expenditure : virtual public person
{
public:
    float elec_bill;
    int num_of_lit;
    float rate_lit;
    float household_sal;
    float milk_cost;

    household_expenditure(string n, string a, int p, float s, float e, int nu, float r, float h) : person(n, a, p, s)
    {
        elec_bill = e;
        num_of_lit = nu;
        rate_lit = r;
        household_sal = h;
        milk_cost = num_of_lit * rate_lit;
    }
    void display()
    {
        cout << "Electricity bill : " << elec_bill<<endl;
        cout << "Milk bill : " << milk_cost<<endl;
        cout << "Household bill : " << household_sal<<endl;
    }
};

class extra_expenditure : virtual public person
{
public:
    float loan;
    float travelling;
    float another;

    extra_expenditure(string n, string a, int p, float s, float l, float t, float an) : person(n, a, p, s)
    {
        loan = l;
        travelling = t;
        another = an;
    }

public:
    void display()
    {
        cout << "Loan : " << loan << endl;
        cout << "Travelling cost : " << travelling << endl;
        cout << "other  : " << another << endl;
    }
};

class total_exp : public household_expenditure, public extra_expenditure
{
    float total;

public:
    total_exp(string n, string a, int p, float s, float l, float t, float an, float e, int nu, float r, float h) : person(n, a, p, s), household_expenditure(n, a, p, s, e, nu, r, h), extra_expenditure(n, a, p, s, l, t, an)
    {
        total = loan + travelling + another + household_sal + elec_bill + (rate_lit * num_of_lit);
    }
    void display()
    {
        if (total > (0.5) * salary)
        {
            throw 1;
        }
        else
        {
            person::display();
            household_expenditure::display();
            extra_expenditure::display();
            cout << "Total expenditure: " << total << endl;
        }
    }
};
int main()
{
    string name;
    string address;
    int phone_num;
    float salary;
    float elec_bill;
    int num_of_lit;
    float rate_lit;
    float household_sal;
    float loan;
    float travelling;
    float another;

    cout << "Enter name , address,phone num and salary of person\n";
    cin >> name >> address >> phone_num >> salary;
    cout << "Enter elec bill,num of liters of milk,cost per litre and household salary\n";
    cin >> elec_bill >> num_of_lit >> rate_lit >> household_sal;

    cout << "Enter loan,travelling cost and other cost\n";
    cin >> loan >> travelling >> another;

    try
    {
        total_exp t(name, address, phone_num, salary, loan, travelling, another, elec_bill, num_of_lit, rate_lit, household_sal);
        t.display();
    }
    catch (int x)
    {
        cout << "You need to reduce your expnditure its too high!! exception thrown with " << x;
    }
    return 0;
}