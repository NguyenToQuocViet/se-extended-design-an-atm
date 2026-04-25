#include "bank/Bank.hpp"

void Bank::addCustomer(Customer* customer) {
    customers_.push_back(customer);
}

Customer* Bank::authenticate(const std::string& cardNumber, const std::string& pin) {
    for (Customer* c : customers_) {
        if (c->getCard().getCardNumber() == cardNumber && c->checkPin(pin)) {
            return c;
        }
    }
    return nullptr;
}

Customer* Bank::findByCard(const std::string& cardNumber) {
    for (Customer* c : customers_) {
        if (c->getCard().getCardNumber() == cardNumber) {
            return c;
        }
    }
    return nullptr;
}
