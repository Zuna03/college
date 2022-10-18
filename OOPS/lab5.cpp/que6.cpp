#include <bits/stdc++.h>
using namespace std;

class test_198
{
    int i;
    static int count_198;

public:
    test_198()
    {
        i = 0;
        count_198++;
    }
    test_198(int k)
    {
        i = k;
        count_198++;
    }
    static void display_198()
    {
        cout << "Objects have been created for " << count_198 << " times" << endl;
    }
    ~test_198()
    {
        cout<<"Here destructor is invoked\n";
    }
};

int test_198::count_198;
int main()
{
    test_198 a;
    a.display_198();
    test_198 b(2);
    b.display_198();

    return 0;
}