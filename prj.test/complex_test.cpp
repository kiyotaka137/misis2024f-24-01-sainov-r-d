// 2024 by Polevoi Dmitry under Unlicense
#include <complex/complex.h>

#include <iostream>

int main() {
	Complex c;
	std::cout << "re=" << c.re << " im=" << c.im << std::endl;
	Complex a{ 1.0,1.0 };
	c += a;
	std::cout << c;
	std::cout << c - Complex(0.0, 8.0);
}