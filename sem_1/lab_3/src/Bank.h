#ifndef BANK_H
#define BANK_H

#include "libraries.h"
#include "Transaction.h"

using namespace std;

class Bank {
public:
    Bank(const string& bankName, const double initialBalance);

    double getBalance() const;
    void addTransaction(const Transaction& transaction);
    void displayTransactions() const;
    string getName() const;

private:
    string name_;
    double balance_;
    vector<Transaction> transactions_;
};

#endif // BANK_H
