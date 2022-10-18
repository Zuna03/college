#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name_198[20];
    int age_198;
    ofstream out_198("que9.txt");
    cout << "\nEnter name: ";
    cin >> name_198;
    cout << "\nEnter age: ";
    cin >> age_198;
    out_198 << name_198 << endl;
    out_198 << age_198;
    out_198.close();
    ifstream in_198("que9.txt");
    in_198 >> name_198;
    in_198 >> age_198;
    cout << name_198 << endl;
    cout << age_198;
    in_198.close();
}