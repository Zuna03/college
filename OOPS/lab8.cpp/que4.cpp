#include <bits/stdc++.h>
using namespace std;

class string_198
{
    char *s;
    int n;

public:
    string_198()
    {
        s = NULL;
        n = 0;
    }

    string_198(const char *x)
    {
        n = strlen(x);
        s = new char[n + 1];
        strcpy(s, x);
    }

    string_198(const string_198 &c)
    {
        n = c.n;
        s = c.s;
    }

    string_198 operator+(string_198 s1)
    {

        string_198 res;
        res.n = n + s1.n;

        res.s = new char[res.n + 1];
        strcpy(res.s, s);
        strcat(res.s, s1.s);

        return res;
    }

    string_198 operator=(string_198 s1)
    {
        string_198 res;
        res.n = s1.n;
        res.s = new char[res.n + 1];
        strcpy(res.s, s1.s);
        return res;
    }
    void display_198()
    {
        cout << s << endl;
    }
};
int main()
{
    string_198 s1("ABC");
    string_198 s2("DEF");

    cout << "First string is : ";
    s1.display_198();

    cout << "Second string is : ";
    s2.display_198();

    cout << "The resultant string is : ";
    string_198 ans = s1 + s2;
    ans.display_198();

    string_198 s4 = s1;
    cout << "Te copied string is : ";
    s4.display_198();

    return 0;
}