#include "CppUnitTest.h"

#include "../RayTraceChallenge/MathUtil/Tuple.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathUtilTest
{
	TEST_CLASS(MathUtilTest)
	{
	public:
		
		TEST_METHOD(TestBasicVectorOperations)
		{
			Tuple v1(1, 2, 3, 4), v2(-1, -2, -3, -4), v3(1, 1, 1, 1);
			auto sum1 = v1 + v2;
			Assert::IsTrue(isZero(sum1));

			auto sum2 = v1 + v3;
			Assert::IsTrue(areEqual(sum2, Tuple(2, 3, 4, 5)));

			auto diff = v1 - v1;
			Assert::IsTrue(isZero(diff));

			const auto v4 = Tuple{ 3, 4, 5 , 0 };
			Assert::IsTrue(areEqual(v4.magnitude(), sqrt(50)));

			const double one = v1.normalize().magnitude();
			Assert::IsTrue(fabs(one - 1.0) < EPSILON);
		}

		TEST_METHOD(TestTupleCreation)
		{
			const auto point = Tuple::point(1, 2, 3);
			Assert::AreEqual(1.0, point.w);

			const auto vector = Tuple::vector(1, 2, 3);
			Assert::AreEqual(0.0, vector.w);
		}

		TEST_METHOD(TestDotAndCrossProduct)
		{
			const auto t1 = Tuple(1, 2, 3, 4);
			const auto t2 = Tuple(-1, 1, 0, 2);
			const auto dotProd = dot(t1, t2);
			Assert::AreEqual(9.0, dotProd);

			const auto v1 = Tuple::vector(1, 2, 3);
			const auto v2 = Tuple::vector(2, 3, 4);
			const auto v1_cross_v2 = cross(v1, v2);
			const auto expected = Tuple::vector(-1, 2, -1);
			Assert::IsTrue(areEqual(expected, v1_cross_v2));
		}
	};
}
