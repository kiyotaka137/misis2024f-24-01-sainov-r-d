#include <rational/rational.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[rational] - ctor") {
    CHECK(Rational() == Rational(0));
    CHECK(Rational() == Rational(0, 1));
    CHECK(Rational() == Rational(0, 5));
}
