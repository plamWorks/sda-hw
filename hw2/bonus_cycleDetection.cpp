#include<iostream>
#include"llist.cpp"
#include<vector>
using namespace std;
bool has_cycle(LList<int>& l) {

	if (!l.empty())
	{
		vector<elem_link1<int>*> adresses;
		l.IterStart();
		elem_link1<int> * p = l.Iter();
		while (p)
		{
			for (int i = 0; i < adresses.size(); i++)
			{
				if (adresses[i] == p)
				{
					return true;
				}
			}
			adresses.push_back(p);
			p = p->link;
		}
	}
	return false;
}
int main()
{
	LList<int> a;
	a.ToEnd(2);
	a.ToEnd(10);
	a.ToEnd(3);
	a.IterStart();
	elem_link1<int> * p = a.Iter();
	elem_link1<int> * q = p;
	p = p->link;
	p->link = q;
	cout << has_cycle(a) << endl;
	system("pause");
	return 0;
}