// CrackCodeInterviewDll.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include "CrackCodeInterviewDll.h"
#include "LinkedList.h"

// 這是匯出變數的範例
CRACKCODEINTERVIEWDLL_API int nCrackCodeInterviewDll=0;

// 這是匯出函式的範例。
CRACKCODEINTERVIEWDLL_API int fnCrackCodeInterviewDll(void)
{
    return 42;
}

// 這是已匯出的類別建構函式。
// 請參閱 CrackCodeInterviewDll.h 中的類別定義
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
			beforeList.add_node_to_tail(ptr->value);
		}
		else
		{
			afterList.add_node_to_tail(ptr->value);
		}
	}
	list.delete_all();
	for (Node* bPtr = beforeList.pHead; bPtr != nullptr; bPtr = bPtr->pNext)
	{
		list.add_node_to_tail(bPtr->value);
	}
	for (Node* aPtr = afterList.pHead; aPtr != nullptr; aPtr = aPtr->pNext)
	{
		list.add_node_to_tail(aPtr->value);
	}
}

LinkedList& CCrackCodeInterviewDll::sum(LinkedList list1, LinkedList list2)
{
	int sum = 0, i = 0, j = 0;
	
	for (Node* ptr1 = list1.pHead; ptr1 != nullptr; i++, ptr1 = ptr1->pNext)
	{
		sum += ptr1->value * pow(10, i);
	}
	for (Node* ptr2 = list2.pHead; ptr2 != nullptr; j++, ptr2 = ptr2->pNext)
	{
		sum += ptr2->value * pow(10, j);
	}
	LinkedList resultList = LinkedList();
	for (int remain = sum; remain > 0; remain /= 10)
	{
		resultList.add_node_to_tail(remain % 10);
	}
	return resultList;
}

bool CCrackCodeInterviewDll::isPalindrome(LinkedList list)
{
	LinkedList reverseList = LinkedList();
	for (Node* ptr1 = list.pHead; ptr1 != nullptr; ptr1 = ptr1->pNext)
	{
		reverseList.add_node_to_head(ptr1->value);
	}
	for (Node* origPtr = list.pHead, *revPtr = reverseList.pHead;
		origPtr != nullptr && revPtr != nullptr;
		origPtr = origPtr->pNext, revPtr = revPtr->pNext)
	{
		if (origPtr->value != revPtr->value)
		{
			return false;
		}
	}
	return true;
}
