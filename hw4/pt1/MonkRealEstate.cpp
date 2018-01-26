#include<iostream>
#include<fstream>
#include"graph.cpp"
#include<string>
using namespace std;

void readFromFile(graph<int>& g, string filename)  //reads the graph from a file
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
int main()
{
	graph<int> g;
	readFromFile(g, "ribs.txt");
	cout << "The Monk Bought : " << g.vertexes().len() << " cities!" << endl; // implementations of vertexes and len can be seen in 
																			  // graph.cpp and llist.cpp
	system("pause");
	return 0;
}