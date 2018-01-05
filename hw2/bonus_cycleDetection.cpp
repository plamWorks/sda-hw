/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
struct Node {
int data;
struct Node* next;
}
*/
#include<vector>
bool has_cycle(Node* head) {

	if (head)
	{
		vector<Node*> adresses;
		Node* p = head;
		while (p)
		{
			for (int i = 0; i < adresses.size(); i++)
			{
				if (adresses[i] == p)
				{
					return true;
				}
			}
			adresses.push_back(p);
			p = p->next;
		}
		return false;
	}
	else
	{
		return false;
	}
	// Complete this function
	// Do not write the main method
}
