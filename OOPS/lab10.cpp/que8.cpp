#include <bits/stdc++.h>
using namespace std;

template <class T_198, int size_198>
class stack_198
{
    T_198 *stk_198;
    int top_198;

public:
    stack_198()
    {
        top_198 = -1;
        stk_198 = new T_198[size_198];
    }

    void push_198(T_198 ele);
    T_198 pop_198();
    void display_198();
};

template <class T_198, int size_198>
void stack_198<T_198, size_198>::push_198(T_198 ele)
{
    if (top_198 == size_198 - 1)
        cout << "Stack is full.\n";
    else
    {
        top_198++;
        stk_198[top_198] = ele;
    }
}

template <class T_198, int size_198>
T_198 stack_198<T_198, size_198>::pop_198()
{
    T_198 popped;
    if (top_198 == -1)
        cout << "ST_198ack is empty\n";
    else
    {
        popped = stk_198[top_198];
        top_198--;
    }
    return popped;
}

template <class T_198, int size_198>
void stack_198<T_198, size_198>::display_198()
{
    while (top_198 != -1)
    {
        cout << stk_198[top_198] << " ";
        top_198--;
    }
    cout << endl;
}
int main()
{
    const int size_198 = 20;
    stack_198<int, size_198> st;
    st.push_198(1);
    st.push_198(2);
    st.push_198(3);
    st.push_198(4);
    st.push_198(5);
    int popped = st.pop_198();
    cout << "The popped element is : " << popped << endl;
    cout << "The stack is : ";
    st.display_198();

    stack_198<char, size_198> st2;
    st2.push_198('a');
    st2.push_198('b');
    st2.push_198('c');

    char popped2 = st2.pop_198();
    cout << "The popped element is : " << popped2 << endl;
    cout << "The stack is : ";
    st2.display_198();

    return 0;
}