// CrackCodeInterview.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "..\CrackCodeInterviewDll\CrackCodeInterviewDll.h"
#include "..\CrackCodeInterviewDll\LinkedList.h"

CCrackCodeInterviewDll library;

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
	LinkedList emptyList = LinkedList();
	emptyList.traverse_and_print();

	LinkedList list1 = LinkedList();
	list1.add_node2(10);
	list1.add_node2(20);
	list1.add_node2(30);
	list1.add_node2(20);
	list1.traverse_and_print();
	library.removeDuplicate(list1);
	list1.traverse_and_print();

	//char input1[] = { "freedom" };
	//reverse(input1);

	//int* a = new int(1);
	//int b = 0;
	//a = &b;

    return 0;
}
