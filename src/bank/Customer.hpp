#pragma once
#include <string>
#include "bank/Card.hpp"
#include "bank/Account.hpp"

class Customer {
private:
    std::string name_;
    std::string pin_;
    Card card_;
    Account* account_;
public:
    //constructor
    Customer(const std::string& name, const std::string& pin, const Card& card, Account* account);
    
    //getters
    std::string getName() const;
    Card getCard() const;
    Account* getAccount() const;
    
    bool checkPin(const std::string& pin) const;
};
