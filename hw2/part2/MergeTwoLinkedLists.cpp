/*
Merge two sorted lists A and B as one linked list
Node is defined as
*/
struct Node
{
int data;
struct Node *next;
}

Node* MergeLists(Node *headA, Node* headB)
{
	if (headA)
	{
		if (headB)
		{
			Node *newHead, *p, *currentA, *currentB, *elementToAdd;
			if (headA->data < headB->data)
			{
				newHead = headA;
			}
			else
			{
				newHead = headB;
			}
			p = newHead;
			currentA = headA;
			currentB = headB;
			while (p)
			{
				if (currentA)
				{
					if (currentB)
					{
						if (currentA->data <= currentB->data)
						{
							elementToAdd = currentA;
							currentA = currentA->next;
						}
						else
						{
							elementToAdd = currentB;
							currentB = currentB->next;
						}
					}
					else
					{
						elementToAdd = currentA;
						currentA = currentA->next;
					}
				}
				else
				{
					if (currentB)
					{
						elementToAdd = currentB;
						currentB = currentB->next;
					}
					else
					{
						elementToAdd = NULL;
					}
				}
				p->next = elementToAdd;
				p = elementToAdd;
			}
			return newHead;
		}
		else
		{
			return headA;
		}
	}
	else
	{
		return headB;
	}
}