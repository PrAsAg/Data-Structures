#include <iostream>
#include <conio.h>
#include <windows.h>
#define Max 100
using namespace std;
class stack
{
	int top = -1;
	int stk[Max];

public:
	void push_stack(int x)
	{
		//cout<<"push stack function"<<endl;
		if (top >= (Max - 1))
		{
			cout << "Stack overflow::" << endl;
		}
		else
		{

			stk[++top] = x;
			cout << "\t" << x << "\tis pushed to stack" << endl;
		}
	}
	void Pop_stack()
	{
		//cout<<"pop stack function"<<endl;
		if (top < 0)
			cout << "Stack Underflow::" << endl;
		else
		{
			cout << stk[top--] << "\t is popped from stack" << endl;
		}
	}
	void stack_condition()
	{
		cout << "stack::" << endl;
		for (int i = top; i >= 0; i--)
		{
			cout << "\t" << stk[i] << endl;
		}
	}
};
int main(int argc, char const *argv[])
{
	cout << "Execution started" << endl;
	stack S;
	int x;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << ".";
		cin >> x;
		S.push_stack(x);
	}
	cout << "\n\nPress any key to continue!!!!!!!" << endl;
	getch();
	system("cls");
	S.stack_condition();
	cout << "\n\nPress any key to continue!!!!!!!" << endl;
	getch();
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		S.Pop_stack();
	}
	return 0;
}
