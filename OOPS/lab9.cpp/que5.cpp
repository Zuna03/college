#include <iostream>
#include <string.h>
using namespace std;

class media_198
{
protected:
    char title_198[50];
    float price_198;

public:
    void getdata()
    {
        cout << "Enter the title: ";
        cin >> title_198;
        cout << "Enter Price: ";
        cin >> price_198;
    }
    virtual void display() = 0;
};

class book_198 : public media_198
{
    int pages_198;

public:
    void getbook()
    {
        cout << "Enter number of pages_198: ";
        cin >> pages_198;
    }
    void display()
    {
        cout << "TITLE: " << title_198 << endl;
        cout << "Price: " << price_198 << endl;
        cout << "Pages: " << pages_198 << endl;
    }
};

class tape_198 : public media_198
{
    float time_198;

public:
    void gettape()
    {
        cout << "Enter play time_198: ";
        cin >> time_198;
    }
    void display()
    {
        cout << "TITLE: " << title_198 << endl;
        cout << "Price: " << price_198 << endl;
        cout << "Play Time: " << time_198 << endl;
    }
};
int main()
{
    media_198 *bptr_198[2];
    book_198 b_198;
    tape_198 t_198;
    bptr_198[0] = &b_198;
    bptr_198[1] = &t_198;
    cout << "BOOK DETAILS:\n";
    bptr_198[0]->getdata();
    b_198.getbook();
    bptr_198[0]->display();

    cout << "TAPE DETAILS:\n";
    bptr_198[1]->getdata();
    t_198.gettape();
    bptr_198[1]->display();
    return 0;
}