#include<iostream>
#include<fstream>
#include"graph.cpp"
#include<string>
using namespace std;

void readFromFile(graph<int>& g, string filename) // reads the graph from a file where every row contains one rib
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
	}
	g.print();
}

bool member(LList<int>& l, int& a)  //helper function to check if l contains a
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

void hasCycleFromTop(graph<int>& g, LList<int>& l, const int& a, bool& flag)  // detects a cycle and stores the result in flag
{
	l.ToEnd(a);
	int copyOfA = a;
	elem_link1<int>* p = g.point(a);
	p = p->link;
	while (p)
	{
		if (!member(l, p->inf))
		{
			hasCycleFromTop(g, l, p->inf, flag);
		}
		else
		{
			flag = true;
		}
		p = p->link;
	}
	int dum;
	l.IterStart();
	elem_link1<int> * q = l.Iter();
	while (q)
	{
		if (q->inf == copyOfA)
		{
			l.DeleteElem(q, dum);
			return;
		}
		q = q->link;
	}
}

// gets the first top of the graph and checks if there are any cycles.
// There is no need to check for the other vertexes
// bc at this stage we assume that the graph is connected
bool hasCycle(graph<int> & g) 
{									
	LList<int> l,v = g.vertexes();   
	v.IterStart();
	bool result = false;
	elem_link1<int> * p = v.Iter();
	hasCycleFromTop(g, l, p->inf, result);
	return result;
}

void DFS(graph<int>& g, LList<int>& l, int& a)
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

bool isTree(graph<int>& g) // checks if g is a tree
{
	return isConnected(g) && !hasCycle(g);
}
int main()
{
	graph<int> g;
	readFromFile(g, "ribs.txt");
	cout << isTree(g)<<endl;
	system("pause");
	return 0;
}