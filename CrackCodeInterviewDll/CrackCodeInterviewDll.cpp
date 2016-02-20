// CrackCodeInterviewDll.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include "CrackCodeInterviewDll.h"


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
