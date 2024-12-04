#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include<iostream>
#include<sstream>
int gcd(int a, int b) {
    //return b ? gcd(b, a % b) : a;
    if (b != 0) {
        return gcd(b, a % b);
    }
    else { return a; }
}
class rational {
public:
    rational(const int numinator, const int denominator) : num(numinator), denom(denominator) {
        if (denom == 0) {
            throw "Division by zero!";
        }
        simplify();
    }
    bool operator==(const rational& other)const noexcept { return(num = other.num) && (denom == other.denom); }
    bool operator!=(const rational& other) const noexcept{ return !operator==(other); }
    bool operator<(const rational& other) const noexcept { return num * other.denom < other.num * denom; }
    bool operator<=(const rational&) const noexcept{ return num * other.denom <= other.num * denom; }
    bool operator>(const rational&) const noexcept { return num * other.denom > other.num * denom; }
    bool operator>=(const rational&) const noexcept { return num * other.denom >= other.num * denom; }

    rational operator+(const rational& other) noexcept {
        int nod = gcd(num * other.denom + other.num * denom, other.denom * denom);
        return rational((num * other.denom + other.num * denom) / nod, (other.denom * denom) / nod);
    }
    rational operator*(const rational& other) noexcept {
        int nod = gcd(num * other.num, denom * other.denom);
        return rational((num * other.num) / nod, (denom * other.denom) / nod);
    }
    rational operator-(const rational& other) noexcept {
        int nod = gcd(num * other.denom - other.num * denom, other.denom * denom);
        return rational((num * other.denom - other.num * denom) / nod, (other.denom * denom) / nod);
    }
    rational operator/(const rational& other) {
        int nod = gcd(num * other.denom, denom * other.num);
        return rational((num * other.denom) / nod, (denom * other.num) / nod);
    }
    rational& operator+=(const rational& other) noexcept {
        num = num * other.denom + other.num * denom;
        denom *= other.denom;
        simplify();
        return *this;
    }
 
    rational& operator-=(const rational& other) noexcept{
        num = num * other.denom - other.num * denom;
        denom = other.denom * denom;
        simplify();
        return *this;
    }
    rational& operator*=(const rational& other) noexcept {
        num *= other.num;
        denom *= other.denom;
        simplify();
        return *this;
    }

    rational& operator/=(rational& const other) {
        num *= other.denom;
        denom *= other.denom;
        simplify();
        return *this;
    }
    std::ostream& writeTo(std::ostream& ostrm) const noexcept {
        ostrm << num << slash << denom;
    }
    std::istream& readFrom(std::istream& istrm) noexcept {
        istrm >> num >> denom;
        return istrm;
    }
    static const char slash{ '/' };
private:
    int num{ 0 };
    int denom{ 1 };
    void simplify() {
        int nod = gcd(num, denom);
        num /= nod;
        denom /= nod;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }
};
inline std::ostream& operator<<(std::ostream& ostrm, const rational& rhs) noexcept
{
    return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, rational& rhs) noexcept
{
    return rhs.readFrom(istrm);
}
#endif

