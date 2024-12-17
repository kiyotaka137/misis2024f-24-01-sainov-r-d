#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include<iostream>
#include<sstream>
#include<cstdint>
namespace simplification {
    std::int32_t gcd(std::int32_t a, std::int32_t b);
}
class Rational {
public:
    Rational();
    Rational(const std::int32_t numinator, const std::int32_t denominator);
    Rational(const std::int32_t numm) noexcept;
    Rational(const Rational&) = default;
    Rational& operator=(const Rational&) = default;
    ~Rational() = default;
    Rational operator-() const noexcept;
    std::int32_t num() const noexcept;
    std::int32_t den() const noexcept;
    bool operator==(const Rational& rhs)const noexcept;
    bool operator<(const Rational& rhs) const noexcept;


    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator/=(const Rational& rhs);
    Rational& operator+=(const std::int32_t rhs) noexcept;
    Rational& operator-=(const std::int32_t rhs) noexcept;
    Rational& operator*=(const std::int32_t rhs) noexcept;
    Rational& operator/=(const std::int32_t rhs);
    std::ostream& output(std::ostream& out);
    std::istream& input(std::istream& in);
private:
    std::int32_t num_{ 0 };
    std::int32_t denom_{ 1 };
    void simplify() ;
    static const char slash{ '/' };
};

bool operator<=(const Rational& lhs, const Rational& rhs) noexcept;
bool operator>(const Rational& lhs, const Rational& rhs)  noexcept;
bool operator>=(const Rational& lhs, const Rational& rhs) noexcept;
bool operator!=(const Rational& lhs, const Rational& rhs) noexcept;

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const std::int32_t rhs) noexcept;
Rational operator-(const Rational& lhs, const std::int32_t rhs) noexcept;
Rational operator*(const Rational& lhs, const std::int32_t rhs) noexcept;
Rational operator/(const Rational& lhs, const std::int32_t rhs);

Rational operator+(const std::int32_t lhs, const Rational& rhs) noexcept;
Rational operator-(const std::int32_t lhs, const Rational& rhs) noexcept;
Rational operator*(const std::int32_t lhs, const Rational& rhs) noexcept;
Rational operator/(const std::int32_t lhs, const Rational& rhs);
inline std::ostream& operator<<(std::ostream& out, Rational& rhs) { return rhs.output(out); }
inline std::istream& operator>>(std::istream& in, Rational& rhs)  { return rhs.input(in); }
#endif

