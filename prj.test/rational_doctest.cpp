#include <rational/rational.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[rational] - ctor") {
    CHECK(Rational() == Rational(0));
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational() == Rational(0, -9));
    CHECK(Rational(5) == Rational(5, 1));
    CHECK(Rational(-5, -10) == Rational(1, 2));
    CHECK(Rational(6, -9) == Rational(-2, 3));
    CHECK(Rational(0, 10) == Rational(0));
}

TEST_CASE("[rational] - num and den") {
    Rational r(4, 6);
    CHECK(r.num() == 2);
    CHECK(r.den() == 3);

    r = Rational(-4, 6);
    CHECK(r.num() == -2);
    CHECK(r.den() == 3);

    r = Rational(4, -6);
    CHECK(r.num() == -2);
    CHECK(r.den() == 3);

    r = Rational(0, 5);
    CHECK(r.num() == 0);
    CHECK(r.den() == 1);
}

TEST_CASE("[rational] - arithmetic operations") {
    Rational a(1, 2);
    Rational b(1, 3);

    CHECK(a + b == Rational(5, 6));
    CHECK(a - b == Rational(1, 6));
    CHECK(a * b == Rational(1, 6));
    CHECK(a / b == Rational(3, 2));

    a += b;
    CHECK(a == Rational(5, 6));

    a -= Rational(1, 6);
    CHECK(a == Rational(2, 3));

    a *= Rational(3, 2);
    CHECK(a == Rational(1, 1));

    a /= Rational(5, 2);
    CHECK(a == Rational(2, 5));
}

TEST_CASE("[rational] - comparison operators") {
    Rational a(1, 2);
    Rational b(1, 3);
    Rational c(2, 4);

    CHECK(a == c);
    CHECK(a != b);
    CHECK(b < a);
    CHECK(a > b);
    CHECK(a >= c);
    CHECK(b <= a);
}

TEST_CASE("[rational] - operations with integers") {
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

TEST_CASE("[rational] - edge cases") {
    CHECK_THROWS_AS(Rational(1, 0), std::invalid_argument);
    CHECK_NOTHROW(Rational(0, 1));
    CHECK(Rational(0, -5) == Rational(0, 1));

    Rational r(-6, -8);
    CHECK(r == Rational(3, 4));
    r = Rational(6, -8);
    CHECK(r == Rational(-3, 4));
}

TEST_CASE("[rational] - chaining operations") {
    Rational r(1, 2);
    r += Rational(1, 3) -= Rational(1, 6);
    CHECK(r == Rational(2, 3));
}

TEST_CASE("[rational] - associativity and commutativity") {
    Rational a(1, 2);
    Rational b(1, 3);

    CHECK((a + b) == (b + a));
    CHECK((a * b) == (b * a));
    CHECK((a + (b + Rational(1, 6))) == ((a + b) + Rational(1, 6)));
    CHECK((a * (b * Rational(2, 3))) == ((a * b) * Rational(2, 3)));
}

