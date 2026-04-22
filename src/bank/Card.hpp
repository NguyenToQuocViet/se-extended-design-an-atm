#pragma once
#include <string>

class Card {
private:
    std::string cardNumber_;
    std::string expiryDate_;
public:
    //constructor
    Card(const std::string& cardNumber, const std::string& expiryDate);
    
    //getter
    std::string getCardNumber() const;
    std::string getExpiryDate() const;
};
