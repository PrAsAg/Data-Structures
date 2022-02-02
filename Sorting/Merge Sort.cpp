#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
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

void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

int main()
{

	int arr[size];
	GetData(arr);
	system("cls");
	cout << "-------------------------------------------------Entered Data-------------------------------------------------\n";
	ShowData(arr);
	cout << "--------------------------------------------------------------------------------------------------------------\n\n";

	MergeSort(arr, 0, size - 1);

	cout << "-------------------------------------------------Sorted Data-------------------------------------------------\n";
	ShowData(arr);
	cout << "-------------------------------------------------------------------------------------------------------------\n";
	getch();
	getch();
	return 0;
}
