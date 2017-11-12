#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int findTheMaximumNumberOfElementsToBeRemoved(stack<int> & a, stack<int> & b, int sizeOfA, int sizeOfB, int maxSum)
{
	vector<int> va, vb;
	for (int i = 0; i < sizeOfA; i++)
	{
		va.push_back(a.top());
		a.pop();
	}
	for (int i = 0; i < sizeOfB; i++)
	{
		vb.push_back(b.top());
		b.pop();
	}

	int sum = 0, count = 0, temp = 0, i = 0, j = 0;

	while (i<sizeOfA && sum + va[i] <= maxSum) { 
		sum += va[i];
		i++;
	}
	count = i;

	while (j<sizeOfB && i >= 0) {          
		sum += vb[j];
		j++;
		while (sum>maxSum && i>0) {
			i--;
			sum -= va[i];
		}
		if (sum <= maxSum && i + j>count)
			count = i + j;
	}
	return count;
}

void clearAll(stack<int> & a, stack<int> & b)
{
	while (!a.empty())
	{
		a.pop();
	}
	while (!a.empty())
	{
		b.pop();
	}
}
int main()
{
	int n;
	stack<int> a,b,helper;
	cin >> n;
	int counter = 0;
	int lengthOfA, lengthOfB, maxSum;
	while (counter < n)
	{
		cin >> lengthOfA >> lengthOfB >> maxSum;
		int currentNumber;
		for (int i = 0; i < lengthOfA + lengthOfB; i++)
		{
			cin >> currentNumber;
			helper.push(currentNumber);
		}
		for (int i = 0; i < lengthOfB; i++)
		{
			b.push(helper.top());
			helper.pop();
		}
		for (int i = 0; i < lengthOfA; i++)
		{
			a.push(helper.top());
			helper.pop();
		}
	
		cout << findTheMaximumNumberOfElementsToBeRemoved( a, b, lengthOfA,lengthOfB,maxSum)<<endl;

		clearAll(a, b);
		counter++;
	}
	cin.get();
	cin.get();
	return 0;
}