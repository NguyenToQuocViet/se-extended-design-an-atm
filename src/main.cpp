#include "bank/Account.hpp"
#include "bank/Card.hpp"
#include "bank/Customer.hpp"
#include "bank/Bank.hpp"
#include "atm/ATM.hpp"

int main() {
    //Seed accounts
    CheckingAccount acc1("ACC-001", Money::fromDollars(10000.00));
    SavingAccount   acc2("ACC-002", Money::fromDollars(500.00));
    CheckingAccount acc3("ACC-003", Money::fromDollars(5.00));

    //Seed cards
    Card card1("2610-2005", "10/29");
    Card card2("0401-2006", "01/29");
    Card card3("1703-2026", "03/29");

    //Seed customers
    Customer c1("Quoc Viet",        "261005",   card1, &acc1);
    Customer c2("Phuong Yen",       "200600",   card2, &acc2);
    Customer c3("Quoc Vu",          "1111",     card3, &acc3);

    //Register with bank
    Bank bank;
    bank.addCustomer(&c1);
    bank.addCustomer(&c2);
    bank.addCustomer(&c3);

    //Run ATM
    ATM atm(&bank);
    atm.run();

    return 0;
}
