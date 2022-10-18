#include <iostream>
using namespace std;
class A_198
{
public:
    class B_198
    {
    private:
        int num_198;

    public:
        void get_data_198(int n)
        {
            num_198 = n;
        }
        void display_198()
        {
            cout << "The number is " << num_198;
        }
    };
};
int main()
{
    cout << "Nested classes " << endl;
    A_198 ::B_198 obj;
    obj.get_data_198(9);
    obj.display_198();
    return 0;
}