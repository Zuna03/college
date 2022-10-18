#include <bits/stdc++.h>
using namespace std;

class vector_198
{
    int x;
    int y;
    int z;

public:
    //Creating a vector_198
    void create_198(int a, int b, int c);

    //Modifying it's value
    void modify_value_198(char ch, int val);

    //Multiply by scalar value for a given axis
    void multiply_given_198(char ch, int val);

    //Multiply by scalar value for all axes
    void multiply_all_198(int val);

    //display the vector_198 in the form P(10, 20, 30)
    void display_198();

    //Divide by scalar value for all axes
    void divide_all_198(int val);

    //Add by scalar value for all axes.
    void add_all_198(int val);
};

void vector_198 ::create_198(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}

void vector_198 ::modify_value_198(char ch, int val)
{

    if (ch == 'x')
        x = val;
    if (ch == 'y')
        y = val;
    if (ch == 'z')
        z = val;
}

void vector_198 ::multiply_given_198(char ch, int val)
{
    if (ch == 'x')
        x *= val;
    if (ch == 'y')
        y *= val;
    if (ch == 'z')
        z *= val;
}

void vector_198 ::multiply_all_198(int val)
{

    x *= val;
    y *= val;
    z *= val;
}

void vector_198 ::display_198()
{
    cout << "P(" << x << "," << y << "," << z << ")" << endl;
}

void vector_198 ::divide_all_198(int val)
{
    x /= val;
    y /= val;
    z /= val;
}

void vector_198 ::add_all_198(int val)
{
    x += val;
    y += val;
    z += val;
}

int main()
{
    vector_198 v1;

    cout << "Enter the coordinates of the vector_198 :-\n";
    int a, b, c;
    cin >> a >> b >> c;
    v1.create_198(a, b, c);
    v1.display_198();
    cout << endl;

    cout << "Enter the coordinate whose value needs to be modified :-\n ";
    char ch;
    cin >> ch;
    cout << "Enter the value from which the old value of coordinate needs to be modified :-\n";
    int val;
    cin >> val;
    v1.modify_value_198(ch, val);
    v1.display_198();
    cout << endl;

    cout << "Enter the coordinate which needs to be multiplied by scal :-\n ";
    char ch1;
    cin >> ch1;
    cout << "Enter the value from which the coordinate needs to be multipled :-\n";
    int val1;
    cin >> val1;
    v1.multiply_given_198(ch1, val1);
    v1.display_198();
    cout << endl;

    cout << "Enter the value from which the coordinate needs to be multiplied :-\n";
    int val2;
    cin >> val2;
    v1.multiply_all_198(val2);
    v1.display_198();
    cout << endl;

    cout << "Enter the value from which the coordinate needs to be divided :-\n";
    int val3;
    cin >> val3;
    v1.divide_all_198(val3);
    v1.display_198();
    cout << endl;

    cout << "Enter the value from which the coordinate needs to be added :-\n";
    int val4;
    cin >> val4;
    v1.add_all_198(val4);
    v1.display_198();
    cout << endl;

    cout << "The program is terminated.";

    return 0;
}