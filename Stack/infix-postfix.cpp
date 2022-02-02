#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

//Function to calculate the postfixed expression with some arithmetic values
void calculation(string s)
{
    stack<int> st;
    //st.push(NULL);
    int first, second, x, result;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        // If the scanned character is an operand assign some value and pusg to stack;
        if (/*(s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')*/ isalpha(s[i]))
        {
            cout << "Enter value for " << s[i] << " :: ";
            cin >> x;
            st.push(x);
        }

        //If scanned character is operant then pop two elements from stack and operate as operator and
        //push the result in the stack
        else
        {
            if (s[i] == '^')
            {
                second = st.top();
                st.pop();
                first = st.top();
                st.pop();
                result = pow(first, second);
                st.push(result);
            }
            else if (s[i] == '/')
            {
                second = st.top();
                st.pop();
                first = st.top();
                st.pop();
                result = first / second;
                st.push(result);
            }
            else if (s[i] == '*')
            {
                second = st.top();
                st.pop();
                first = st.top();
                st.pop();
                result = first * second;
                st.push(result);
            }
            else if (s[i] == '+')
            {
                second = st.top();
                st.pop();
                first = st.top();
                st.pop();
                result = first + second;
                st.push(result);
            }
            else if (s[i] == '-')
            {
                second = st.top();
                st.pop();
                first = st.top();
                st.pop();
                result = first - second;
                st.push(result);
            }
            else
            {
                cout << "Error::" << endl;
            }
        }
    }
    result = st.top();
    cout << "Your Result :: " << result << endl;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void conversion(string s)
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for (int i = 0; i < l; i++)
    {

        // If the scanned character is an operand, add it to output string.
        if (/*(s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')*/ isalpha(s[i]))
            ns += s[i];
        //to avoid a(a+b) type problem

        // If the scanned character is an ‘(‘, push it to the stack.
        else if (s[i] == '(')

            st.push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (s[i] == ')')
        {
            while (st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if (st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }

        //If an operator is scanned
        else
        {
            while (st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }
    }
    //Pop all the remaining elements from the stack
    while (st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }

    cout << ns << endl;
    calculation(ns);
}

int main(int argc, char const *argv[])
{
    // cout<<"start"<<endl;
    string expression;
    while (true)
    {
        cout << "start" << endl;
        cin >> expression;
        conversion(expression);
    }
    return 0;
}
