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
		LinkedList emptyList, list1, list2, list3, list4;

		Chap2()
		{
			// Prepare test data
			emptyList = LinkedList();

			list1 = LinkedList();
			list1.add_node_to_tail(10);
			list1.add_node_to_tail(20);
			list1.add_node_to_tail(30);
			list1.add_node_to_tail(20);

			list2 = LinkedList();
			list2.add_node_to_tail(100);
			list2.add_node_to_tail(20);
			list2.add_node_to_tail(30);
			list2.add_node_to_tail(50);

			list3 = LinkedList();
			list3.add_node_to_tail(1);
			list3.add_node_to_tail(1);
			list3.add_node_to_tail(1);

			list4 = LinkedList();
			list4.add_node_to_tail(1);
			list4.add_node_to_tail(5);
			list4.add_node_to_tail(3);
			list4.add_node_to_tail(2);
			list4.add_node_to_tail(4);			
		}

		CCrackCodeInterviewDll library;

		TEST_METHOD(Chap2_1)
		{
			library.removeDuplicate(emptyList);
			Assert::IsTrue(emptyList.is_empty());

			library.removeDuplicate(list1);
			Assert::IsFalse(list1.has_duplicate_element());

			library.removeDuplicate(list2);
			Assert::IsFalse(list2.has_duplicate_element());

			library.removeDuplicate(list3);
			Assert::IsFalse(list3.has_duplicate_element());
		}

		TEST_METHOD(Chap2_2)
		{
			Node* result1 = library.getKthLast(emptyList, 1);			
			Assert::IsNull(result1);

			Node* result2 = library.getKthLast(list1, 1);
			Assert::AreEqual(20, result2->value);
			result2 = library.getKthLast(list1, 2);
			Assert::AreEqual(30, result2->value);
			result2 = library.getKthLast(list1, 3);
			Assert::AreEqual(20, result2->value);
			result2 = library.getKthLast(list1, 4);
			Assert::AreEqual(10, result2->value);

			Node* result3 = library.getKthLast(list2, 1);
			Assert::AreEqual(50, result3->value);
			result3 = library.getKthLast(list2, 2);
			Assert::AreEqual(30, result3->value);
			result3 = library.getKthLast(list2, 3);
			Assert::AreEqual(20, result3->value);
			result3 = library.getKthLast(list2, 4);
			Assert::AreEqual(100, result3->value);

			Node* result4 = library.getKthLast(list3, 1);
			Assert::AreEqual(1, result4->value);
			result4 = library.getKthLast(list3, 2);
			Assert::AreEqual(1, result4->value);
			result4 = library.getKthLast(list3, 3);
			Assert::AreEqual(1, result4->value);
		}

		TEST_METHOD(Chap2_3)
		{
			library.deleteMiddle(list4, list4.get_index_at(3));
			Node* result = list4.get_index_at(3);
			Assert::AreEqual(2, result->value);
		}

		TEST_METHOD(Chap2_4)
		{
			library.partitionValue(list4, 4);
			Node* result1 = list4.get_index_at(1);
			Assert::AreEqual(1, result1->value);
			result1 = list4.get_index_at(2);
			Assert::AreEqual(3, result1->value);
			result1 = list4.get_index_at(3);
			Assert::AreEqual(2, result1->value);
			result1 = list4.get_index_at(4);
			Assert::AreEqual(5, result1->value);
			result1 = list4.get_index_at(5);
			Assert::AreEqual(4, result1->value);
		}

		TEST_METHOD(Chap2_5)
		{
			//111 + 42351 = 42462 => 2->6->4->2->4
			LinkedList resultList1 = library.sum(list4, list3);
			Node* result1 = resultList1.get_index_at(1);
			Assert::AreEqual(2, result1->value);
			result1 = resultList1.get_index_at(2);
			Assert::AreEqual(6, result1->value);
			result1 = resultList1.get_index_at(3);
			Assert::AreEqual(4, result1->value);
			result1 = resultList1.get_index_at(4);
			Assert::AreEqual(2, result1->value);
			result1 = resultList1.get_index_at(5);
			Assert::AreEqual(4, result1->value);
		}
	};
}