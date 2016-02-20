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

//Chap1_2
void CCrackCodeInterviewDll::reverse(char* str)
{
	// if input is null, return
	size_t length = strlen(str);

	//reverse the input string
	char temp, *end_ptr;
	end_ptr = str + length - 1;

	while (end_ptr > str) {
		temp = *str;
		*str = *end_ptr;
		*end_ptr = temp;
		str++;
		end_ptr--;
	}

	return;
}
