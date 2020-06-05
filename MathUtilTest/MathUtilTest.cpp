#include "CppUnitTest.h"

#include "../RayTraceChallenge/MathUtil/Tuple.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathUtilTest
{
	TEST_CLASS(MathUtilTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Tuple v1(1, 2, 3, 4), v2(-1, -2, -3, -4);
			auto sum = v1 + v2;
			Assert::AreEqual(sum.x, 0.0);
			Assert::AreEqual(sum.y, 0.0);
			Assert::AreEqual(sum.z, 0.0);
			Assert::AreEqual(sum.w, 0.0);
		}
	};
}
