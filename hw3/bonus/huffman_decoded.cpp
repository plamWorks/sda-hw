void decode_huff(node * root, string s)
{
	node* p = root;
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
			cout << p->data;
			p = root;
		}
	}
}