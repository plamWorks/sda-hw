The Node struct is defined as follows :
struct Node {
	int data;
	Node* left;
	Node* right;
}
*/
bool isGreaterThanAllOrEqual(Node* root, int data)
{
	if (!root)
	{
		return true;
	}
	if (root->data >= data)
	{
		return false;
	}
	else
	{
		return isGreaterThanAllOrEqual(root->left, data) && isGreaterThanAllOrEqual(root->right, data);
	}
}
bool isLessThanAllOrEqual(Node* root, int data)
{
	if (!root)
	{
		return true;
	}
	if (root->data <= data)
	{
		return false;
	}
	else
	{
		return (isLessThanAllOrEqual(root->left, data) && isLessThanAllOrEqual(root->right, data));
	}
}
bool checkBST(Node* root) {
	if (!root)
	{
		return true;
	}
	if (isGreaterThanAllOrEqual(root->left, root->data) && isLessThanAllOrEqual(root->right, root->data))
	{
		return (checkBST(root->left) && checkBST(root->right));
	}
	else
	{
		return false;
	}
}