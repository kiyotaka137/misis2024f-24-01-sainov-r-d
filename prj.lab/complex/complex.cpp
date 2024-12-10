#include<complex/complex.h>
#include<stdexcept>
#include <cmath>
#include<iostream>
Complex Complex::operator-() const noexcept { return Complex(-re, -im); }
bool Complex::operator==(const Complex& rhs) const noexcept { return abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon() && abs(im - rhs.im) < 2 * std::numeric_limits<double>::epsilon(); }
bool Complex::operator!=(const Complex& rhs) const noexcept { return(!operator==(rhs)); }
Complex& Complex::operator+=(const Complex& rhs) noexcept {
	im += rhs.im;
	re += rhs.re;
	return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }
Complex& Complex::operator-=(const Complex& rhs) noexcept {
	im -= rhs.im;
	re -= rhs.re;
	return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }
Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double newre = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	re = newre;
	return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept { return operator*=(Complex(rhs)); }
Complex& Complex::operator/=(const Complex& rhs)  {
	double denom = rhs.re * rhs.re + rhs.im * rhs.im;
	if (denom == 0)throw(std::exception("division by zero!"));
	return Complex((re * rhs.re + im * rhs.im) / denom, (im * rhs.re - re * rhs.im) / denom);
}
Complex& Complex::operator/=(const double rhs) { return operator/=(Complex(rhs)); }
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
std::istream& operator>>(std::istream& is, Complex& rhs) {
	return rhs.read(is);
}
std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
	return rhs.write(os);
}
std::ostream& Complex::write(std::ostream& os) const {
	os << leftBrace << re << separator << im << rightBrace;
	return os;
}
std::istream& Complex::read(std::istream& is) {
	char lbrace;
	double real;
	char c;
	double imaginary;
	char rbrace;
	is >> lbrace >> re >> c >> im >> rbrace;
	if (is.good()) {
		if (Complex::leftBrace == lbrace && Complex::separator == c && Complex::rightBrace == rbrace) {
			re = real;
			im = imaginary;
			normal = true;
		}
		else {
			is.setstate(std::ios_base::failbit);
		}
	}
	return is;
}
