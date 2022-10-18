#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    char PID;
    int waiting_time;
    int response_time;
    node *next;
};

class round_robin
{
public:
    node *front = NULL;
    int j = 65; //ascii code

    void create(int n)
    {
        node *new_node = new node;
        new_node->PID = j++;
        new_node->waiting_time = n;
        new_node->response_time = new_node->waiting_time;

        if (front == NULL)
        {
            front = new_node;
            front->next = front;
        }
        else
        {
            node *temp = front;
            while (temp->next != front)
                temp = temp->next;
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void quantum(int t)
    {
        node *temp = front;
        int c = 0, i = 0;//c:cpu time
        while (front != NULL)
        {
            {
                temp->response_time = temp->response_time - t;
                c = c + t;
                if (temp->response_time <= 0)
                {
                    c = c + temp->response_time;
                    cout << temp->PID << "\t\t\t" << c << "\t" << endl;
                    del(temp->PID);
                    if (temp->next == temp)
                    {
                        break;
                    }
                }
                temp = temp->next;
            }
        }
    }

    void del(char x)
    {
        node *p = NULL;
        node *temp = front;

        if (front->PID == x)
        {
            while (temp->next != front)
                temp = temp->next;
            p = front;
            temp->next = front->next;
            front = front->next;
            delete p;
        }
        else
        {
            while (temp->PID != x)
            {
                p = temp;
                temp = temp->next;
            }
            p->next = temp->next;
            delete temp;
        }
    }
};

int main()
{
    round_robin r;
    int i, n, x, y, t;
    cout << "Enter the total no. of processes :";
    cin >> y;
    cout << "Enter the time quantum for the process:";
    cin >> t;
    cout << "Enter the burst time of the processes in order ->\n";
    for (i = 0; i < y; i++)
    {
        cin >> n;
        r.create(n);
    }
    cout << endl;

    cout << "Process ID\t CPU Time\t\n";
    r.quantum(t);

    return 0;
}