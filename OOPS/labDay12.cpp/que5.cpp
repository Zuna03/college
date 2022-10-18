#include <iostream>
using namespace std;

class student_198
{
public:
    student_198()
    {
    }
    ~student_198()
    {
    }
};
int main()
{
    int choice_198, n, memorySize_198;

    while (true)
    {
        try
        {
            cout << "Enter number of students \n";
            cin >> n;
            student_198 *a = new student_198[n];
            cout << "Enter hypothetical memory size\n";
            cin >> memorySize_198;
            delete[] a;
            if (sizeof(a) > memorySize_198)
                throw -1;
            else
                cout << "Memory allocated successfully\n";
        }
        catch (int x)
        {
            cout << "Memory allocation not possible exception thrown with " << x << endl;
        }

        cout << "Do you want to cont 1/0 ?\n";
        cin >> choice_198;
        if (choice_198 == 0)
            break;
    }
    cout << "Program terminated successfully\n";

    return 0;
}