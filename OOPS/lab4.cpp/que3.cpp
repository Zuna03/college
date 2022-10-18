#include <bits/stdc++.h>
using namespace std;

class test_198
{
    int data_198;
    static int in_198;
    static int out_198;

public:
    void input_198(int val_198)
    {
        data_198 = val_198;
        ++in_198;
    }
    void output_198()
    {
        cout << data_198 << endl;
        ++out_198;
    }

    static void display_198()
    {
        cout << "Present input function count is :- " << in_198 << endl;
        cout << "Present output function count is :- " << out_198 << endl;
    }
};

int test_198::in_198 = 0;
int test_198::out_198 = 0;

int main()
{

    test_198 a_198;
    test_198 b_198;
    test_198 c_198;

    int x_198, y_198, z_198;
    cin >> x_198 >> y_198 >> z_198;

    a_198.input_198(x_198);
    b_198.input_198(y_198);
    c_198.input_198(z_198);

    a_198.output_198();
    b_198.output_198();
    c_198.output_198();

    test_198 ::display_198();

    return 0;
}