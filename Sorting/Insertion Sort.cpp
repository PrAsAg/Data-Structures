#include <iostream>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;
#define size 10

class insertion
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
    void Sort()
    {
        int b;
        int j;

        for (int i = 1; i < size; i++)
        {
            b = a[i];
            j = i;
            while (a[j - 1] > b && j >= 1)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = b;
        }
    }
    void Visualization()
    {
        cout << "-------------------------------------------------Visualization-------------------------------------------------\n";
        int b;
        int j;

        for (int i = 1; i < size; i++)
        {
            cout << "Pass-" << setfill('0') << setw(2) << i << ":\t";
            b = a[i];
            j = i;
            while (a[j - 1] > b && j >= 1)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = b;
            for (int x = 0; x < size; x++)
            {
                cout << a[x] << "\t";
                Sleep(300);
            }
            cout << endl;
        }

        cout << "---------------------------------------------------------------------------------------------------------------\n\n";
    }
};
int main()
{
    insertion sort;
    sort.GetData();
    system("cls");
    cout << "-------------------------------------------------Entered Data-------------------------------------------------\n";
    sort.ShowData();
    cout << "--------------------------------------------------------------------------------------------------------------\n\n";
    sort.Visualization();
    sort.Sort();
    cout << "-------------------------------------------------Sorted Data-------------------------------------------------\n";
    sort.ShowData();
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    getch();
    getch();
}
