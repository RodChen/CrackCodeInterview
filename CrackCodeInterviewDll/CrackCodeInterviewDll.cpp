// CrackCodeInterviewDll.cpp : �w�q DLL ���ε{�����ץX�禡�C
//

#include "stdafx.h"
#include "CrackCodeInterviewDll.h"
#include "LinkedList.h"

// �o�O�ץX�ܼƪ��d��
CRACKCODEINTERVIEWDLL_API int nCrackCodeInterviewDll=0;

// �o�O�ץX�禡���d�ҡC
CRACKCODEINTERVIEWDLL_API int fnCrackCodeInterviewDll(void)
{
    return 42;
}

// �o�O�w�ץX�����O�غc�禡�C
// �аѾ\ CrackCodeInterviewDll.h �������O�w�q
CCrackCodeInterviewDll::CCrackCodeInterviewDll()
{
    return;
}

//Chap1_1
bool CCrackCodeInterviewDll::hasUniqueChar(char * str, size_t size)
{
	bool result = true;

	// index is ASCII code of char
	bool hasChar[256] = { false };

	for (size_t i = 0; i < size; i++)
	{
		int index = (int)str[i];
		if (hasChar[index])
		{
			result = false;
			break;
		}
		else
		{
			hasChar[index] = true;
		}
	}
	return result;
}

//Chap1_2
void CCrackCodeInterviewDll::reverse(char* str)
{
	size_t length = strlen(str);
	char temp, *end_ptr;
	end_ptr = str + length - 1;

	//swap char
	while (end_ptr > str) {
		temp = *str;
		*str = *end_ptr;
		*end_ptr = temp;
		str++;
		end_ptr--;
	}
	return;
}

//Chap1_3
//Assume max str's length is 256
bool CCrackCodeInterviewDll::isPermutated(char * str, char * permutatedStr)
{
	size_t length = strlen(str);
	size_t permuLength = strlen(permutatedStr);
	if (permuLength > length || length > 256 || str == "")
	{
		return false;
	}

	// Check if each char in permutatedStr appears in str once
	bool isAppeared[256] = { false };
	for (size_t i = 0; i < permuLength; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (*(permutatedStr + i) == *(str + j) && !isAppeared[i])
			{
				isAppeared[i] = true;
				break;
			}
			if (j == length - 1)
			{
				return false;
			}
		}
	}
	return true;
}

//Chap2_1
void CCrackCodeInterviewDll::removeDuplicate(LinkedList list)
{
	if (list.is_empty())
	{
		return;
	}

	for (Node* ptr1 = list.pHead; ptr1->pNext != NULL; )
	{
		// remove every node after ptr1 having equal value as ptr1
		for (Node* ptr2 = ptr1; ptr2->pNext != NULL; )
		{
			if (ptr2->pNext->value == ptr1->value)
			{
				Node* temp = ptr2->pNext;
				ptr2->pNext = temp->pNext;
				temp->pNext = NULL;
			}
			else
			{
				ptr2 = ptr2->pNext;
			}
		}

		// if everything after ptr1 is removed, ptr1->pNext is NULL
		if (ptr1->pNext != NULL)
		{
			ptr1 = ptr1->pNext;
		}
		else
		{
			break;
		}
	}
}

Node * CCrackCodeInterviewDll::getKthLast(LinkedList list, unsigned int k)
{
	if (k == 0 || list.is_empty())
	{
		return nullptr;
	}
	Node* slowPtr = list.pHead, *fastPtr = list.pHead;
	
	// fastPtr goes through k - 1 nodes (becomes kth node) 
	for (size_t i = 0; i < k - 1; i++)
	{
		if (fastPtr->pNext == nullptr)
		{
			return nullptr;
		}
		else
		{
			fastPtr = fastPtr->pNext;
		}
	}

	// go to tail
	while (fastPtr->pNext != nullptr)
	{
		fastPtr = fastPtr->pNext;
		slowPtr = slowPtr->pNext;
	}

	return slowPtr;
}

void CCrackCodeInterviewDll::deleteMiddle(LinkedList list, Node * pMid)
{
	Node* ptr = pMid;
	while (ptr->pNext != nullptr)
	{
		ptr->value = ptr->pNext->value;
		ptr = ptr->pNext;
	}
	ptr = nullptr;
}

void CCrackCodeInterviewDll::partitionValue(LinkedList& list, int x)
{
	LinkedList beforeList = LinkedList();
	LinkedList afterList = LinkedList();

	for (Node* ptr = list.pHead; ptr != nullptr; ptr = ptr->pNext)
	{
		if (ptr->value < x)
		{
			beforeList.add_node(ptr->value);
		}
		else
		{
			afterList.add_node(ptr->value);
		}
	}
	list.delete_all();
	for (Node* bPtr = beforeList.pHead; bPtr != nullptr; bPtr = bPtr->pNext)
	{
		list.add_node(bPtr->value);
	}
	for (Node* aPtr = afterList.pHead; aPtr != nullptr; aPtr = aPtr->pNext)
	{
		list.add_node(aPtr->value);
	}
}
