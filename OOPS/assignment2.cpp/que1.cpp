#include <bits/stdc++.h>
using namespace std;

class drinks
{
public:
    int dcode;
    string dname;
    int dsize;
    int dprice;

    void getInfo()
    {
        int dc, ds, dp;
        string dn;
        cout << "Enter code,name,size,price of the drink : ";
        cin >> dc >> dn >> ds >> dp;
        dcode = dc;
        dname = dn;
        dsize = ds;
        dprice = dp;
    }

    void display()
    {
        cout << "Drink's code : " << dcode << endl;
        cout << "Drink's name : " << dname << endl;
        cout << "Drink's size : " << dsize << endl;
        cout << "Drink's price : " << dprice << endl;
    }
};
int main()
{
    fstream file("que1.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Error in opening source file..!!";
    }

    int choice;
    while (true)
    {
        /* code */

        drinks d1;
        d1.getInfo();

        file.write((char *)&d1, sizeof(d1));
        file.seekg(0);

        string s1 = "Indycola";
        bool found = 0;

        while (file.read((char *)&d1, sizeof(d1)))
        {
            if (d1.dname.compare(s1) == 0)
                found = 1;
        }

        if (found == 1)
            d1.display();

        cout << "Do you want to cont 1/0?\n";
        cin >> choice;
        if (choice == 0)
            break;
    }

    file.close();

    return 0;
}