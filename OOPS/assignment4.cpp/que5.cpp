#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
class BOOK_198
{
    int Bno_198;
    char title_198[30];

public:
    int RBno_198() { return Bno_198; }
    void enter_198()
    {
        cin >> Bno_198;
        gets(title_198);
    }
    void display_198()
    {
        cout << Bno_198 << title_198 << endl;
    }
};
void bookSearch_198()
{
    fstream FIL;
    FIL.open("BOOK_198.DAT", ios::binary | ios::in);
    BOOK_198 B;
    int bn, Found = 0;
    cout << "enter_198 Book Num to search: ";
    cin >> bn;
    while (FIL.read((char *)&B, sizeof(B)))
        if (B.RBno_198() == bn)
        {
            B.display_198();
            Found++;
        }
    if (Found == 0)
        cout << "Sorry! Book not found!!!" << endl;
    FIL.close();
}
int main()
{
    bookSearch_198();
    return 0;
}