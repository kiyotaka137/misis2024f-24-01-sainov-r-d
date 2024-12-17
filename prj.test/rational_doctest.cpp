#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "rational/rational.h"

TEST_CASE("[rational] - constructors and size") {
	CHECK(Rational() == Rational(0, 1));
	CHECK(Rational(0) == Rational(0, 20));
	CHECK(Rational(1) == Rational(1, 1));
	CHECK(Rational(128, 1024) == Rational(1, 8));
	CHECK(Rational(128,8) == Rational(16));
}

TEST_CASE("[rational] -arifmetic") {
	std::int32_t a = 2;
	CHECK(a + Rational(5, 2) == Rational(9, 2));
	CHECK((Rational(2, 4) += Rational(1, 2)) == Rational(1, 1));
	CHECK(Rational(3, 9) + Rational(4, 3) == Rational(5, 3));
	CHECK(Rational(3, 9) + Rational(-4, 3) == Rational(-1));
	CHECK(Rational(2, 6) / Rational(3, 4) == Rational(4, 9));
	CHECK(Rational(2, 6) / Rational(-3, 4) == Rational(-4, 9));
	CHECK(Rational(3, 2) - Rational(1, 2) == Rational(1, 1));
	CHECK(Rational(3, 2) - Rational(43, 7) == Rational(-65, 14));
	CHECK(Rational(5, -4) * Rational(2, 1) == Rational(-5, 2));
	CHECK(Rational(5, 4) * Rational(2, 3) == Rational(5, 6));
	CHECK(Rational(5, 4) * 2 == Rational(5, 2));
	CHECK(Rational(-1, 3) == -Rational(1, 3));
	CHECK(Rational(1, -3) == -Rational(1, 3));
}

TEST_CASE("[rational] : logic_base_operators") {
	CHECK(Rational(1) > Rational(999,1000));
	CHECK(Rational(1, 2) > Rational(1, 4));
	CHECK(Rational(1, 4) >= Rational(25, 100));
	CHECK(Rational(1, -3) < Rational(1, 3));
	CHECK(Rational(2, 16) < Rational(1, 3));
	CHECK(Rational(1, -3) <= Rational(1, 3));
	CHECK(Rational(1, 3) != Rational(3, 3));
	CHECK(Rational(3, 3) != Rational(2, 3));
	CHECK(Rational(-1, -3) == Rational(3, 9));
}
TEST_CASE("[rational] - dincrement") {
	CHECK(Rational(-1, 2) == -Rational(1, 2));
}
TEST_CASE("[rational] - operators") {
	Rational r(2, 3);

	CHECK(r + 1 == Rational(5, 3));
	CHECK(r - 1 == Rational(-1, 3));
	CHECK(r * 2 == Rational(4, 3));
	CHECK(r / 2 == Rational(1, 3));

	r += 1;
	CHECK(r == Rational(5, 3));

	r -= 2;
	CHECK(r == Rational(-1, 3));

	r *= 3;
	CHECK(r == Rational(-1, 1));

	r /= -2;
	CHECK(r == Rational(1, 2));
}