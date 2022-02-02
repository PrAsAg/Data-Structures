#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define size 11

    class Queue
{
    int data[size];
    int rear;
    int front;

public:
    Queue()
    {
        rear = 0;
        front = 0;
    }

    bool IsQueueEmpty()
    {
        if (rear == front)
            return true;
        else
            return false;
    }
    bool IsQueueFull()
    {
        if (((rear + 1) % size) == front)
            return true;
        else
            return false;
    }

    void condition()
    {

        int show;
        show = front;
        cout << "----------------------------------Queue Condition--------------------------------\n";
        while (show !=rear)
        {
            show=(show+1)%size;
            cout << data[show] << "\t";
            if (show == rear)
                break;

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
            rear = (rear + 1) % size;
            cout << "Please Enter Data to List in Queue\t";
            cin >> data[rear];
            condition();
        }
    }
    void Dequeue()
    {
        if (IsQueueEmpty())
        {
            cout << "Queue Is Empty!!!!!!!!" << endl;
        }
        else
        {
            front = (front + 1) % size;

            if (rear == front)
            {

                cout << "----------------------------------Queue Condition--------------------------------\n";
                cout << "\n----------------------------------------------------------------------------------\n\n";
                cout << endl;
                return;
            }
            condition();
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
