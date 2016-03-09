#pragma once

/* definition of the list node class */
class Node
{
	friend class LinkedList;

public:
	/* Constructors with No Arguments */
	Node(void)
		: pNext(NULL)
	{ }

	/* Constructors with a given value */
	Node(int val)
		: value(val), pNext(NULL)
	{ }

	/* Constructors with a given value and a link of the next node */
	Node(int val, Node* next)
		: value(val), pNext(next)
	{}

	int value; /* data, can be any data type, but use integer for easiness */
	Node *pNext; /* pointer to the next node */

};
