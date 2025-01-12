#include "complex.hpp"
#include<stdexcept>
#include <cmath>
#include<iostream>
Complex Complex::operator-() const noexcept { 
	return Complex(-re, -im); 
}

bool Complex::operator==(const Complex& rhs) const noexcept { 
	return abs(re - rhs.re) < 2 * std::numeric_limits<double>::epsilon() && abs(im - rhs.im) < 2 * std::numeric_limits<double>::epsilon(); 
}

bool Complex::operator!=(const Complex& rhs) const noexcept {
	return(!operator==(rhs)); 
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
	im += rhs.im;
	re += rhs.re;
	return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept { 
	return operator+=(Complex(rhs)); 
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
	im -= rhs.im;
	re -= rhs.re;
	return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept { 
	return operator-=(Complex(rhs)); 
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double newre = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	re = newre;
	return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept { 
	return operator*=(Complex(rhs)); 
}

Complex& Complex::operator/=(const Complex& rhs)  {
	double denom = rhs.re * rhs.re + rhs.im * rhs.im;
	if (denom == 0)throw(std::exception("division by zero!"));
	return Complex((re * rhs.re + im * rhs.im) / denom, (im * rhs.re - re * rhs.im) / denom);
}

Complex& Complex::operator/=(const double rhs) { 
	return operator/=(Complex(rhs)); 
}
//сложение

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { 
	return Complex(lhs) += rhs;
}
Complex operator+(const Complex& lhs, const double rhs) noexcept { 
	return Complex(lhs) +=rhs; 
}
Complex operator+(const double lhs, const Complex& rhs) noexcept { 
	return Complex(lhs) += rhs; 
}

//вычитание

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { 
	return Complex(lhs) -= rhs; 
}
Complex operator-(const Complex& lhs, const double rhs) noexcept { 
	return Complex(lhs) -= rhs; 
}
Complex operator-(const double lhs, const Complex& rhs) noexcept { 
	return Complex(lhs) -= rhs; 
}

//умножение

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { 
	return Complex(lhs) *= rhs; 
}

Complex operator*(const Complex& lhs, const double rhs) noexcept { 
	return Complex(lhs) *= rhs;
}

Complex operator*(const double lhs, const Complex& rhs) noexcept { 
	return Complex(lhs) *= rhs; 
}

//деление
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
	char leftbrace;
	char rightbrace;
	char c;
	double imaginary = 0.0;
	double real = 0.0;
	is >> leftbrace >> re >> c >> im >> rightbrace;
	if (is.good()) {
		if (Complex::leftBrace == leftbrace && Complex::separator == c && Complex::rightBrace == rightbrace) {
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
