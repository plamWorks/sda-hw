#include<iostream>
#include"llist.cpp"
using namespace std;
/*
Merge two sorted lists A and B as one linked list
*/
LList<int> MergeLists(LList<int>& a, LList<int>& b)
{
	LList<int> result;
	if (!a.empty())
	{
		if (!b.empty())
		{
			a.IterStart();
			b.IterStart();
			elem_link1<int>* currentA = a.Iter();
			elem_link1<int>* currentB = b.Iter();
			while (currentA && currentB)
			{
				if (currentA->inf < currentB->inf)
				{
					result.ToEnd(currentA->inf);
					currentA = currentA->link;
				}
				else
				{
					result.ToEnd(currentB->inf);
					currentB = currentB->link;
				}
			}
			if (currentA)
			{
				while (currentA)
				{
					result.ToEnd(currentA->inf);
					currentA = currentA->link;
				}
			}
			if (currentB)
			{
				while (currentB)
				{
					result.ToEnd(currentB->inf);
					currentB = currentB->link;
				}
			}
		}
		else
		{
			result = a;
		}
	}
	else
	{
		result = b;
	}
	return result;
}
int main()
{
	LList<int> a, b;
	a.ToEnd(1);
	a.ToEnd(2);
	a.ToEnd(2);
	a.ToEnd(10);
	a.ToEnd(30);

	b.ToEnd(4);
	b.ToEnd(31);
	LList<int> res = MergeLists(a, b);
	res.print();

	system("pause");
	return 0;
}