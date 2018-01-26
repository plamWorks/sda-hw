#include "BinTree.cpp"
#include <iostream>
#include<string>
using namespace std;

struct douplet {
	int freq;
	char data;
	friend ostream& operator<<(ostream& out, douplet d)
	{
		out << d.data;
		return out;
	}
	friend istream& operator>>(istream& in, douplet d)
	{
		cout << "freq: ";
		in >> d.freq;
		cout << "data: ";
		in >> d.data;
		return in;
	}
};

void decode_huff(node<douplet> * root, string s)
{
	node<douplet>* p = root;
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] != '0')
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
		if (!p->left && !p->right)
		{
			cout << p->inf.data;
			p = root;
		}
	}
}
int main()
{
	BinTree<douplet> tree;
	tree.Create();
	string s;
	cin >> s;
	decode_huff(tree.GetRoot(), s);
	system("pause");
	return 0;
}