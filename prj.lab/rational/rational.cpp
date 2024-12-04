#include<rational/rational.h>
#include<stdexcept>
rational::rational(const int numinator, const int denominator) : num(numinator), denom(denominator) {
    if (denom == 0) {
        throw "Division by zero!";
    }
    simplify();
}
void rational::simplify()noexcept {}
bool rational::operator==(const rational& other)const noexcept { return true; }
bool rational::operator!=(const rational& other) const noexcept { return true; }
bool rational::operator<(const rational& other) const noexcept { return true; }
bool rational::operator<=(const rational& other) const noexcept { return true; }
bool rational::operator>(const rational& other) const noexcept { return true; }
bool rational::operator>=(const rational& other) const noexcept { return true; }
rational operator+(const rational& lhs, const rational& rhs) noexcept{ return rational{ lhs } += rhs; }
rational operator-(const rational& lhs, const rational& rhs) noexcept { return rational{ lhs } -= rhs; }
rational operator*(const rational& lhs, const rational& rhs) noexcept { return rational{ lhs } *= rhs; }
rational operator/(const rational& lhs, const rational& rhs) { return rational{ lhs } /= rhs; }
rational operator+(const rational& lhs, const int rhs) noexcept { return rational{ lhs } += rhs; }
rational operator-(const rational& lhs, const int rhs) noexcept { return rational{ lhs } -= rhs; }
rational operator*(const rational& lhs, const int rhs) noexcept { return rational{ lhs } *= rhs; }
rational operator/(const rational& lhs, const int rhs) { return rational{ lhs } /= rhs; }
rational operator+(const int lhs, const rational& rhs) noexcept { return operator+(lhs, rhs); }
rational operator-(const int lhs, const rational& rhs) noexcept { return operator-(lhs, rhs); }
rational operator*(const int lhs, const rational& rhs) noexcept { return operator*(lhs, rhs); }
rational operator/(const int lhs, const rational& rhs) { return operator/(lhs, rhs); }
rational& rational::operator+=(const rational& rhs) noexcept { return *this; };
rational& rational::operator-=(const rational& rhs) noexcept { return *this; };
rational& rational::operator*=(const rational& rhs) noexcept { return *this; };
rational& rational::operator/=(const rational& rhs) { return *this; };

rational& rational::operator+=(const int32_t rhs) noexcept { return operator+=(rational(rhs)); };
rational& rational::operator-=(const int32_t rhs) noexcept { return operator-=(rational(rhs)); };
rational& rational::operator*=(const int32_t rhs) noexcept { return operator*=(rational(rhs)); };
rational& rational::operator/=(const int32_t rhs) { return operator/=(rational(rhs)); };
std::ostream& operator<<(std::ostream& ostrm, const rational& rhs) noexcept { return ostrm; }

std::istream& operator>>(std::istream& istrm, rational& rhs) noexcept { return istrm; }