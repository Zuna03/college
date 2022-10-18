#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream file1_198("que4.txt");
    const int N = 1000;
    char arr_198[N];
    if (!file1_198)
    {
        cout << "Error in opening source file..!!";
    }

    file1_198 << "This num is One" << endl;
    file1_198 << "Two" << endl;
    file1_198 << "Three" << endl;
    file1_198 << "Four" << endl;
    file1_198 << "Five" << endl;
    file1_198 << "Six" << endl;
    file1_198 << "Seven" << endl;
    file1_198 << "Eight" << endl;
    file1_198 << "Nine" << endl;
    file1_198 << "Ten" << endl;

    file1_198.close();

    ifstream file2_198("que4.txt");
    while (file2_198)
    {
        file2_198.getline(arr_198, N);
        strrev(arr_198);
        cout << arr_198 << endl;
    }
    file2_198.close();

    return 0;
}