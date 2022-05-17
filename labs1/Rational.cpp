#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include "Rational.h"

void Rational::Make()
{
    if (!den)
        throw std::invalid_argument("denominator should not be zero");
    if (((num >> (sizeof(num) * 8 - 1)) ^ (den >> (sizeof(den) * 8 - 1))) & 1)
        num = -std::abs(num);
    else
        num = std::abs(num);
    den = std::abs(den);
}

std::ostream& operator <<(std::ostream& ost, Rational const& r)
{
    return ost << r.num << '/' << r.den;
}

std::istream& operator>>(std::istream& ist, Rational& r) 
{
    std::string s;
    std::getline(ist, s, ')');
    std::string::size_type ind;
    while ((ind = s.find_first_of("(,)")) != std::string::npos)
        s.replace(ind, 1, 1, ' ');
    std::istringstream iss(s);
    iss >> r.num >> r.den;
    r.Make();
    return ist;
}

Rational const operator+ (Rational const& lhs, Rational const& rhs)
{
    return Rational(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Rational const operator- (Rational const& lhs, Rational const& rhs)
{
    return lhs + Rational(-rhs.num, rhs.den);
}

Rational const operator* (Rational const& lhs, Rational const& rhs)
{
    return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

Rational const operator/ (Rational const& lhs, Rational const& rhs)
{
    return lhs * Rational(rhs.den, rhs.num);
}

bool operator< (Rational const& lhs, Rational const& rhs)
{
    return double(lhs.num) / lhs.den < double(rhs.num) / rhs.den;
}

bool operator== (Rational const& lhs, Rational const& rhs)
{
    return !(lhs < rhs || rhs < lhs);
}

bool operator> (Rational const& lhs, Rational const& rhs)
{
    return rhs < lhs;
}

bool operator<= (Rational const& lhs, Rational const& rhs)
{
    return !(rhs < lhs);
}

bool operator>= (Rational const& lhs, Rational const& rhs)
{
    return !(lhs < rhs);
}

