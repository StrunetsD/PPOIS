#include "Transaction.h"


  void Transaction::process() const {
      cout << "Processing transaction: " << client_->getName()
                << " bought " << painting_->getTitle()
                << " for " << amount_ << " $." << "\n";
  }
  double Transaction::getAmount() const {
      return amount_;
  }