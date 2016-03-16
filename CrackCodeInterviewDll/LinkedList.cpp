#include "stdafx.h"
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	/* Initialize the head and tail node */
	pHead = pTail = 0;
}

LinkedList::LinkedList(int val)
{
	/* Create a new node, acting as both the head and tail node */
	pHead = new Node(val);
	pTail = pHead;
}

LinkedList::~LinkedList()
{
	/*
	* Leave it empty temporarily.
	* It will be described in detail in the example "How to delete a linkedlist".
	*/
}

void LinkedList::traverse_and_print()
{
	Node *p = pHead;

	/* The list is empty? */
	if (pHead == NULL) {
		cout << "The list is empty" << endl;
		return;
	}

	cout << "LinkedList: ";
	/* A basic way of traversing a linked list */
	while (p != NULL) { /* while there are some more nodes left */
						/* output the value */
		cout << p->value;
		/* The pointer moves along to the next one */
		p = p->pNext;
	}
	cout << endl;
}

void LinkedList::add_node_to_tail(int data)
{
	//Node newNode = Node(data);
	Node* pNewNode = new Node(data);

	if (this->is_empty())
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		Node *cur = pHead;
		while (cur)
		{
			if (cur->pNext == NULL)
			{
				cur->pNext = pNewNode;
				pTail = pNewNode;
				return;
			}
			cur = cur->pNext;
		}
	}
}

void LinkedList::add_node_to_head(int data)
{
	Node* pNewNode = new Node(data);

	if (this->is_empty())
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pNewNode->pNext = pHead;
		pHead = pNewNode;		
	}
}

//got some problems...
void LinkedList::add_node2(int data)
{
	Node newNode = Node(data);
	//Node* pNewNode = new Node(data);

	if (this->is_empty())
	{
		pHead = &newNode;
		pTail = &newNode;
	}
	else
	{
		pTail->pNext = &newNode;
		pTail = &newNode;
	}
}

bool LinkedList::is_empty()
{
	return pHead == NULL ? true : false;
}

bool LinkedList::has_duplicate_element()
{
	for (Node* ptr1 = pHead; ptr1->pNext != NULL; ptr1 = ptr1->pNext)
	{
		for (Node* ptr2 = ptr1; ptr2->pNext != NULL; ptr2 = ptr2->pNext)
		{
			if (ptr2->pNext->value == ptr1->value)
			{
				return true;
			}
		}
	}
	return false;
}

Node * LinkedList::get_index_at(unsigned int index)
{
	if (index > size())
	{
		return nullptr;
	}

	Node* ptr = pHead;
	for (size_t i = 0; i < index - 1; i++)
	{
		ptr = ptr->pNext;
	}

	return ptr;
}

unsigned int LinkedList::size()
{
	unsigned int size = 0;
	for (Node* ptr = pHead; ptr != nullptr; ptr = ptr->pNext)
	{
		size++;
	}
	return size;
}

void LinkedList::delete_all()
{
	for (Node* ptr = pHead; ptr != nullptr ; )
	{
		Node* temp = ptr;
		ptr = ptr->pNext;
		temp->pNext = nullptr;
	}
	pHead = nullptr;
	pTail = nullptr;
}
