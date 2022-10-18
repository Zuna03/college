#include <bits/stdc++.h>
using namespace std;

class my_date
{
public:
    int years1;
    int month1;
    int days1;

    my_date()
    {
        years1 = 0;
        month1 = 0;
        days1 = 0;
    }

    my_date(int y, int m, int d)
    {
        years1 = y;
        month1 = m;
        days1 = d;
    }
    struct daTe
    {
        int years2;
        int month2;
        int days2;
        void create(int y, int m, int d)
        {
            years2 = y;
            month2 = m;
            days2 = d;
        }
    };
    void gap(struct daTe s1, class my_date s2)
    {
        if (s1.days2 >= s2.days1)
            days1 = s1.days2 - s2.days1;
        else
        {
            s1.days2 += 30;
            s1.month2 -= 1;
            days1 = s1.days2 - s2.days1;
        }

        if (s1.month2 >= s2.month1)
            month1 = s1.month2 - s2.month1;
        else
        {
            s1.month2 += 12;
            s1.years2 -= 1;
            month1 = s1.month2 - s2.month1;
        }

        years1 = s1.years2 - s2.years1;
    }
    void display()
    {
        cout << "I am currently " << years1 << " years ," << month1 << " months and " << days1 << " days old."
             << "\n";
    }
};

int main()
{
    int y1, m1, d1;
    cout << "Enter your birth year,month and date :\n";
    cin >> y1 >> m1 >> d1;
    class my_date s1(y1, m1, d1);

    class my_date ::daTe s2;
    int y2, m2, d2;
    cout << "Enter any year,month and date :\n";
    cin >> y2 >> m2 >> d2;
    s2.create(y2, m2, d2);

    class my_date s3;
    s3.gap(s2, s1);
    s3.display();

    return 0;
}