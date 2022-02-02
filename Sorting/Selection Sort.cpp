#include <iostream>
#include <iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;
#define size 10

class selection
{
    int a[size];

public:
    void GetData()
    {
        cout << "Please enter " << size << " data to be sorted???" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            cin >> a[i];
        }
    }
    void ShowData()
    {

        for (int i = 0; i < size; i++)
        {
            cout << a[i] << "\t";
            Sleep(300);
        }
        cout << endl;

    }
    void visualiztion()
    {
        int temp;
        int min;
        cout << "-------------------------------------------------Visualization-------------------------------------------------\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Pass-" << setfill('0') << setw(2) << i+1 << ":\t";
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                if (a[j] < a[min] || a[j]==a[min])
                {
                    min = j;
                }
            }
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
            for (int x = 0; x < size; x++)
            {
                cout << a[x] << "\t";
                Sleep(300);
            }
            cout << endl;
        }

        cout << "---------------------------------------------------------------------------------------------------------------\n\n";
    }
    void sort()
    {
        int temp;
        int min;
        for (int i = 0; i < size; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                if (a[j] < a[min]||a[j]==a[min])
                {
                    min = j;
                }
            }
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
};

int main()
{
    selection sort;
    sort.GetData();
    system("cls");
    cout << "-------------------------------------------------Entered Data-------------------------------------------------\n";
    sort.ShowData();
    cout << "--------------------------------------------------------------------------------------------------------------\n\n";
    sort.visualiztion();
    sort.sort();
    cout << "-------------------------------------------------Sorted Data-------------------------------------------------\n";
    sort.ShowData();
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    getch();
    getch();
}
