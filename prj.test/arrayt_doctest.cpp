#include <arrayt/arrayt.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[arrayt] - ctor") {
	CHECK(ArrayT<double>().Size() == 0);
}