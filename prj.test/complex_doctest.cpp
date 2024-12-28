#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "complex/complex.hpp"

TEST_CASE("[complex] - complex unit tests") {
	CHECK(Complex() == Complex(0.0, 0.0));
	CHECK(Complex(3.0) == Complex(2.0, 0.0) + Complex(1.0, 0.0));
	CHECK(Complex(2.0) == Complex(2.0, 0.0));
	CHECK(Complex(1, 0) + Complex(2, 4) == Complex(3, 4));
	CHECK(Complex(2, 3) * Complex(5, -7) == Complex(31, 1));
	CHECK(Complex(4, 1) / Complex(3, -4) == Complex(0.32, 0.76));
	CHECK(Complex(75, -50) / (3 + Complex(0, 4)) == Complex(1, -18));
	CHECK(Complex(12, 3) + 12 == Complex(24, 3));
	CHECK(-Complex(12, 3) == Complex(-12, -3));
	CHECK(Complex(11, 3) != Complex(-12, 3));
	CHECK(Complex(11, 0) + 2 == Complex(13, 0));
	CHECK(Complex(1) + Complex(2) == Complex(3));
	CHECK(Complex(3) - Complex(1) == Complex(2));
	CHECK(Complex(3) + 2.0 == Complex(5));
	Complex b;
	Complex c{ 1.0,1.0 };
	b = c;
	c += b;
	CHECK(b == Complex{ 1.0,1.0 });
	CHECK(c == Complex(2.0, 2.0));
	CHECK(b != c);
}
TEST_CASE("[complex] - test -=") {
	Complex com1{ 1.0,1.0 };
	Complex com2{ 1.0,1.0 };
	com1 -= com2;
	CHECK(com1 == Complex{ 0.0,0.0 });
	double p = -1.0;
	com1 -= p;
	CHECK(com1 == Complex{1.0,0.0});
	CHECK(com1 != Complex{ 1.0,1.0 });
	com1  = p + com1;
}
TEST_CASE("[complex] - test +=") {

}
TEST_CASE("[complex] - test *=") {

}
TEST_CASE("[complex] - test /=") {

}

