#include <iostream>
#include "common/Money.hpp"

int main() {
    std::cout << "===== Money class smoke test =====\n\n";

    //Constructor + factory
    Money a{1234};                              //tu cents
    Money b = Money::fromDollars(15.00);        //tu dollars
    Money c = Money::fromDollars(2.50);

    std::cout << "[1] Construction\n";
    std::cout << "  a = Money{1234} = " << a << " (expect $12.34)\n";
    std::cout << "  b = fromDollars(15.00) = " << b << " (expect $15.00)\n";
    std::cout << "  c = fromDollars(2.50)  = " << c << " (expect $2.50)\n\n";

    //Getter
    std::cout << "[2] Getters\n";
    std::cout << "  a.getCents()   = " << a.getCents()   << " (expect 1234)\n";
    std::cout << "  a.getDollars() = " << a.getDollars() << " (expect 12.34)\n\n";

    //Arithmetic
    std::cout << "[3] Arithmetic\n";
    Money sum  = b + c;
    Money diff = b - c;
    std::cout << "  b + c = " << sum  << " (expect $17.50)\n";
    std::cout << "  b - c = " << diff << " (expect $12.50)\n\n";

    //Compound assignment
    std::cout << "[4] Compound assignment\n";
    Money acc = Money::fromDollars(100.00);
    acc += b;
    std::cout << "  acc = $100; acc += $15  -> " << acc << " (expect $115.00)\n";
    acc -= c;
    std::cout << "  acc -= $2.50            -> " << acc << " (expect $112.50)\n\n";

    //Comparison
    std::cout << "[5] Comparison (1=true, 0=false)\n";
    std::cout << "  b == b : " << (b == b) << " (expect 1)\n";
    std::cout << "  b == c : " << (b == c) << " (expect 0)\n";
    std::cout << "  b != c : " << (b != c) << " (expect 1)\n";
    std::cout << "  b <  c : " << (b <  c) << " (expect 0)\n";
    std::cout << "  b >  c : " << (b >  c) << " (expect 1)\n";
    std::cout << "  b >= b : " << (b >= b) << " (expect 1)\n";
    std::cout << "  c <= b : " << (c <= b) << " (expect 1)\n\n";

    //Edge: rounding
    std::cout << "[6] Rounding edge case\n";
    Money tricky = Money::fromDollars(0.1 + 0.2);   //0.30000000000000004
    std::cout << "  fromDollars(0.1 + 0.2) = " << tricky
              << " cents=" << tricky.getCents()
              << " (expect $0.30, cents=30)\n";

    return 0;
}
