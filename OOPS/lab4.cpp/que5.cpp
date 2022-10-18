#include <bits/stdc++.h>
using namespace std;

class book_198
{
    char name_198[20];
    char author_198[40];
    float price_198;

public:
    friend void print_range_198(int n_198, book_198 *b_198, float low_range_198, float upp_range_198);

    void getData_198(char n_198[20], char a_198[40], float p_198)
    {
        strcpy(name_198, n_198);
        strcpy(author_198, a_198);
        price_198 = p_198;
    }
    void display_198()
    {
        cout << "The name of the book is :- " << name_198 << endl;
        cout << "The author of the book is :- " << author_198 << endl;
        cout << "The price of the book is :- " << price_198 << endl;
        cout<<endl;
    }
};

void print_range_198(int n_198, book_198 *b_198, float low_range_198, float upp_range_198)
{
    for (int i_198 = 0; i_198 < n_198; i_198++)
    {
        if (b_198[i_198].price_198 >= low_range_198 && b_198[i_198].price_198 <= upp_range_198)
        {
            b_198[i_198].display_198();
        }
    }
}

int main()
{
    int n_198;

    cout << "Enter number of books :- " << endl;
    cin >> n_198;

    book_198 b_198[n_198];

    for (int i_198 = 0; i_198 < n_198; i_198++)
    {
        char Name_198[20];
        char Author_198[40];
        float Price_198;

        cout << "Enter name,author and price of book " << i_198 + 1 << endl;
        cin >> Name_198 >> Author_198 >> Price_198;

        b_198[i_198].getData_198(Name_198, Author_198, Price_198);
    }

    cout << "Enter lower range price and upper range price for the book :-" << endl;
    float low_range_198, upp_range_198;
    cin >> low_range_198 >> upp_range_198;

    print_range_198(n_198, b_198, low_range_198, upp_range_198);

    return 0;
}