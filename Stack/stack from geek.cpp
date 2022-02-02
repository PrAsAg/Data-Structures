
#include <iostream>

using namespace std;

#define MAX 100

class Stack
{
	int top;
	int a[MAX];

public:
	Stack()
	{
		top = -1;
	}
	bool push(int x);
	int pop();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1))
	{
		cout << "Stack Overflow";
		return false;
	}
	else
	{
		a[++top] = x;
		cout << "\t" << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if (top < 0)
	{
		cout << "Stack Underflow";
		return 0;
	}
	else
	{
		int x = a[top--];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int main()
{
	Stack s;
	int x;
	for (int i = 0; i < 10; ++i)
	{
		cout << i + 1 << ".";
		cin >> x;
		s.push(x);
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << s.pop() << " Popped from stack\n";
	}
	return 0;
}
