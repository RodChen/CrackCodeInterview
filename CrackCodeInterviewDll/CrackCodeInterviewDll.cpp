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

	for (Node* ptr1 = list.pHead; ptr1->pNext != NULL; ptr1 = ptr1->pNext)
	{
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
	}
}
