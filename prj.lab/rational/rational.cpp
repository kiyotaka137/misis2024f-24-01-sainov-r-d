#include<rational/rational.h>
#include<stdexcept>
#include<iostream>
#include<sstream>

std::int32_t simplification::gcd(std::int32_t a, std::int32_t b) {
    if (b != 0) {
        return gcd(b, a % b);
    }
    else { return a; }
}
void Rational::simplify(){
    if (denom_ == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    if (num_ == 0) {
        denom_ = 1;
        return;
    }
    int nod = simplification::gcd(num_, denom_);
    num_ /= nod;
    denom_ /= nod;
    if (denom_ < 0) {
        num_ = -num_;
        denom_ = -denom_;
    }
}
Rational::Rational() : num_(0), denom_(1) {}
Rational::Rational(const std::int32_t numm) noexcept : num_(numm), denom_(1) {}
Rational Rational::operator-() const noexcept{
    return Rational(-num_, denom_);
}
std::int32_t Rational::num() const noexcept {
    return num_;     
}
std::int32_t Rational::den() const noexcept {
    return denom_;
}
Rational::Rational(const std::int32_t numinator, const std::int32_t denominator) : num_(numinator), denom_(denominator) {
    if (denom_ == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    simplify();
}
bool Rational::operator==(const Rational& rhs)const noexcept { 
    return (num_ * rhs.denom_ == rhs.num_ * denom_); 
}

bool Rational::operator<(const Rational& rhs) const noexcept { 
    return (num_ * rhs.denom_ < rhs.num_ * denom_); 
}

bool operator!=(const Rational& lhs, const Rational& rhs)  noexcept {
    return !(lhs == rhs); 
}

bool operator<=(const Rational& lhs, const Rational& rhs)  noexcept { 
    return (lhs == rhs || lhs < rhs); 
}

bool operator>(const Rational& lhs, const Rational& rhs)  noexcept { 
    return !(lhs == rhs) && !(lhs < rhs); 
}

bool operator>=(const Rational& lhs, const Rational& rhs)  noexcept { 
    return (lhs > rhs) || (lhs == rhs); 
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.denom_ + rhs.num_*denom_;
    denom_ = denom_ * rhs.denom_;
    simplify();
    return *this;
};

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.denom_ - rhs.num_ * denom_;
    denom_ = denom_ * rhs.denom_;
    simplify();
    return *this;
};

Rational& Rational::operator*=(const Rational& rhs) noexcept { 
    num_ = num_ * rhs.num_;
    denom_ = denom_ * rhs.denom_;
    simplify();
    return *this;
};

Rational& Rational::operator/=(const Rational& rhs) { 
    if (rhs.num_ == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    num_ = num_ * rhs.denom_;
    denom_ = denom_ * rhs.num_;
    simplify();
    return *this;
};

Rational& Rational::operator+=(const std::int32_t rhs) noexcept { 
    num_ += rhs * denom_;
    simplify();
    return *this;
};

Rational& Rational::operator-=(const std::int32_t rhs) noexcept { 
    num_ -= rhs * denom_;
    simplify();
    return *this;
};

Rational& Rational::operator*=(const std::int32_t rhs) noexcept {
    num_ *= rhs;
    simplify();
    return *this;
}

Rational& Rational::operator/=(const std::int32_t rhs) { 
    Rational a(1, rhs);
    *this *= a;
    simplify();
    return *this;
}

std::istream& Rational::input(std::istream& in) {
    char sl;
    std::int32_t np = 0, nq = 1;
    in.clear();
    in >> np >> sl >> nq;

    if (in.good() && nq != 0) {
        int32_t d = simplification::gcd(std::abs(np), std::abs(nq));
        np /= d;
        nq /= d;
        if (sl == slash) {
            if (np < 0 && nq < 0) {
                num_ = -np;
                denom_ = -nq;
            }else if (np < 0 && nq > 0 || np > 0 && nq < 0) {
                num_ = -std::abs(np);
                denom_ = std::abs(nq);
            }else {
                num_ = np;
                denom_ = nq;
            }
        }else
            in.setstate(std::ios_base::failbit);
    }else
        in.setstate(std::ios_base::failbit);
    return in;
}
std::ostream& Rational::output(std::ostream& out){
    out << num_ << slash << denom_;
    return out;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept{ 
    Rational temp(lhs);
    temp += rhs;
    return temp;
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    Rational temp(lhs);
    temp -= rhs;
    return temp;
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
    Rational temp(lhs);
    temp *= rhs;
    return temp;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational temp(lhs);
    temp /= rhs;
    return temp;
}

Rational operator+(const Rational& lhs, const std::int32_t rhs) noexcept {
    Rational temp(lhs);
    temp += rhs;
    return temp;
}

Rational operator-(const Rational& lhs, const std::int32_t rhs) noexcept {
    Rational temp(lhs);
    temp -= rhs;
    return temp;
}
Rational operator*(const Rational& lhs, const std::int32_t rhs) noexcept {
    Rational temp(lhs);
    temp *= rhs;
    return temp;
}

Rational operator/(const Rational& lhs, const std::int32_t rhs) {
    Rational temp(lhs);
    temp /= rhs;
    return temp;
}

Rational operator+(const std::int32_t lhs, const Rational& rhs) noexcept {
    Rational temp(lhs);
    temp += rhs;
    return temp;
}

Rational operator-(const std::int32_t lhs, const Rational& rhs) noexcept {
    Rational temp(lhs);
    temp -= rhs;
    return temp;
}

Rational operator*(const std::int32_t lhs, const Rational& rhs) noexcept {
    Rational temp(lhs);
    temp *= rhs;
    return temp;
}

Rational operator/(const std::int32_t lhs, const Rational& rhs) {
    Rational temp(lhs);
    temp /= rhs;
    return temp;
}




