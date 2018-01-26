#include "BinTree.cpp"
#include <iostream>
using namespace std;

bool isGreaterThanAllOrEqual(node<int>* root, int data)
{
	if (!root)
	{
		return true;
	}
	if (root->inf >= data)
	{
		return false;
	}
	else
	{
		return isGreaterThanAllOrEqual(root->left, data) && isGreaterThanAllOrEqual(root->right, data);
	}
}
bool isLessThanAllOrEqual(node<int>* root, int data)
{
	if (!root)
	{
		return true;
	}
	if (root->inf <= data)
	{
		return false;
	}
	else
	{
		return (isLessThanAllOrEqual(root->left, data) && isLessThanAllOrEqual(root->right, data));
	}
}
bool checkBST(node<int>* root) {
	if (!root)
	{
		return true;
	}
	if (isGreaterThanAllOrEqual(root->left, root->inf) && isLessThanAllOrEqual(root->right, root->inf))
	{
		return (checkBST(root->left) && checkBST(root->right));
	}
	else
	{
		return false;
	}
}
int main()
{
	BinTree<int> tree;
	tree.Create();
	cout << checkBST(tree.GetRoot());
	system("pause");
	return 0;
}