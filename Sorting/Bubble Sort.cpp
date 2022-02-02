#include <iostream>
#include <windows.h>
#include <iomanip>
#include<conio.h>
#define size 10

using namespace std;

class Bubble
{
    int data[size];
    int flag;

public:
    void GetData()
    {
        cout << "Please Enter " << size << "Data for Sorting??" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ".";
            cin >> data[i];
        }
    }
    void SortData()
    {
        int temp, flag=1;
        for (int pass = size - 1; pass >= 0 && flag; pass--)
        {
            flag=0;
            for (int i = 0; i <= pass; i++)
            {
                if (data[i] > data[i + 1])
                {
                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;
                    flag=1;
                }
            }
        }
    }
    void DisplayData()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << "\t";
        }
        cout << endl;
    }
    void Visualization()
    {
        int temp,x=1;
        for (int pass = size - 1; pass >= 0; pass--)
        {
            cout<<"Pass-"<<setfill('0')<<setw(2)<<x++<<":\t";
            for (int i = 0; i <= pass; i++)
            {
                if (data[i] > data[i + 1])
                {
                    temp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = temp;
                }
            }
            for(int x=0; x<size;x++){
                cout<<data[x]<<"\t";
                Sleep(300);
            }
            cout<<endl;
        }
    }

};

int main(int argc, const char **argv)
{
    Bubble dt;
    dt.GetData();
    system("cls");
    cout << "-------------------------------------------------Entered Data-------------------------------------------------\n";
    dt.DisplayData();
    cout << "--------------------------------------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "-------------------------------------------------Visualization-------------------------------------------------\n";
    dt.Visualization();
    cout << "---------------------------------------------------------------------------------------------------------------\n\n";
    dt.SortData();

    cout << "-------------------------------------------------Sorted Data-------------------------------------------------\n";
    dt.DisplayData();
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    getch();
    return 0;
}
