#ifndef BANK_H
#define BANK_H
#include "libraries.h"
#include "Transaction.h"
class Bank {
public:
  Bank():totalRevenue_(20.0){};
  void processTransaction(Transaction* transaction);
  double getTotalRevenue() const;
  void showTransactions() const;
private:
    vector<Transaction*> transactions_;
    double totalRevenue_;
};



#endif //BANK_H
