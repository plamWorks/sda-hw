#include<iostream>
using namespace std;

int fib_simple(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fib_simple(n - 1) + fib_simple(n - 2);
	}
}

int main()
{
	cout << fib_simple(20)<<endl;
	cin.get();
	return 0;
}