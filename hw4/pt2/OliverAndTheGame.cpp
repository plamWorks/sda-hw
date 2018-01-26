#include<iostream>
#include<fstream>
#include"graph.cpp"
#include<string>
using namespace std;
// creating 2 graphs
// gToRoot is for when the query starts with 0
// gFromRoot is for when the query starts with 1
void readFromFile(graph<int>& gToRoot, graph<int>& gFromRoot, string filename)  
{
	ifstream is(filename, ios::in);                                        
	int leftNum, rightNum;													 
	while (!is.eof())
	{
		is >> leftNum >> rightNum;
		if (!gToRoot.top(leftNum))
		{
			gToRoot.addTop(leftNum);
			gFromRoot.addTop(leftNum);
		}

		if (!gToRoot.top(rightNum))
		{
			gToRoot.addTop(rightNum);
			gFromRoot.addTop(rightNum);
		}
		gFromRoot.addRib(leftNum, rightNum);
		gToRoot.addRib(rightNum, leftNum);
	}
	cout << "To Root: " << endl;
	gToRoot.print();
	cout << endl << "From root" << endl;
	gFromRoot.print();
}

bool member(LList<int>& l, int& a)  // helper function to check if l contains a
{
	l.IterStart();
	elem_link1<int>* p = l.Iter();
	while (p)
	{
		if (p->inf == a)
		{
			return true;
		}
		p = p->link;
	}
	return false;
}
// because of the way the graphs are formed , backtracking is not needed!
void wayToRoot(graph<int>& g, LList<int>& l, int& a)   // finds the path from a to the root(1) and writes it in l
{
	l.ToEnd(a);
	if (a == 1)				// we have reached the root
	{
		return;
	}
	elem_link1<int>* p = g.point(a);
	p = p->link;
	while (p)
	{
		if (!member(l, p->inf))
		{
			wayToRoot(g, l, p->inf);
		}
		p = p->link;
	}
}
void DfsFromTop(graph<int>& g, LList<int>& l, int& from) // finds all the tops we can visit starting at int::from , and writes them in l
{
	l.ToEnd(from);
	elem_link1<int>* p = g.point(from);
	p = p->link;
	while (p)
	{
		if (!member(l, p->inf))
		{
			DfsFromTop(g, l, p->inf);
		}
		p = p->link;
	}
}
int main()
{
	graph<int> gTo, gFrom;
	readFromFile(gTo, gFrom, "ribs.txt");
	cout << "Number of queries?" << endl;
	int q;
	cin >> q;
	int direction, target, start;
	for (int i = 0; i < q; i++)
	{
		cin >> direction >> target >> start;
		if (direction == 0)
		{
			LList<int> l;
			wayToRoot(gTo, l, start);
			if (member(l, target))
			{
				cout << "YES \n";
			}
			else
			{
				cout << "NO \n";
			}
		}
		if (direction == 1)
		{
			LList<int> l;
			DfsFromTop(gFrom, l, start);
			if (member(l, target))
			{
				cout << "YES \n";
			}
			else
			{
				cout << "NO \n";
			}
		}
	}

	system("pause");
	return 0;
}