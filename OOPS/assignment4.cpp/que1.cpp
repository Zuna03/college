#include <bits/stdc++.h>
using namespace std;

// define a class to store DRINKS data
class DRINKS_198
{
    int DCODE_198;
    char DNAME_198[13];
    float DPRICE_198;
    int DSIZE_198;

public:
    DRINKS_198() {}
    void getdrinks_198();  // get DRINKS data from user
    void showdrinks_198(); // display data
    char *getname_198() { return DNAME_198; }
};

void DRINKS_198 ::getdrinks_198()
{
    cout << "\nEnter CODE No. :: ";
    cin >> DCODE_198;
    cin.ignore(); // ignore the newline char inserted when you press enter
    cout << "\nEnter NAME :: ";
    cin.getline(DNAME_198, 13);
    cout << "\nEnter PRICE :: ";
    cin >> DPRICE_198;
    cout << "\nEnter SIZE :: ";
    cin >> DSIZE_198;
}

void DRINKS_198 ::showdrinks_198()
{
    cout << "\nCODE No. :: " << DCODE_198 << endl;
    cout << "\nNAME :: " << DNAME_198 << endl;
    cout << "\nPRICE :: " << DPRICE_198 << endl;
    cout << "\nSIZE :: " << DSIZE_198 << endl;
}

int main()
{
    DRINKS_198 s[3]; // array of 3 DRINKS objects
    fstream file;
    int i;

    file.open("file.txt", ios ::out); // open file for writing
    cout << "\nWriting DRINKS information to the file :- " << endl;
    cout << "\nEnter 3 DRINKSs Details to the File :- " << endl;

    for (i = 0; i < 3; i++)
    {
        s[i].getdrinks_198();
        // write the object to a file
        file.write((char *)&s[i], sizeof(s[i]));
    }

    file.close(); // close the file

    file.open("file.txt", ios ::in); // open file for reading
    cout << "\nReading INDY COLA information FROM the file :- " << endl;

    for (i = 0; i < 3; i++)
    {
        // read an object from a file
        file.read((char *)&s[i], sizeof(s[i]));
        if (strcmp(s[i].getname_198(), "INDY COLA") == 0)
            s[i].showdrinks_198();
    }

    file.close(); // close the file

    return 0;
}