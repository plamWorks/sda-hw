#include "BinTree.cpp"
#include<queue>
#include <iostream>
using namespace std;

template<class T>
void BinTree<T>::traversalPrint() const
{
	queue<node<T>*> q;
	if (root != NULL)
	{
		q.push(root);
		while (!q.empty())
		{
			node<T>* current = q.front();
			q.pop();
			if (current->left)
			{
				q.push(current->left);
			}
			if (current->right)
			{
				q.push(current->right);
			}
			cout << current->inf << " ";
		}
	}
}
1
int main() {
	BinTree<int> tree;
	tree.Create();
	tree.traversalPrint();
	system("pause");
	return 0;
}