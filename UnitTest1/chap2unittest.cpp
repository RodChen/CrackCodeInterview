#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CrackCodeInterviewDll\CrackCodeInterviewDll.h"
#include "..\CrackCodeInterviewDll\LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chap2UnitTest
{
	TEST_CLASS(Chap2)
	{
	public:
		CCrackCodeInterviewDll library;

		TEST_METHOD(Chap2_1)
		{
			LinkedList emptyList = LinkedList();
			library.removeDuplicate(emptyList);
			Assert::IsTrue(emptyList.is_empty());

			LinkedList list1 = LinkedList();
			list1.add_node(10);
			list1.add_node(20);
			list1.add_node(30);
			list1.add_node(20);
			library.removeDuplicate(list1);
			Assert::IsFalse(list1.has_duplicate_element());

			LinkedList list2 = LinkedList();
			list2.add_node(100);
			list2.add_node(20);
			list2.add_node(30);
			list2.add_node(50);
			library.removeDuplicate(list2);
			Assert::IsFalse(list2.has_duplicate_element());

			LinkedList list3 = LinkedList();
			list3.add_node(1);
			list3.add_node(1);
			list3.add_node(1);
			library.removeDuplicate(list3);
			Assert::IsFalse(list3.has_duplicate_element());
		}
	};
}