#include "Bank.h"

void Bank::processTransaction(Transaction* transaction) {
    transaction->process();
    transactions_.push_back(transaction);
    totalRevenue_ += transaction->getAmount();
}
double Bank::getTotalRevenue() const {
  return totalRevenue_;
}
void Bank::showTransactions() const{
    cout << "All Transactions:" << "\n";
    for (const Transaction*  transactions_: transactions_) {
        transactions_->process();
    }
}
