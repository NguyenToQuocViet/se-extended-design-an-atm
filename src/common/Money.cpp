#include "common/Money.hpp"
#include <ostream>
#include <iomanip>
#include <cmath>

//Constructor
Money::Money(std::int64_t cents) : cents_(cents) {}

//Factory
Money Money::fromDollars(double d) {
    return Money{std::llround(d * 100)};
}

//Getters
std::int64_t Money::getCents() const {
    return cents_;
}

double Money::getDollars() const {
    return static_cast<double>(cents_) / 100.0;
}

//Operator Overide (member)
Money& Money::operator+=(const Money& rhs) {
    cents_ += rhs.cents_;
    return *this;
}

Money& Money::operator-=(const Money& rhs) {
    cents_ -= rhs.cents_;
    return *this;
}

bool Money::operator==(const Money& rhs) const {
    return (cents_ == rhs.cents_);
}

bool Money::operator!=(const Money& rhs) const {
    return (cents_ != rhs.cents_);
}

bool Money::operator< (const Money& rhs) const { 
    return (cents_ < rhs.cents_);
}

bool Money::operator<=(const Money& rhs) const {
    return (cents_ <= rhs.cents_);
}

bool Money::operator> (const Money& rhs) const {
    return (cents_ > rhs.cents_);
}

bool Money::operator>=(const Money& rhs) const {
    return (cents_ >= rhs.cents_);
}

//Operator Overide (free)
Money operator+(const Money& a, const Money& b) {
    Money result = a;
    result += b;
    return result;
}

Money operator-(const Money& a, const Money& b) {
    Money result = a;
    result -= b;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Money& m) {
    os << '$'
       << std::fixed
       << std::setprecision(2)
       << m.getDollars();
    return os;
}
