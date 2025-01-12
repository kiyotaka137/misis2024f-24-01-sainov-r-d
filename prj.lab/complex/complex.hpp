#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iosfwd>
struct Complex {
	double re{ 0.0 };
	double im{ 0.0 };
	bool normal = false;
	Complex() = default;
	explicit Complex(const double real) : re(real) { }
	Complex(const Complex&) = default;
	~Complex() = default;
	Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

	Complex& operator=(const Complex&) = default;
	Complex& operator=(Complex&&) = default;
	Complex operator-() const noexcept;

    bool operator==(const Complex& rhs) const noexcept;
	bool operator!=(const Complex& rhs) const noexcept;

	Complex& operator+=(const Complex& rhs) noexcept;
	Complex& operator+=(const double rhs) noexcept;
	Complex& operator-=(const Complex& rhs) noexcept;
	Complex& operator-=(const double rhs) noexcept;
	Complex& operator*=(const Complex& rhs) noexcept;
	Complex& operator*=(const double rhs) noexcept;

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);

	std::ostream& write(std::ostream& ostrm) const;

	std::istream& read(std::istream& istrm);

	static const char leftBrace{ '{' };   
	static const char separator{ ',' };   
	static const char rightBrace{ '}' };  
};


Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator+(const Complex& lhs, const double rhs) noexcept;
Complex operator+(const double lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const double rhs) noexcept;
Complex operator-(const double lhs, const Complex& rhs) noexcept;

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator*(const Complex& lhs, const double rhs) noexcept;
Complex operator*(const double lhs, const Complex& rhs) noexcept;
Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const double rhs);

Complex operator/(const double lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);
#endif