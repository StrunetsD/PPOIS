#ifndef TRANSACTION_H
#define TRANSACTION_H


#include "Client.h"
#include "Painting.h"


class Transaction {
public:
  Transaction(Client* client, Painting* painting, const double amount): client_(client), painting_(painting), amount_(amount) {};
  void process()const;
  double getAmount()const;
private:
  Client* client_;
  Painting* painting_;
  double amount_;
};




#endif //TRANSACTION_H
