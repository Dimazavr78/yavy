#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
    explicit Rational(int num_ = 0, int den_ = 1) : num(num_), den(den_)
    {
        Make();
    }
    void Make();
    friend std::ostream& operator << (std::ostream&, Rational const&);
    friend std::istream& operator>> (std::istream&, Rational&);
    friend Rational const operator+ (Rational const&, Rational const&);
    friend Rational const operator- (Rational const&, Rational const&);
    friend Rational const operator* (Rational const&, Rational const&);
    friend Rational const operator/ (Rational const&, Rational const&);
    friend bool operator< (Rational const&, Rational const&);
    friend bool operator== (Rational const&, Rational const&);
    friend bool operator> (Rational const&, Rational const&);
    friend bool operator<= (Rational const&, Rational const&);
    friend bool operator>= (Rational const&, Rational const&);
    
private:
    int num, den;
};

#endif // RATIONAL_H