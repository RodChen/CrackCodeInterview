#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CrackCodeInterviewDll\CrackCodeInterviewDll.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chap1UnitTest
{		
	TEST_CLASS(Chap1)
	{
	public:
		CCrackCodeInterviewDll library;

		TEST_METHOD(Chap1_1)
		{
			char string1[] = "Absolute";
			Assert::IsTrue(library.hasUniqueChar(string1, strlen(string1)));

			char string2[] = "Screen";
			Assert::IsFalse(library.hasUniqueChar(string2, strlen(string2)));

			char string3[] = "";
			Assert::IsTrue(library.hasUniqueChar(string3, strlen(string3)));
		}
		
		TEST_METHOD(Chap1_2)
		{	
			char input1[] = { "freedom" };
			library.reverse(input1);
			Assert::AreEqual("modeerf", input1, "",  LINE_INFO());

			char input2[] = "";
			library.reverse(input2);
			Assert::AreEqual("", input2, "", LINE_INFO());

			char input3[] = "AB";
			library.reverse(input3);
			Assert::AreEqual("BA", input3, "", LINE_INFO());
		}

		TEST_METHOD(Chap1_3)
		{
			char string1[] = "Absolute";
			char permutatedStr1[] = "bsAluteo";
			Assert::IsTrue(library.isPermutated(string1, permutatedStr1));

			char string2[] = "Screen";
			char permutatedStr2[] = "crS";
			Assert::IsTrue(library.isPermutated(string2, permutatedStr2));

			char string3[] = "Screen";
			char permutatedStr3[] = "crSNee";
			Assert::IsFalse(library.isPermutated(string3, permutatedStr3));

			char string4[] = "Ab";
			char permutatedStr4[] = "";
			Assert::IsTrue(library.isPermutated(string4, permutatedStr4));

			char string5[] = "";
			char permutatedStr5[] = "";
			Assert::IsTrue(library.isPermutated(string5, permutatedStr5));

			char string6[] = "";
			char permutatedStr6[] = "Ab";
			Assert::IsFalse(library.isPermutated(string6, permutatedStr6));
		}
	};
}