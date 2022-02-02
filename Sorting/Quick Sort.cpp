#include <iostream>
#include <cstdlib>
#include<windows.h>
#include<conio.h>
#define size 10

using namespace std;

void GetData(int *a)
{
    cout << "Please enter " << size << " data to be sorted???" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ".";
        cin >> a[i];
    }
}
void ShowData(int *a)
{

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "\t";
        Sleep(300);
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;

    // Getting index of pivot.
    for (i = low; i < high; i++)
    {
        if (a[i] < a[pivot])
        {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    // Swapping value at high and at the index obtained.
    swap(&a[pivot], &a[index]);

    return index;
}

int RandomPivotPartition(int a[], int low, int high)
{
    int pvt, n, temp;
    n = rand();
    // Randomizing the pivot value in the given subpart of array.
    pvt = low + n % (high - low + 1);

    // Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
    swap(&a[high], &a[pvt]);

    return Partition(a, low, high);
}

int Sort(int a[], int low, int high)
{
    int pindex;
    if (low < high)
    {
        // Partitioning array using randomized pivot.
        pindex = RandomPivotPartition(a, low, high);
        // Recursively implementing QuickSort.
        Sort(a, low, pindex - 1);
        Sort(a, pindex + 1, high);
    }
    return 0;
}

int main()
{


    int a[size];
    GetData(a);
    system("cls");
    cout << "-------------------------------------------------Entered Data-------------------------------------------------\n";
    ShowData(a);
    cout << "--------------------------------------------------------------------------------------------------------------\n\n";


    Sort(a, 0, size - 1);


    cout << "-------------------------------------------------Sorted Data-------------------------------------------------\n";
    ShowData(a);
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    getch();
    getch();
    return 0;
}
