#include<iostream>
#include"llist.cpp"
using namespace std;
/*
Remove all duplicate elements from a sorted linked list
*/
void RemoveDuplicates(LList<int>& l)
{
	l.IterStart();
	elem_link1<int>* p = l.Iter();
	if (p == NULL)
	{
		return;
	}
	else
	{
		while (p->link)
		{
			elem_link1<int>* q = p->link;
			if (p->inf == q->inf)
			{
				p->link = q->link;
				delete q;
			}
			else
			{
				p = p->link;
			}
		}
	}
}
int main()
{
	LList<int> l;
	l.ToEnd(1);
	l.ToEnd(2);
	l.ToEnd(2);
	l.ToEnd(3);
	l.ToEnd(3);
	l.ToEnd(3);

	RemoveDuplicates(l);
	l.print();


	system("pause");
	return 0;
}