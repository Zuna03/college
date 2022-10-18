#include <bits/stdc++.h>
using namespace std;

static int total_cost_198 = 0;
class items_198
{
    string code_198;
    string name_198;
    int price_198;
    int quantity_198;

public:
    items_198()
    {
    }
    void get_data_198(string c1, string n, int p)
    {
        code_198 = c1;
        name_198 = n;
        price_198 = p;
    }

    void get_quantity_198(int q)
    {
        quantity_198 = q;
    }

    friend void cal_price_198(items_198 i1, int n);
    friend void display(items_198 *i1);
};

void display(items_198 *i1)
{
    cout << setw(5) << "S.no" << setw(5) << "code" << setw(15) << "name" << setw(25) << "price" << setw(30) << "quantity" << setw(35) << "Total" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(5) << i + 1 << setw(5) << i1[i].code_198 << setw(15) << i1[i].name_198 << setw(25) << i1[i].price_198 << setw(30) << i1[i].quantity_198 << setw(35) << i1[i].quantity_198 * i1[i].price_198 << endl;
        total_cost_198 += (i1[i].quantity_198 * i1[i].price_198);
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(115) << "Total = Rs." << total_cost_198 << "/-" << endl;
}

int main()
{
    items_198 *it = new items_198[10];
    for (int i = 0; i < 10; i++)
    {

        cout << "Enter code of the item-" << i + 1 << "\n";
        string c1;
        getchar();
        getline(cin, c1);

        cout << "Enter name of the item " << i + 1 << "\n";
        string n1;
        getchar();
        getline(cin, n1);

        cout << "Enter price of the item " << i + 1 << "\n";
        int p1;
        cin >> p1;

        it[i].get_data_198(c1, n1, p1);
        cout << "Enter the quantity in which you want the product " << i + 1 << "\n";
        int n;
        cin >> n;
        it[i].get_quantity_198(n);
    }
    cout << endl;
    display(it);

    return 0;
}