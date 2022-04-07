#include "pch.h"
#include "CppUnitTest.h"
#include "../lsb3_1/lsb3_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		TEST_METHOD(AverageGrade_ReturnsCorrectValue) {
			//Arrange
			Student s;
			s.lname = "Petrenko";
			s.course = 2;
			s.physics = 3;
			s.math = 4;
			s.cs = 5;
			s.spec = (Spec)0;
			double expected = 4;

			//Act
			double actual = AverageGrade(s);

			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
