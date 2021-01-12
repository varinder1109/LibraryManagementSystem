#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "Header.h"
#include "Header.cpp"
#include "Book.h"
#include "Book.cpp"
#include "Student.h"
#include "Student.cpp"  
#include "FinalProject.cpp"

namespace FinalProjectUnitTest
{
	TEST_CLASS(FinalProjectUnitTest)
	{
	public:
		TEST_METHOD(TestToCheckIfIssuedBooksAreAvailable)
		{
			Assert::AreEqual(0, viewIssuedBooks(0, 1));
		}
		TEST_METHOD(TestToCheckIfBookWithNumberIsAlreadyAvailable)
		{
			Assert::AreEqual(1, checkBook(123));
		}
	};
}
