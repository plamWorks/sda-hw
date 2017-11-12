#include<iostream>
using namespace std;

// calculated[n] will store the n+1-st fibonacci number
long long calculated[100] = { 1,1 };
long long fib(int n)
{
	if (calculated[n - 1])
	{
		return calculated[n - 1];
	}
	else
	{
		calculated[n - 1] = fib(n - 1) + fib(n - 2);
		return calculated[n - 1];
	}
}
int main()
{
	cout << fib(3);
	cin.get();
	return 0;
}