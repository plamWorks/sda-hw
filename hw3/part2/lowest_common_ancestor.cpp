node<int> *lca(node<int> *root, int v1, int v2)
{
	int resultLeft = contains(root->left, v1) + contains(root->left, v2);
	int resultRight = contains(root->right, v1) + contains(root->right, v2);
	if (resultLeft == 1 || resultRight == 1)
		return root;
	else
	{
		if (resultLeft && root->left)
		{
			if (root->left->inf == v1 || root->left->inf == v2)
			{
				return root;
			}
			else
			{
				return lca(root->left, v1, v2);
			}
		}
		if (resultRight && root->right)
		{
			if (root->right->inf == v1 || root->right->inf == v2)
			{
				return root;
			}
			else
			{
				return lca(root->right, v1, v2);
			}
		}
	}
}