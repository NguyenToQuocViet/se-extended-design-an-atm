#include "bank/Customer.hpp"

//constructor
Customer::Customer(const std::string& name, const std::string& pin, const Card& card, Account* account)
    : name_(name), pin_(pin), card_(card), account_(account) {}

//getters
std::string Customer::getName() const {
    return name_;
}

Card Customer::getCard() const {
    return card_;
}

Account* Customer::getAccount() const {
    return account_;
}

bool Customer::checkPin(const std::string& pin) const {
    return pin_ == pin;
}
