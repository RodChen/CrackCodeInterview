// CrackCodeInterviewDll.cpp : �w�q DLL ���ε{�����ץX�禡�C
//

#include "stdafx.h"
#include "CrackCodeInterviewDll.h"


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
