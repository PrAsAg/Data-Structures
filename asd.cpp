#include <iostream>
#include <stack>
#include <iomanip>
#define size 10
using namespace std;

class tsp
{
    stack<string> city;
    stack<int> distance;
    string cities[size];
    int flag[size];
    int a[size][size];

public:
    void ResetFlag(int n)
    {
        for (int i = 0; i < n; i++)
        {
            flag[i] = 0;
        }
    }

    void GetCities(int n)
    {
        cout << "Enter cities??\n";
        string temp;

        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ".";
            cin >> cities[i];
        }

        // for (int i = 0; i < 5; i++)
        // {
        //     string temp;
        //     cout << i + 1 << ".";
        //     temp=city.top();
        //     city.pop();
        //     cout<<temp<<endl;

        // }
    }

    void GetDistance(int n)
    {
        // int present,smallestindex,smallest;
        // int previous=999;
        // city.push(cities[0]);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         cout<<cities[i]<<"\tTO\t"<<cities[j]<<"\t";
        //         cin>>present;
        //         if(present<previous && flag[j]==0)
        //         {

        //             previous=present;
        //             smallestindex=j;
        //         }
        //         smallest=previous;

        //     }
        //     previous=999;
        //     city.push(cities[smallestindex]);
        //     distance.push(smallest);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cout << cities[i] << "\tTO\t" << cities[j] << "\t";
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
                    a[i][j] = 0;
                a[i][j] = a[j][i];
            }
        }
        cout << setfill(' ') << setw(10) << " ";
        for (int i = 0; i < n; i++)
        {
            cout << setfill(' ') << setw(20) << cities[i];
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setfill(' ') << setw(10) << cities[i];
            for (int j = 0; j < n; j++)
            {
                cout << setfill(' ') << setw(20) << a[i][j];
            }
            cout << endl;
        }
    }

    // void ExtractCities(){

    // }

    void CalculateDistance(int n)
    {
        int smallest = 999;
        int smallestindex;
        int sum = 0;
        city.push(cities[0]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (flag[i] == 0 && i != j)
                {
                    if (a[i][j] < smallest)
                        smallest = a[i][j];
                        smallestindex=j;

                }
            }
            city.push(cities[smallestindex]);
            sum=sum+smallest;
            smallest=999;
        }
        cout<<"smallest distance::"<<sum;
    }
};

int main()
{
    tsp st;
    int n;
    cout << "Please Enter No. Of Cities??\t\t";
    cin >> n;
    st.ResetFlag(n);
    st.GetCities(n);
    st.GetDistance(n);
    //st.ExtractCities(n);
    st.CalculateDistance(n);

    return 0;
}
