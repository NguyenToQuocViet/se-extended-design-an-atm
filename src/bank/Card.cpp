#include "bank/Card.hpp"

//constructor
Card::Card(const std::string& cardNumber, const std::string& expiryDate) : cardNumber_(cardNumber), expiryDate_(expiryDate) {}

//getters
std::string Card::getCardNumber() const {
    return cardNumber_;
}

std::string Card::getExpiryDate() const {
    return expiryDate_;
}
