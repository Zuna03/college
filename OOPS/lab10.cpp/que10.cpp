#include <bits/stdc++.h>
using namespace std;

template <class T_198, int size_198>
class queue_198
{
    T_198 *q;
    int front_198, rear_198;

public:
    queue_198()
    {
        front_198 = -1;
        rear_198 = -1;
        q = new T_198[size_198];
    }

    void enqueue_198(T_198 ele);
    T_198 dequeue_198();
    void display_198();
};

template <class T_198, int size_198>
void queue_198<T_198, size_198>::enqueue_198(T_198 ele)
{
    if (rear_198 == size_198 - 1)
    {
        cout << "Stack is full\n";
        return;
    }
    else
    {
        q[rear_198] = ele;
        rear_198++;
    }
}

template <class T_198, int size_198>
T_198 queue_198<T_198, size_198>::dequeue_198()
{
    T_198 popped;
    if (front_198 == rear_198)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        popped = q[front_198];
        front_198++;
    }
    return popped;
}

template <class T_198, int size_198>
void queue_198<T_198, size_198>::display_198()
{
    int temp = front_198;
    while (temp != rear_198)
    {
        cout << q[temp] << " ";
        temp++;
    }
    cout << endl;
}
int main()
{
    const int size_198 = 20;

    queue_198<int, size_198> q;
    q.enqueue_198(1);
    q.display_198();
    q.enqueue_198(2);
    q.display_198();
    q.enqueue_198(3);
    q.display_198();
    q.enqueue_198(4);
    q.display_198();
    int popped = q.dequeue_198();
    cout << "The popped element is : " << popped << endl;
    q.display_198();

    queue_198<double, size_198> q2;
    q2.enqueue_198(2.345);
    q2.display_198();
    q2.enqueue_198(4.345);
    q2.display_198();
    q2.enqueue_198(12.345);
    q2.display_198();
    double popped2 = q2.dequeue_198();
    cout << "The popped element is : " << popped2 << endl;
    q2.display_198();

    return 0;
}