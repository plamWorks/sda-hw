#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Queue {
private:
	stack<int> main, helper;
	int front;
public:
	void Enqueue(int&);
	int Dequeue();
	void print();
};

void Queue::Enqueue(int& x)
{
	if (main.empty())
	{
		front = x;
	}
	main.push(x);
}
int Queue::Dequeue()
{
	int result;
	while (!main.empty())
	{
		helper.push(main.top());
		main.pop();
	}
	result = helper.top();
	helper.pop();
	if (!helper.empty())
	{
		front = helper.top();
	}
	while (!helper.empty())
	{
		main.push(helper.top());
		helper.pop();
	}
	return result;
}
void Queue::print()
{
	cout << front << endl;
}

int main()
{
	int command = 0;
	int param = 0;
	Queue queue;

	int q = 0;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> command;
		switch (command)
		{
		case 1: cin >> param; queue.Enqueue(param); break;
		case 2: queue.Dequeue(); break;
		case 3:	queue.print(); break;
		}
	}
	cin.get();
	return 0;
}