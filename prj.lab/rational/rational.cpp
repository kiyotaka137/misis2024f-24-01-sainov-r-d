#include<rational/rational.h>
#include<stdexcept>
#include<iostream>
#include<sstream>

int32_t simplification::gcd(int32_t a, int32_t b) {
    if (b != 0) {
        return gcd(b, a % b);
    }
    else { return a; }
}
void Rational::simplify() noexcept{
    int nod = simplification::gcd(num, denom);
    num /= nod;
    denom /= nod;
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
}
Rational::Rational() : num(0), denom(1) {}
Rational::Rational(const std::int32_t numm) noexcept : num(numm), denom(1) {}
Rational Rational::operator-() const noexcept{
    return Rational(-num, denom);
}
std::int32_t Rational::returnnum() const noexcept {
    return num;     
}
std::int32_t Rational::returnden() const noexcept {
    return denom;
}
Rational::Rational(const std::int32_t numinator, const std::int32_t denominator) : num(numinator), denom(denominator) {
    if (denom == 0) 
        throw std::invalid_argument("Division by zero!");
    
    simplify();
}
bool Rational::operator==(const Rational& rhs)const noexcept { return (num * rhs.denom == rhs.num * denom); }
bool Rational::operator<(const Rational& rhs) const noexcept { return (num * rhs.denom < rhs.num * denom); }
bool operator!=(const Rational& lhs, const Rational& rhs)  noexcept { return !(lhs == rhs); }
bool operator<=(const Rational& lhs, const Rational& rhs)  noexcept { return (lhs == rhs || lhs < rhs); }
bool operator>(const Rational& lhs, const Rational& rhs)  noexcept { return !(lhs == rhs) && !(lhs < rhs); }
bool operator>=(const Rational& lhs, const Rational& rhs)  noexcept { return (lhs > rhs) || (lhs == rhs); }
Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num = num * rhs.denom + rhs.num*denom;
    denom = denom * rhs.denom;
    simplify();
    return *this;
};
Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num = num * rhs.denom - rhs.num * denom;
    denom = denom * rhs.denom;
    simplify();
    return *this;
};
Rational& Rational::operator*=(const Rational& rhs) noexcept { 
    num = num * rhs.num;
    denom = denom * rhs.denom;
    simplify();
    return *this;
     };
Rational& Rational::operator/=(const Rational& rhs) { 
    num = num * rhs.denom;
    denom = denom * rhs.num;
    simplify();
    return *this;
};
Rational& Rational::operator+=(const int32_t rhs) noexcept { return operator+=(Rational(rhs)); };
Rational& Rational::operator-=(const int32_t rhs) noexcept { return operator-=(Rational(rhs)); };
Rational& Rational::operator*=(const int32_t rhs) noexcept { return operator*=(Rational(rhs)); };
Rational& Rational::operator/=(const int32_t rhs) { return operator/=(Rational(rhs)); }
std::istream& Rational::input(std::istream& in) {
    char sl = 0;
    long long np = 0, nq = 1;
    in.clear();
    in >> np >> sl >> nq;

    if (in.good() && nq != 0) {
        int32_t d = simplification::gcd(std::abs(np), std::abs(nq));
        np /= d;
        nq /= d;
        if (sl == slash) {
            if (np < 0 && nq < 0) {
                num = -np;
                denom = -nq;
            }
            else if (np < 0 && nq > 0 || np > 0 && nq < 0) {
                num = -std::abs(np);
                denom = std::abs(nq);
            }
            else {
                num = np;
                denom = nq;
            }
        }
        else
            in.setstate(std::ios_base::failbit);
    }
    else
        in.setstate(std::ios_base::failbit);
    return in;
}
std::ostream& Rational::output(std::ostream& out){
    out << num << slash << denom;
    return out;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept{ return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{ lhs } /= rhs; }
Rational operator+(const Rational& lhs, const int32_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int32_t rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const int32_t rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const int32_t rhs) { return Rational{ lhs } /= rhs; }
Rational operator+(const int32_t lhs, const Rational& rhs) noexcept { return operator+(lhs, rhs); }
Rational operator-(const int32_t lhs, const Rational& rhs) noexcept { return operator-(lhs, rhs); }
Rational operator*(const int32_t lhs, const Rational& rhs) noexcept { return operator*(lhs, rhs); }
Rational operator/(const int32_t lhs, const Rational& rhs) { return operator/(lhs, rhs); }




