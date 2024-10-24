#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "libraries.h"
class Transaction {
public:
    Transaction(const string& transactionType, const double transactionAmount)
        : type_(transactionType), amount_(transactionAmount) {

        if (transactionAmount <= 0) {
            throw invalid_argument("Transaction amount must be greater than zero.");
        }

        if (type_ != "deposit" && type_ != "withdrawal") {
            throw invalid_argument("Invalid transaction type. Must be 'deposit' or 'withdrawal'.");
        }
    }

    string getType() const { return type_; }
    double getAmount() const { return amount_; }
private:
    string type_;
    double amount_;

};

#endif // TRANSACTION_H
