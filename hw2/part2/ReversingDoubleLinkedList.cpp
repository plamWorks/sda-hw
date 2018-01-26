#include<iostream>
#include"dllist.cpp"
using namespace std;

void DList<int>::Reverse()
{
	node<int>* p = start;
	if (p)
	{
		p->prev = p->next;
		p->next = NULL;
		node<int>* q;
		while (p->prev)
		{
			p = p->prev;
			q = p->next;
			p->next = p->prev;
			p->prev = q;
		}
	}
	start = p;
}
int main()
{
	DList<int> dl;
	dl.ToEnd(2);
	dl.ToEnd(10);
	dl.ToEnd(15);
	dl.ToEnd(31);
	dl.ToEnd(11);
	dl.print();
	dl.Reverse();
	dl.print();
	system("pause");
	return 0;
}