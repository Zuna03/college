#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line_198;
    ifstream file1_198{"que2.txt"};
    ofstream file2_198{"que2Copy.txt"};

    if (file1_198 && file2_198)
    {
        while (getline(file1_198, line_198))
        {
            file2_198 << line_198 << "\n";
        }
        cout << "Copy Finished \n";
    }
    else
    {
        printf("Cannot read File");
    }

    file1_198.close();
    file2_198.close();

    return 0;
}