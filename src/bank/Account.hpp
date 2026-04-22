#pragma once
#include <string>
#include "common/Money.hpp"

class Account {
protected:
    std::string accountNumber_;
    Money balance_;
public:
    //constructor
    Account(const std::string& accountNumber, Money initialBalance);
    //destructor
    virtual ~Account();
    
    //getters
    std::string getAccountNumber() const;
    Money getBalance() const;
    
    //pure virtual
    virtual void deposit(Money amount) = 0;
    virtual bool withdraw(Money amount) = 0;
};

class CheckingAccount : public Account {
public:
    //constructor
    CheckingAccount(const std::string& accountNumber, Money initialBalance);
    
    //overide
    void deposit(Money amount) override;
    bool withdraw(Money amount) override;
};

class SavingAccount : public Account {
public:
    //constructor
    SavingAccount(const std::string& accountNumber, Money initialBalance);
    
    //overide
    void deposit(Money amount) override;
    bool withdraw(Money amount) override;
};
