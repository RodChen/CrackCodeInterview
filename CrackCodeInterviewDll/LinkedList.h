#pragma once
#ifdef CRACKCODEINTERVIEWDLL_EXPORTS
#define CRACKCODEINTERVIEWDLL_API __declspec(dllexport)
#else
#define CRACKCODEINTERVIEWDLL_API __declspec(dllimport)
#endif
#include "Node.h"

/* definition of the linked list class */
class CRACKCODEINTERVIEWDLL_API LinkedList
{
public:
	/* Constructors with No Arguments */
	LinkedList(void);
	/* Constructors with a given value of a list node */
	LinkedList(int val);
	/* Destructor */
	~LinkedList(void);

	/* pointer of head node */
	Node *pHead;
	/* pointer of tail node */
	Node *pTail;

	/* Traversing the list and printing the value of each node */
	void traverse_and_print();

	void add_node(int data);

	void add_node2(int data);

	bool is_empty();

	bool has_duplicate_element();

	Node* get_index_at(unsigned int index);

	unsigned int size();
};
