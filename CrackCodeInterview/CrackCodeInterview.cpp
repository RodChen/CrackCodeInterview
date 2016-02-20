// CrackCodeInterview.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

void reverse(char* str)
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

int main()
{
	char input1[] = { "freedom" };
	reverse(input1);

	int* a = new int(1);
	int b = 0;
	a = &b;

    return 0;
}
