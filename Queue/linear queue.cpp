#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
#define size 10

class Queue
{
    int data[size];
     int rear;
     int front;

public:
    Queue()
    {
        rear = -1;
        front = 0;
    }
    void condition()
    {
        int show;
        show = front;
        cout << "----------------------------------Queue Condition--------------------------------\n";
        while(true)
        {
            cout << data[show] << "\t";
            if(show==rear)
                break;
            show++;
        }
        cout << "\n----------------------------------------------------------------------------------\n\n";
        cout << endl;
    }

    void Enqueue()
    {
        if (IsQueueFull())
        {
            cout << "Queue Is Full!!!!!!" << endl;
            condition();
        }
        else
        {
            rear++;
            cout << "Please Enter Data to List in Queue\t";
            cin >> data[rear];
            condition();
        }
    }

    void Dequeue()
    {
        if (IsQueueEmpty())
        {
            cout << "Queue Is Empty!!!!!!" << endl;
        }
        else
        {
            front++;
            if(rear<front){
                    cout << "----------------------------------Queue Condition--------------------------------\n";
                    cout << "\n----------------------------------------------------------------------------------\n\n";
                    cout << endl;
                    return;

            }
            condition();
        }
    }

    bool IsQueueEmpty()
    {
        if (rear < front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsQueueFull()
    {
        if ((size - 1) == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int choice;
    Queue Q;
    while (true)
    {
        cout << "Please Enter\n\t"
             << "1 - For Enqueue\n\t2 - for Dequeue" << endl;
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            Q.Enqueue();

           // Q.condition();
        }
        else if (choice == 2)
        {
            system("cls");
            Q.Dequeue();

           // Q.condition();
        }
        else
        {
            cout << "Error Input Please Review your entry!!!!!!!!!" << endl;
        }
    }

    return 0;
}
