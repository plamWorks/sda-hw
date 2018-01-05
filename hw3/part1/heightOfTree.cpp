int height(Node* root) {
	int max = 0;
	int current = 0;
	helpHeight(root, current, max);
	return max;
}
void helpHeight(Node* root, int& current, int& max)
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