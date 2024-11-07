#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../LR8.1 Char/LR8.1char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char t[] = "i love chocolate";

			int result1 = CountLet(t, 'c');
			int result2 = CountLet(t, 'o');
			int result3 = CountLet(t, 'p');

			int expected1 = 2;
			int expected2 = 3;
			int expected3 = 0;
			Assert::AreEqual(result1, expected1);
			Assert::AreEqual(result2, expected2);
			Assert::AreEqual(result3, expected3);

		}
		TEST_METHOD(TestMethod2)
		{
			char t[] = "while123while";

			char* result = Change(t);
			char expected[] = "**123**";
			Assert::AreEqual(result, expected);
		}
	};
}
