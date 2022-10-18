#include <bits/stdc++.h>

using namespace std;
struct GAME
{
    char GameName[30];
    char participant[10][30];
};

void CreateNewFile()
{
    GAME g1;
    ifstream fin;
    ofstream fout;
    fin.open("GAME.DAT", ios::in | ios::binary);
    fout.open("BASKET.DAT", ios::out | ios::binary);
    while (!fin.eof())
    {
        fin.read((char *)&g1, sizeof(g1));
        if (strcmp(g1.GameName, "Basket Ball") == 0)
            fout.write((char *)&g1, sizeof(g1));
    }
    fin.close();
    fout.close();
}
int main()
{
    CreateNewFile();
    return 0;
}