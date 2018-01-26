#include<iostream>
#include"BinTree.cpp"
using namespace std;

template <typename T>
void swapNodes(node<T>* root, int level, int k)
{
	if (root == NULL || (root->left == NULL && root->right == NULL)) return;

	if ((level + 1) % k == 0)
	{
		node<T>* temp = root->left;
		root->left = root->right;
		root->right = temp;
	}

	swapNodes(root->left, level + 1, k);
	swapNodes(root->right, level + 1, k);
}

int main()
{
	BinTree<int> binTree;
	int k;
	cin >> k;

	binTree.Create();
	binTree.print();
	cout << endl;

	swapNodes(binTree.GetRoot(), 1, k);
	binTree.print();

	system("pause");
	return 0;
}