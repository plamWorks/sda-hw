#include "BinTree.cpp"
#include <iostream>
using namespace std;

void helpHeight(node<int>* root, int& current, int& max)
{
	if (root == NULL)
	{
		return;
	}
	if (current>max)
	{
		max = current;
	}
	current++;
	helpHeight(root->left, current, max);
	helpHeight(root->right, current, max);
	current--;
}

int height(node<int>* root) {
	int max = 0;
	int current = 0;
	helpHeight(root, current, max);
	return max;
}

int main() {
	BinTree<int> tree;
	tree.Create();
	cout << height(tree.GetRoot());
	system("pause");
	return 0;
}