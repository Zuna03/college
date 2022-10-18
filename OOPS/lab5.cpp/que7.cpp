#include <bits/stdc++.h>
using namespace std;

class books_198
{
    string author_198;
    string title_198;
    string publisher_198;
    int price_198;
    int stock_198;

public:
    books_198()
    {
    }
    books_198(string a_198, string t_198, string p_198, int pr_198, int s_198)
    {
        author_198 = a_198;
        title_198 = t_198;
        publisher_198 = p_198;
        price_198 = pr_198;
        stock_198 = s_198;
    }
    friend void searchbooks_198(books_198 *b_198, int n_198, string t_198, string a_198);
};

void searchbooks_198(books_198 *b_198, int n_198, string t_198, string a_198)
{
    for (int i = 0; i < n_198; i++)
    {
        if (b_198[i].author_198 == a_198 && b_198[i].title_198 == t_198)
        {
            if (b_198[i].stock_198 <= 0)
            {
                cout << "The required book is not available!! Sorry!!\n";
                return;
            }
            else
            {
                cout << "Author    : " << b_198[i].author_198 << endl;
                cout << "Title     : " << b_198[i].title_198 << endl;
                cout << "Price     : " << b_198[i].price_198 << endl;
                cout << "Publisher : " << b_198[i].publisher_198 << endl;

                cout << "Enter the required amount of books :- ";
                int no_198;
                cin >> no_198;

                if (b_198[i].stock_198 >= no_198)
                {
                    int bill = no_198 * b_198[i].price_198;
                    cout << "Your bill is :- " << bill << "\n";
                    b_198[i].stock_198 -= no_198;
                    cout << "Thank you for the purchase !!\n";
                    cout << "Visit again :)\n";
                    return;
                }
                else
                {
                    cout << "Sorry!! Required copies not in stock\n";
                    cout << "Visit again :)\n";
                    return;
                }
            }
        }
        if (i == n_198 - 1)
        {
            cout << "Sorry the books is not available !!\n";
            cout << "Visit us again\n";
            return;
        }
    }
}
int main()
{
    int n_198;
    cout << "Enter the total number of distinct books available in the book store :- \n";
    cin >> n_198;
    books_198 *b_198 = new books_198[n_198];
    for (int i = 0; i < n_198; i++)
    {
        string a_198, t_198, p_198;
        int m_198, s_198;
        cout << "Enter the price and stock of the book :-\n ";
        cin >> m_198 >> s_198;
        cout << "\n";
        getchar();
        cout << "Enter the  author of the book :- \n";
        getline(cin, a_198);
        cout << "\n";
        cout << "Enter the name of the book :- \n";
        getline(cin, t_198);
        cout << "\n";
        cout << "Enter the publisher of the book :- \n";
        getline(cin, p_198);
        b_198[i] = books_198(a_198, t_198, p_198, m_198, s_198);
    }
    string st_198, sa_198;
    cout << "Enter the name of the book you wish to search :- ";
    getline(cin, st_198);
    cout << "Enter the name of the author of the book you wish to search :- ";
    getline(cin, sa_198);
    searchbooks_198(b_198, n_198, st_198, sa_198);
    cout << "The Program is terminated successfully!! \n";

    return 0;
}