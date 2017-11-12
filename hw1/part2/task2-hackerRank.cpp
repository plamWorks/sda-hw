#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	stack<int> main, tracker;
	int n;
	cin >> n;
	cin.get();
	int counter = 1;
	int command;
	int param;
	while (counter <= n)
	{
		cin >> command;

		switch (command)
		{
		case 1: cin >> param;
			if (main.empty())
			{
				tracker.push(param);
				main.push(param);
			}
			else
			{
				int currMax = tracker.top();
				tracker.push(max(currMax, param));
				main.push(param);
			}
			break;

		case 2: main.pop();
			tracker.pop();
			break;
		case 3: cout << tracker.top() << endl; break;
		default: cout << "Bad command !";
		}
		counter++;
	}
	cin.get();
	cin.get();
	return 0;
}