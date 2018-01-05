void levelOrder(node * root) {
	queue<node*> q;
	if (root != NULL)
	{
		q.push(root);

		while (!q.empty())
		{
			node* current = q.front();
			q.pop();
			if (current->left)
			{
				q.push(current->left);
			}
			if (current->right)
			{
				q.push(current->right);
			}
			cout << current->data << " ";
		}
	}
}