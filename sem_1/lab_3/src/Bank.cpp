#include "Bank.h"

Bank::Bank(const string& bankName, const double initialBalance)
    : name_(bankName), balance_(initialBalance) {
    if (initialBalance < 0) {
        throw invalid_argument("Initial balance cannot be negative.");
    }
}

double Bank::getBalance() const {
    return balance_;
}

void Bank::addTransaction(const Transaction& transaction) {
    transactions_.push_back(transaction);
    if (transaction.getType() == "deposit") {
        balance_ += transaction.getAmount();
    } else if (transaction.getType() == "withdrawal") {
        if (balance_ < transaction.getAmount()) {
            throw runtime_error("Insufficient funds for withdrawal.");
        }
        balance_ -= transaction.getAmount();
    }
}

void Bank::displayTransactions() const {
    cout << "Transaction history for bank: " << name_ << '\n';
    for (const auto& transaction : transactions_) {
        cout << "Type: " << transaction.getType() << ", Amount: " << transaction.getAmount() << '\n';
    }
}

string Bank::getName() const {
    return name_;
}
