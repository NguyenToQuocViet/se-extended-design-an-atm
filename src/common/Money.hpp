#pragma once
#include <cstdint>
#include <iosfwd>

class Money {
private:
    std::int64_t cents_;
public:
    //constructor
    Money(std::int64_t cents);
    //factory
    static Money fromDollars(double d);
    
    //getter
    std::int64_t getCents() const;
    double getDollars() const;
    
    //operator overide (member)
    Money& operator+=(const Money& rhs);
    Money& operator-=(const Money& rhs);

    bool operator==(const Money& rhs) const;
    bool operator!=(const Money& rhs) const;
    bool operator< (const Money& rhs) const;
    bool operator<=(const Money& rhs) const;
    bool operator> (const Money& rhs) const;
    bool operator>=(const Money& rhs) const;
};

//operator overide (free)
Money operator+(const Money& a, const Money& b);
Money operator-(const Money& a, const Money& b);
std::ostream& operator<<(std::ostream& os, const Money& m);
