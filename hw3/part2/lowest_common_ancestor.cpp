#include "BinOrdTree.cpp"
#include<queue>
#include <iostream>
using namespace std;

bool contains(BinOrdTree<int>& bot, int n)
{
	if (bot.empty())
	{
		return false;
	}
	if (bot.RootTree() == n)
	{
		return true;
	}

	else
	{
		return contains(bot.LeftTree(), n) || contains(bot.RightTree(), n);
	}
}

int lca(BinOrdTree<int>& bot, int v1, int v2)
{
	int resultLeft = contains(bot.LeftTree(), v1) + contains(bot.LeftTree(), v2);
	int resultRight = contains(bot.RightTree(), v1) + contains(bot.RightTree(), v2);
	if (resultLeft == 1 || resultRight == 1)
		return bot.RootTree();
	else
	{
		if (resultLeft && !bot.LeftTree().empty())
		{
			if (bot.LeftTree().RootTree() == v1 || bot.LeftTree().RootTree() == v2)
			{
				return bot.RootTree();
			}
			else
			{
				return lca(bot.LeftTree(), v1, v2);
			}
		}
		else if (resultRight && !bot.RightTree().empty())
		{
			if (bot.RightTree().RootTree() == v1 || bot.RightTree().RootTree())
			{
				return  bot.RootTree();
			}
			else
			{
				return lca(bot.RightTree(), v1, v2);
			}
		}
		else
		{
			return bot.RootTree();
		}
	}

}
int main() {
	BinOrdTree<int> bot;
	bot.Create();
	int v, w;
	cin >> v >> w;
	int p = lca(bot, v, w);
	cout << "LCA is " << p << endl;
	system("pause");
	return 0;
}