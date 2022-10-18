#include <bits/stdc++.h>
using namespace std;

class ex_198
{
    static int i;

public:
    ex_198()
    {
        i++;
        cout << "Constructor was invoked here for object " << i << endl;
    }
    ~ex_198()
    {
        cout << "Destructor was invoked here for object " << i << endl;
    }
};
int ex_198::i;

int main()
{
    cout<<"Main function\n";
    ex_198 a;
    ex_198 b;

    return 0;
}