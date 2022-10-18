#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    const int N = 50;

    ofstream myfile_198;
    myfile_198.open("que1.txt");

    if (!myfile_198)
    {
        cout << "Error in opening source file..!!";
    }

    myfile_198 << "Object Oriented Programming" << endl;
    myfile_198.close();

    ifstream file;
    file.open("que1.txt");
    char arr[N];
    cout << "Content of file is :" << endl;
    while (file)
    {
        file.getline(arr, N);
        cout << arr;
    }
    file.close();

    return 0;
}