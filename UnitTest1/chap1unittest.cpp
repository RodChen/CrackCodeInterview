#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CrackCodeInterviewDll\CrackCodeInterviewDll.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chap1UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Chap1_2)
		{
			// TODO: �z�����յ{���X�b�o��		
			char input1[] = { "freedom" };
			CCrackCodeInterviewDll chap1_2;
			chap1_2.reverse(input1);
			Assert::AreEqual("modeerf", input1, "",  LINE_INFO());
		}

	};
}