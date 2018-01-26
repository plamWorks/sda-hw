#include<iostream>
#include<fstream>
#include"graph.cpp"
#include<string>
using namespace std;
//reads a file with ribs but adds them both ways 
// if file says "a b" it adds a->b and b->a
void readFromFileAndAddBothWays(graph<int>& g, string filename) 
{																
	ifstream is(filename, ios::in);
	int leftNum, rightNum;
	while (!is.eof())
	{
		is >> leftNum >> rightNum;
		if (!g.top(leftNum))
		{
			g.addTop(leftNum);
		}
		if (!g.top(rightNum))
		{
			g.addTop(rightNum);
		}
		g.addRib(leftNum, rightNum);
		g.addRib(rightNum, leftNum);
	}
	g.print();
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

void DFS(graph<int>& g, LList<int>& l, int& a)  // used in the isConnectedFunction
{
	l.ToEnd(a);
	elem_link1<int>* p = g.point(a);
	p = p->link;
	while (p)
	{
		if (!member(l, p->inf))
		{
			DFS(g, l, p->inf);
		}
		p = p->link;
	}
}
bool isConnected(graph<int>& g)   // if the graph is connected, a DFS from a single top shall traverse all the vertexes
{
	LList<int> l;
	LList<int> v = g.vertexes();
	v.IterStart();
	elem_link1<int> * p = v.Iter();        // we chose the first top and do a DFS
	DFS(g, l, p->inf);
	return l.len() == v.len();    // compare the number of elements in the two lists	
}

int main()
{
	graph<int> g;
	readFromFileAndAddBothWays(g, "ribs.txt");
	cout << "Number of queries?" << endl;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int fromTop, toTop;
		cout << "Cut the line between : ";
		cin >> fromTop >> toTop;
		g.deleteRib(fromTop, toTop);   // 2 ribs are temporary deleted
		g.deleteRib(toTop, fromTop);
		if (isConnected(g))
		{
			cout << "Happy" << endl;
		}
		else
		{
			cout << "Unhappy"<<endl;
		}
		g.addRib(fromTop, toTop);  //add the deleted ribs again for the next query
		g.addRib(toTop, fromTop);
	}
	system("pause");
	return 0;
}