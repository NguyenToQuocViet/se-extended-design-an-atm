#include "bank/Account.hpp"

//Account
//constructor
Account::Account(const std::string& accountNumber, Money initialBalance): accountNumber_(accountNumber), balance_(initialBalance) {}

//destructor
Account::~Account() {}

//getters
std::string Account::getAccountNumber() const {
    return accountNumber_;
}

Money Account::getBalance() const {
    return balance_;
}

//CheckingAccount
//constructor
CheckingAccount::CheckingAccount(const std::string& accountNumber, Money initialBalance) : Account(accountNumber, initialBalance) {}

//deposit
void CheckingAccount::deposit(Money amount) {
    balance_ += amount;
}

//withdraw
bool CheckingAccount::withdraw(Money amount) {
    if (amount > balance_) return false;
    balance_ -= amount;
    return true;
}

//SavingAccount
//constructor
SavingAccount::SavingAccount(const std::string& accountNumber, Money initialBalance) : Account(accountNumber, initialBalance) {}

//deposit
void SavingAccount::deposit(Money amount) {
    balance_ += amount;
}

//withdraw
bool SavingAccount::withdraw(Money amount) {
    if (amount > balance_) return false;
    balance_ -= amount;
    return true;
}
