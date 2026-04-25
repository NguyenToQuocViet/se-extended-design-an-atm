#pragma once
#include <vector>
#include "bank/Customer.hpp"

class Bank {
private:
    std::vector<Customer*> customers_;
public:
    void addCustomer(Customer* customer);
    Customer* authenticate(const std::string& cardNumber, const std::string& pin);
    Customer* findByCard(const std::string& cardNumber);
};
