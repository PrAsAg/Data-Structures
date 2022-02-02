#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
void stk()
{
    char ch;
    int x, y;
    stack<int> st;
    do
    {
        cout << "Enter integer to push\t";
        cin >> x;
        st.push(x);
        cout << "Press any key to continue Or press 'c' to cancel push" << endl;
        ch = getch();
    } while (ch != 'c');
    do
    {
        if (st.top() != NULL)
        {
            y = st.top();
            st.pop();
            cout << y << endl;
        }
    } while (st.top() != NULL);
}
int main()
{
    stk();
    return 0;
}
